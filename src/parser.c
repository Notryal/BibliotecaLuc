#include "LinkedList.h"
#include "parser.h"
#include "Libros.h"

int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int isOk = -1;
	char id[128];
	char titulo[128];
	char autor[128];
	char precio[128];
	char editorial[128];
	int header = 1;
	int cantidad = 0;
	int idEditorial;
	eLibro* auxiliar = NULL;

	if(pFile!=NULL && pArrayListLibro!=NULL)
	{
		do
		{
			cantidad = fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,titulo,autor,precio,editorial);

			if((cantidad==5) && (header!=1))
			{
				BuscarIdEditorial(editorial,&idEditorial);
				itoa(idEditorial,editorial,128);
				auxiliar = libro_newParametros(id,titulo,autor,precio,editorial);
				if(auxiliar!=NULL)
				{
					ll_add(pArrayListLibro, auxiliar);
					isOk=0;
				}
				else
				{
					libro_delete(auxiliar);
				}
			}
			else
			{
				header=0;//evita el titulo
			}
		}
		while(!feof(pFile));
	}

    return isOk;
}
/*
int parser_SaveFilterListToText(FILE* pFile , LinkedList* pArrayListFilter)
{
	int isOk = -1;
	int i;
	int* auxId;
	char* auxTitulo[200];
	char* auxAutor[200];
	float* auxPrecio;
	int* auxIdEditorial;


	eLibro* libroAux;

	if(pFile != NULL && pArrayListFilter != NULL)
	{
		fprintf(pFile, "%s, %s, %s, %s, %s\n", "id", "titulo", "autor", "precio", "idEditorial");
		for(i=0;i<ll_len(pArrayListFilter);i++)
		{
			libroAux = (eLibro*)ll_get(pArrayListFilter, i);

			if((!(libro_getId(libroAux,auxId)) &&
				!(libro_getTitulo(libroAux,auxTitulo)) &&
				!(libro_getAutor(libroAux,auxAutor)) &&
				!(libro_getPrecio(libroAux,auxPrecio)) &&
				!(libro_getEditorialId(libroAux,auxIdEditorial))))
			{
				fprintf(pFile, "%d, %s, %s, %2.f, %d\n", auxId, auxTitulo, auxAutor, auxPrecio, auxIdEditorial);
				isOk = 0;
			}
		}
	}
	return isOk;
}

*/






