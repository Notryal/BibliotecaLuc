#include "Libros.h"
#include "Editoriales.h"

eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
	eLibro* pLibroParam = NULL;

	if(idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		pLibroParam = libro_new();

		if(pLibroParam!=NULL)
		{
			if((libro_setVerifyChar(pLibroParam,idStr,tituloStr,autorStr,precioStr,editorialIdStr))!=0)
			{
				libro_delete(pLibroParam);
			}
		}
	}

	return pLibroParam;
}

eLibro* libro_new(void)
{
	eLibro* pLibro = NULL;

	int id;
	char titulo[128];
	char autor[128];
	float precio;
	int editorialId;

	id=1;
	precio=1;
	editorialId=1;

	pLibro = (eLibro*) malloc(sizeof(eLibro));

	strcpy(titulo," ");
	strcpy(autor," ");

	if(pLibro!=NULL)
	{
		libro_setVerifyInt(pLibro,id,titulo,autor,precio,editorialId);
	}

	return pLibro;
}



void libro_delete(eLibro* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int libro_CompararAutor(void* autorUno, void* autorDos)
{
	int comp;

	eLibro* lib1;
	eLibro* lib2;

	lib1 =(eLibro*) autorUno;
	lib2 =(eLibro*) autorDos;

	comp = strcmp(lib1->autor,lib2->autor);

	return comp;
}



//---------------------------------------------SETTERS---------------------------------------------
int libro_setId(eLibro* this, int id)
{
	int isOk = -1;

	if(this!=NULL && id>0)
	{
		this->id = id;
		isOk=0;
	}

	return isOk;
}

int libro_setTitulo(eLibro* this, char* titulo)
{
	int isOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
		isOk=0;
	}

	return isOk;
}

int libro_setAutor(eLibro* this, char* autor)
{
	int isOk = -1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor,autor);
		isOk=0;
	}

	return isOk;
}

int libro_setPrecio(eLibro* this, float precio)
{
	int isOk = -1;

	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		isOk=0;
	}

	return isOk;
}

int libro_setEditorialId(eLibro* this, int editorialId)
{
	int isOk = -1;

	if(this!=NULL && editorialId>0)
	{
		this->editorialId = editorialId;
		isOk=0;
	}

	return isOk;
}

//---------------------------------------------GETTERS---------------------------------------------
int libro_getId(eLibro* this, int* id)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		isOk=0;
	}

	return isOk;
}
int libro_getTitulo(eLibro* this, char* titulo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strncpy(titulo, this->titulo, 128);
		retorno = 0;
	}

	return retorno;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int retorno;

	retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strncpy(autor, this->autor, 128);
		retorno = 0;
	}

	return retorno;
}

int libro_getPrecio(eLibro* this, float* precio)
{
	int isOk = -1;

	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		isOk=0;
	}

	return isOk;
}

int libro_getEditorialId(eLibro* this, int* editorialId)
{
	int isOk = -1;

	if(this!=NULL && editorialId!=NULL)
	{
		*editorialId = this->editorialId;
		isOk=0;
	}

	return isOk;
}

//-----------------------------------------------------------

int libro_setVerifyChar(eLibro* this, char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* editorialIdStr)
{
	int isOk = -1;

	if(this!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && editorialIdStr!=NULL)
	{
		if((!(libro_setId(this,atoi(idStr))) &&
			!(libro_setTitulo(this,tituloStr)) &&
			!(libro_setAutor(this,autorStr)) &&
			!(libro_setPrecio(this,atof(precioStr))) &&
			!(libro_setEditorialId(this,atoi(editorialIdStr)))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int libro_setVerifyInt(eLibro* this, int id, char* titulo, char* autor, float precio, int editorialId)
{
	int isOk = -1;

	if(this!=NULL && id>0 && titulo!=NULL && autor!=NULL && precio>0 && editorialId>0)
	{
		if((!(libro_setId(this,id)) &&
			!(libro_setTitulo(this,titulo)) &&
			!(libro_setAutor(this,autor)) &&
			!(libro_setPrecio(this,precio)) &&
			!(libro_setEditorialId(this,editorialId))))
		{
			isOk=0;
		}
	}

	return isOk;
}

int libro_getVerify(eLibro* this, int* id, char* titulo, char* autor, float* precio, int* editorialId)
{
	int isOk = -1;

	if(this!=NULL && id!=NULL && titulo!=NULL && autor!=NULL && precio!=NULL && editorialId!=NULL)
	{
		if((!(libro_getId(this,id)) &&
			!(libro_getTitulo(this,titulo)) &&
			!(libro_getAutor(this,autor)) &&
			!(libro_getPrecio(this,precio)) &&
			!(libro_getEditorialId(this,editorialId))))
		{
			isOk=0;
		}
	}

	return isOk;
}
//-----------------------------------------------------------






void libro_printOneLibro(eLibro* pLibro,LinkedList* pEditorialesId)
{
	int auxiliarID;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarEditorialIdLibros;
	int auxiliarEditorialIdEditoriales;
	char auxNombreEditorial[128];

	eEditorial* editorialAux;

	//puts("rompe antes del for");

	for(int i=0;i<ll_len(pEditorialesId);i++)
	{
		editorialAux = (eEditorial*)ll_get(pEditorialesId, i);

		if(!libro_getVerify(pLibro,&auxiliarID,auxiliarTitulo,auxiliarAutor,&auxiliarPrecio,&auxiliarEditorialIdLibros)
		 && !eEditorial_getId(editorialAux,&auxiliarEditorialIdEditoriales))
		{
			//puts("rompe en el primer if");

			if(auxiliarEditorialIdEditoriales ==auxiliarEditorialIdLibros &&
			!eEditorial_getName(editorialAux, auxNombreEditorial))
			{
				//puts("rompe en el segundo if");
				printf("| %2d |%-16s|%-16s|$%-7.2f|%2d|%-18s|\n",auxiliarID
																 	 	 	 	 	  ,auxiliarTitulo
																					  ,auxiliarAutor
																					  ,auxiliarPrecio
																					  ,auxiliarEditorialIdLibros
																					  ,auxNombreEditorial);
			}
		}
	}
}

void* libros_Mapeado(void* unLibro)
{
	eLibro* auxiliarLibro;
	eLibro* retorno;
	int idEditorial;
	float precioLibro;
	float precioConDescuento;
	float descuento;

	retorno = NULL;

	if(unLibro != NULL)
	{
		auxiliarLibro = (eLibro*)unLibro;

		if(!libro_getEditorialId(auxiliarLibro, &idEditorial))
		{
			if(idEditorial == 1 && !libro_getPrecio(auxiliarLibro, &precioLibro))
			{
				if(precioLibro >= 300)
				{
					descuento = (precioLibro * 20) / 100;
					precioConDescuento = precioLibro - descuento;

					if(!libro_setPrecio(auxiliarLibro, precioConDescuento))
					{
						retorno = auxiliarLibro;
					}
				}
			}
			else
			{
				if(idEditorial == 2 && !libro_getPrecio(auxiliarLibro, &precioLibro))
				{
					if(precioLibro <= 200)
					{
						descuento = (precioLibro * 10) / 100;
						precioConDescuento = precioLibro - descuento;

						if(libro_setPrecio(auxiliarLibro, precioConDescuento))
						{
							retorno = auxiliarLibro;
						}
					}
				}
			}
		}
	}

	return retorno;
}


