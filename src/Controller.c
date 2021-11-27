#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Controller.h"
#include "parser.h"
#include "menus.h"

int controller_saveAsText(char* path , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	int i;
	int len;
	int auxiliarID;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarEditorialId;
	char auxiliarEditorialNombre[128];
	FILE* pArchivo;
	eLibro* aux = NULL;

	if(path!=NULL && pArrayListLibro!=NULL)
	{
		pArchivo = fopen(path,"w");

		len = ll_len(pArrayListLibro);

		if(pArchivo!= NULL && len>0)
		{
			fprintf(pArchivo,"id,titulo,autor,precio,editorialId\n");

			for(i=0; i<len ;i++)
			{
				aux = (eLibro*) ll_get(pArrayListLibro,i);

				if(aux!=NULL)
				{
					if(!libro_getVerify(aux,&auxiliarID,auxiliarTitulo,auxiliarAutor,&auxiliarPrecio,&auxiliarEditorialId))
					{
						fprintf(pArchivo,"%d,%s,%s,%2.f,%s\n",auxiliarID,auxiliarTitulo,auxiliarAutor,auxiliarPrecio,auxiliarEditorialNombre);
						isOk=0;
					}
					else
					{
						libro_delete(aux);
						printf("No se pudo guardar el archivo\n");
					}
				}
			}
		}
		else
		{
			printf("Error al abrir el archivo\n");
		}
		fclose(pArchivo);
	}

	if(!isOk)
	{
		printf("El archivo fue guardado con exito!\n");
	}
	return isOk;
}


int controller_loadFromText(char* path , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayListLibro!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_libroFromText(pArchivo, pArrayListLibro))
			{
				puts("Se cargo con exito\n");
				isOk=0;
			}
		}
		else
		{
			puts("Error al abrir el archivo\n");
		}

		fclose(pArchivo);
	}

    return isOk;
}

int controller_sortLibro(LinkedList* pArrayListLibro)
{
	int isOk = -1;
	char confirmar[4];
	strcpy(confirmar,"no");
	LinkedList* clon = NULL;
	int opcion;
	opcion = libroMenu();

	if(pArrayListLibro!=NULL)
	{
		clon = ll_clone(pArrayListLibro);

		if(clon!=NULL)
		{
			do
			{
				switch(opcion)
				{
					case 0:
						utn_getString(confirmar,4,3,"\n¿Esta seguro que desea salir?[si/no]\n","\nRespuesta invalida, si o no\n");

						if(stricmp(confirmar,"no"))
						{
							ll_deleteLinkedList(clon);
						}
						break;
					case 1:
						if(!ll_sort(clon,libro_compareByAutor,1))
						{
							printf("Se ha ordenado la lista por autor de manera ascendente");
						}
						else
						{
							printf("No pudo ordenarse la lista");
						}
						break;
					case 2:
						controller_listLibro(clon);
						break;
				}
			}while(stricmp(confirmar,"si"));
		}
	}

	return isOk;
}



int controller_listLibro(LinkedList* pArrayListLibro)
{
	int isOk = -1;

	if(pArrayListLibro!=NULL)
	{
		printf("LISTA DE EMPLEADOS\n");
		if(libro_printList(pArrayListLibro)!=0)
		{
			printf("No hay libros para mostrar");
			isOk=0;
		}
	}

    return isOk;
}

int controller_mapDescuentos(LinkedList* pArrayListLibro){

	int isOk = -1;

	if(pArrayListLibro!=NULL)
	{
		pArrayListLibro=ll_map(pArrayListLibro,libro_descuentos); //librodescuentos va a ser mi funcion
		printf("Se ha aplicado el descuento con exito");
		isOk=0;
	}
	return isOk;
}



int controller_filterEditorial(char* path, LinkedList* pArrayListLibros,LinkedList* pArrayListEditoriales)
{
	int isOk;
	LinkedList* listaMinotauro = NULL;
	isOk = 1;

	if(pArrayListLibros != NULL)
	{
		listaMinotauro = ll_filter(pArrayListLibros, libro_FiltrarMinotauro);

		if(listaMinotauro != NULL)
		{
			isOk = 0;
			controller_listLibro(listaMinotauro);
		}
	}
	return isOk;
}






