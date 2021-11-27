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

	id=0;
	precio=0;
	editorialId=0;

	pLibro = (eLibro*) malloc(sizeof(eLibro));

	strcpy(titulo,"\0");
	strcpy(autor,"\0");

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
//editorial no harcodeo
int BuscarIdEditorial(char* nombre, int* id)
{
	int isOk = -1;
	int idAux[6]={1,2,3,4,5,6};
	char nombreAux[6][25]={"PLANETA","SIGLO XXI EDITORES","PEARSON","MINOTAURO","SALAMANDRA","PENGUIN BOOKS"};

	if(nombre!=NULL && id!=NULL)
	{
		for(int i=0;i<6;i++)
		{
			if(!stricmp(nombreAux[i],nombre))
			{
				*id=idAux[i];
				isOk=0;
			}
		}
	}

	return isOk;
}

int BuscarEditorialId(LinkedList* Editoriales,int id)
{
		int index;
		int i;
		int len;
		int auxIdEdit;
		eEditorial* auxEditorial;

		index= -1;

		if(Editoriales != NULL && ll_len(Editoriales)>0)
		{
			for(i=0 ; i<ll_len(Editoriales) ; i++)
			{
				auxEditorial= (eEditorial*)ll_get(Editoriales, i);

				if(auxEditorial != NULL && auxIdEdit != NULL && auxIdEdit>0)
				{
					auxIdEdit= auxEditorial->idEditorial;
				}

				if(auxEditorial!= NULL && auxIdEdit==id)
				{
					index = i;
					break;
				}
			}
		}

	return index;
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
	int isOk = -1;

	if(this!=NULL && titulo!=NULL)
	{
		strcpy(titulo,this->titulo);
		isOk=0;
	}

	return isOk;
}

int libro_getAutor(eLibro* this, char* autor)
{
	int isOk = -1;

	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor,this->autor);
		isOk=0;
	}

	return isOk;
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


int libro_printOneLibro(eLibro* this)
{
	int isOk = -1;
	int auxiliarID;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarEditorialId;
	char editorial[128];

	if(this!=NULL)
	{
		if(!libro_getVerify(this,&auxiliarID,auxiliarTitulo,auxiliarAutor,&auxiliarPrecio,&auxiliarEditorialId))
		{


			BuscarNombreEditorial(auxiliarEditorialId,editorial);







			printf("| %2d |%-50s|%-16s|$%-7.2f|%2d|%-18s|\n",auxiliarID
												 	 	 	 	 	  ,auxiliarTitulo
																	  ,auxiliarAutor
																	  ,auxiliarPrecio
																	  ,auxiliarEditorialId
																	  ,editorial);
			isOk=0;
		}
		else
		{
			puts("Error para mostrar el libro");
		}
	}

	return isOk;
}

int libro_printList(LinkedList* listaLibros)
{
	int isOk = -1;
	int len;
	int i;
	eLibro* aux = NULL;

	if(listaLibros!=NULL)
	{
		len = ll_len(listaLibros);

		if(len>0)
		{

			puts("|ID\t|\tTITULO\t|\t\tAUTOR\t|\tPRECIO |\t\t ID.EDITORIAL \t|\tNOMBRE EDITORIAL \n");

			for(i=0; i<len ;i++)
			{
				aux = (eLibro*) ll_get(listaLibros,i);

				if(aux != NULL)
				{
					libro_printOneLibro(aux);
					isOk=0;
				}
			}

		}
	}

	return isOk;
}


int libro_FiltrarMinotauro(void* libro){
	int isOk = -1;
	int auxIdEditorial;
	eLibro* unLibro;

	if(libro != NULL)
	{
		unLibro = (eLibro*)libro;

		if(libro_getEditorialId(unLibro, &auxIdEditorial) == 1)
		{
			if(auxIdEditorial == 4)
			{
				isOk = 1;
			}
		}
	}
	return isOk;
}

int libro_compareByAutor(void* libro1, void* libro2)
{
	int isOk = -1;
	eLibro* lib1 = NULL;
	eLibro* lib2 = NULL;
	char nombre1[128];
	char nombre2[128];

	if(libro1!=NULL && libro2!=NULL)
	{
		lib1 = (eLibro*) libro1;
		lib2 = (eLibro*) libro2;

		if((!libro_getAutor(lib1,nombre1)) && (!libro_getAutor(lib2,nombre2)))
		{
			isOk = strcmp(nombre1,nombre2);
		}
	}

	return isOk;
}

void* libro_descuentos(void* libros)
{
	eLibro* pElement = NULL;
	int auxId;
	float auxPrecio;
	float newPrecio=0;
	char auxNombre[128];

	if(libros!=NULL)
	{
		pElement= (eLibro*) libros;
		if(!libro_getEditorialId(pElement,&auxId))
		{
			BuscarNombreEditorial(auxId,auxNombre);

			if(stricmp(auxNombre,"Planeta")==0)
			{
				libro_getPrecio(pElement,&auxPrecio);
				if(auxPrecio>=300)
				{
					newPrecio=auxPrecio-(auxPrecio*20/100);
					libro_setPrecio(pElement,newPrecio);
				}
			}
			else
			{
				if(stricmp(auxNombre,"SIGLO XXI EDITORES")==0)
				{
					libro_getPrecio(pElement,&auxPrecio);
					if(auxPrecio<=200)
					{
						newPrecio=auxPrecio-(auxPrecio*10/100);
						libro_setPrecio(pElement,newPrecio);
					}
				}
			}
		}
	}

	return pElement;
}



