/*
 * Controller.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListLibro);
int controller_listLibro(LinkedList* pArrayListLibro);
int controller_sortLibro(LinkedList* pArrayListLibro);
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);
int controller_filterEditorial(char* path, LinkedList* pArrayListLibros,LinkedList* pArrayListEditoriales);

#endif /* CONTROLLER_H_ */
