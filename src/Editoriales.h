#ifndef EDITORIALES_H_
#define EDITORIALES_H_

#include "LinkedList.h"

typedef struct
{
	int idEditorial;
	char nombre[200];
}eEditorial;

eEditorial* editorial_new();

eEditorial* eEditorial_newParametros(char* idStr, char* nombreStr);
void eEditorial_delete(eEditorial* auxEditorial);

//
int eEditorial_setId(eEditorial* this, int id);
int eEditorial_setName(eEditorial* this, char* nombre);
//
int eEditorial_getId(eEditorial* this, int* id);
int eEditorial_getName(eEditorial* this, char* nombre);



#endif /* EDITORIALES_H_ */
