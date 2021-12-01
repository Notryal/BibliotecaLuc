#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "parser.h"
#include "menus.h"


int controller_sortLibros(LinkedList* pArrayLibros);
int controller_ListLibros(LinkedList* pArrayLibros, LinkedList* pArrayEditoriales);

int controller_loadEditorialFromText(char* path , LinkedList* pArrayEditoriales);

int controller_loadFromText(char* path , LinkedList* pArrayLibros);



int Controller_FilterEditorial(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial);

int Controller_Mapeado(char* path , LinkedList* pArrayList, LinkedList* pArrayListEditorial);

int Controller_Contador(char* path ,LinkedList* pArrayList, LinkedList* pArrayListEditorial);
int Controller_Acumulador(char* path ,LinkedList* pArrayList, LinkedList* pArrayListEditorial);



#endif /* CONTROLLER_H_ */
