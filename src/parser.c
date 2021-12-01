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
	char idEditorial[128];

	eLibro* auxiliar = NULL;

	auxiliar = libro_new();

	if(pFile!=NULL && pArrayListLibro!=NULL)
	{

		fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,titulo,autor,precio,idEditorial);

		do
		{
			if(fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^,] , %[^\n]\n",id,titulo,autor,precio,idEditorial)==5)
			{
				auxiliar = libro_newParametros(id,titulo,autor,precio,idEditorial);

				//printf("%s , %s, %s, %s, %s\n",id,titulo,autor,precio,idEditorial);

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

		}while(!feof(pFile));
	}

    return isOk;
}


int parser_EditorialesFromText(FILE* pFile , LinkedList* pArrayListEditorial){

	int isOk = -1;
	eEditorial* pEditorial;

	char id[200];
	char nombre[200];

		if(pFile != NULL && pArrayListEditorial != NULL)
		{
			fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
			do
			{
				if(fscanf(pFile, "%[^,],%[^\n]\n", id, nombre) == 2)
				{
					pEditorial = eEditorial_newParametros(id, nombre);

					if(pEditorial != NULL)
					{
						ll_add(pArrayListEditorial, pEditorial);
						isOk = 0;
					}
				}
			}while(!feof(pFile));
		}
    return isOk;

}





int parser_SaveFilterListToText(FILE* pFile , LinkedList* pArrayListFilter)
{
	int isOk = -1;
	int i;
	int auxId;
	char auxTitulo[200];
	char auxAutor[200];
	float auxPrecio;
	int auxIdEditorial;


	eLibro* libroAux;

	if(pFile != NULL && pArrayListFilter != NULL)
	{
		fprintf(pFile, "%s, %s, %s, %s, %s\n", "id", "titulo", "autor", "precio", "idEditorial");
		for(i=0;i<ll_len(pArrayListFilter);i++)
		{
			libroAux = (eLibro*)ll_get(pArrayListFilter, i);

			if((!(libro_getId(libroAux,&auxId)) &&
				!(libro_getTitulo(libroAux,auxTitulo)) &&
				!(libro_getAutor(libroAux,auxAutor)) &&
				!(libro_getPrecio(libroAux,&auxPrecio)) &&
				!(libro_getEditorialId(libroAux,&auxIdEditorial))))
			{
				fprintf(pFile, "%d, %s, %s, %2.f, %d\n", auxId, auxTitulo, auxAutor, auxPrecio, auxIdEditorial);
				isOk = 0;
			}
		}
	}
	return isOk;
}


int Parser_SaveAsText(FILE* pFile , LinkedList* pArrayList)
{
	eLibro* unLibro;
	int auxiliarId;
	char auxiliarTitulo[128];
	char auxiliarAutor[128];
	float auxiliarPrecio;
	int auxiliarIdEditorial;
	int retorno;
	int len;
	int i;

	retorno = 1;

	if(pFile != NULL && pArrayList != NULL)
	{
		len = ll_len(pArrayList);

		for(i = 0; i < len; i++)
		{
			unLibro = (eLibro*)ll_get(pArrayList, i);

			if(!libro_getId(unLibro, &auxiliarId) && !libro_getTitulo(unLibro, auxiliarTitulo) &&
			!libro_getAutor(unLibro, auxiliarAutor) && !libro_getPrecio(unLibro, &auxiliarPrecio) &&
			!libro_getEditorialId(unLibro, &auxiliarIdEditorial))
			{
				fprintf(pFile, "\n%d, %s, %s, %.2f, %d", auxiliarId, auxiliarTitulo, auxiliarAutor, auxiliarPrecio, auxiliarIdEditorial);

				retorno = 0;
			}
		}
	}
	return retorno;
}







