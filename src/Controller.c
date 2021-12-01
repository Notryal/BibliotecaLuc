#include "Controller.h"

int Controller_FilterEditorial(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial)
{
	int retorno;
	FILE* miArchivo;
	LinkedList* nuevaLista;

	retorno = 1;

	if(path != NULL && pArrayList != NULL)
	{
		miArchivo = fopen(path, "w");
		nuevaLista = ll_filter(pArrayList, librosFiltrarMinotauro);
		if(miArchivo != NULL && nuevaLista != NULL)
		{
			if(Parser_SaveAsText(miArchivo, nuevaLista) == 0)
			{
				controller_ListLibros(nuevaLista, pArrayListEditorial);
				retorno = 0;
			}
			else
			{
				printf("\nError parser");
			}
			fclose(miArchivo);
		}
	}

	return retorno;
}


int librosFiltrarMinotauro(void* unLibro)
{
	int retorno;
	eLibro* auxiliarLibro;
	int idEditorial;

	retorno = 0;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!libro_getEditorialId(auxiliarLibro, &idEditorial))
		{
			if(idEditorial == 4)
			{
				retorno = 1;
			}
		}
	}

	return retorno;
}





int controller_loadFromText(char* path , LinkedList* pArrayLibros)
{
	int isOk = -1;
	FILE* pArchivo;

	if(path!=NULL && pArrayLibros!=NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo!= NULL)
		{
			if(!parser_libroFromText(pArchivo, pArrayLibros))
			{
				isOk=0;
			}
		}
		fclose(pArchivo);
	}

    return isOk;
}

int controller_loadEditorialFromText(char* path , LinkedList* pArrayEditoriales){

	int isOk = -1;

	FILE* pFile = fopen(path, "r");

	if(pFile != NULL && pArrayEditoriales != NULL)
	{
		if(!parser_EditorialesFromText(pFile, pArrayEditoriales))
		{
			isOk = 0;
		}
	}
	fclose(pFile);
    return isOk;
}

int controller_ListLibros(LinkedList* pArrayLibros, LinkedList* pArrayEditoriales)
{
int isOk = -1;
int len;
int i;
eLibro* aux = NULL;

	if(pArrayLibros!=NULL)
	{
		len = ll_len(pArrayLibros);

		if(len>0)
		{

			//ll_sort(pArrayLibros,Libros_CompareById,1);

			puts("|ID\t|\tTITULO|\tAUTOR\t|\tPRECIO|\tID.EDITORIAL|NOMBRE EDITORIAL \n");

			for(i=0; i<len ;i++)
			{
				aux = (eLibro*) ll_get(pArrayLibros,i);

				if(aux != NULL)
				{
					libro_printOneLibro(aux,pArrayEditoriales);
					isOk=0;
				}
			}
		}
	}else{
		printf("No hay libros para mostrar");
	}

return isOk;
}

int controller_sortLibros(LinkedList* pArrayLibros)
{
	int isOk = -1;

		if(pArrayLibros != NULL)
		{
			ll_sort(pArrayLibros, libro_CompararAutor, 1);

				isOk = 0;

		}
		return isOk;
}

int Controller_Mapeado(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial)
{
	int isOk;
	FILE* miArchivo;
	LinkedList* nuevaLista;

	isOk = -1;

	if(path != NULL && pArrayList != NULL)
	{
		miArchivo = fopen(path, "w");
		nuevaLista = ll_map(pArrayList, libros_Mapeado);

		if(miArchivo != NULL && nuevaLista != NULL)
		{
			if(!Parser_SaveAsText(miArchivo, nuevaLista))
			{
				controller_ListLibros(nuevaLista, pArrayListEditorial);
				isOk = 0;
			}
			else
			{
				printf("\nError parser");
			}
			fclose(miArchivo);
		}
	}

	return isOk;
}


//******************************************************




