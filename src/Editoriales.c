/*
 * Editoriales.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Usuario
 */

#include "Editoriales.h"

eEditorial* editorial_new()
{
	eEditorial* pNewEditorial = NULL;

	pNewEditorial = (eEditorial*) malloc(sizeof(eEditorial));

	if(pNewEditorial != NULL)
	{
		pNewEditorial->idEditorial = 0;
		strcpy(pNewEditorial->nombre,"0");
	}

	return pNewEditorial;
}

eEditorial* eEditorial_newParametros(char* idStr, char* nombreStr)
{
	eEditorial* editorialAux;

	if(idStr != NULL && nombreStr != NULL)
	{
		editorialAux = editorial_new();

		if(eEditorial_setId(editorialAux, atoi(idStr)) == -1 ||
		   eEditorial_setName(editorialAux, nombreStr) == -1)
		{
			printf("Error al cargar las editoriales \n");
			eEditorial_delete(editorialAux);
		}
	}
	return editorialAux;
}

void eEditorial_delete(eEditorial* this)
{

	if(this!=NULL){

		free(this);

	}

}

int eEditorial_setId(eEditorial* this, int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->idEditorial = id;
		retorno = 0;
	}
	return retorno;
}

int eEditorial_getId(eEditorial* this, int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

int eEditorial_setName(eEditorial* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}


int eEditorial_getName(eEditorial* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}













