#include "LinkedList.h"
#include "Controller.h"
#include "menus.h"

/*

1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
 *
 *
 */


int main(void) {

setbuf(stdout,NULL);

LinkedList* listaLibros = ll_newLinkedList();
LinkedList* listaEditoriales = ll_newLinkedList();
int flagLibrosCargados = 0;
//int flagEditorialesCargados = 0;

int opciones;
char path[200];

	do
	{
		opciones = Menu();

		switch(opciones)
		{
		case 1:
			if(flagLibrosCargados == 0 || ll_isEmpty(listaLibros))
			{
				getStringPath(path,200,3,"\nIngrese el nombre del archivo a cargar: ","Error, intente nuevamente");

				if(controller_loadFromText(path,listaLibros)==1)
				{
					flagLibrosCargados = 1;
				}
				else
				{
					puts("\nNo se encontro el nombre del archivo datalibros \n");
				}
			}else{

				puts("Ya cargo un archivo");

			}
		break;
		case 2:
			if(!ll_isEmpty(listaLibros))
			{
				getStringPath(path,200,3,"\nIngrese el nombre del archivo a cargar: ","Error, intente nuevamente");

				if(!controller_loadFromText(path,listaEditoriales))
				{
					puts("Se cargo con exito\n");
				}
				else
				{
					puts("\nNo se encontro el nombre del archivo datalibros \n");
				}
			}else{

				puts("Ya cargo un archivo");

			}
			break;
		break;
		case 3:

			//if(flagLibrosCargados == 1 && flagEditorialesCargados == 1)
			if(!ll_isEmpty(listaLibros))
			{
				controller_sortLibro(listaLibros);
			}
			else
			{
				puts("\n Tiene que cargar la lista de libros e editoriales para poder ordenar algo\n");
			}
		break;

		case 4:

			//if(flagLibrosCargados == 1 && flagEditorialesCargados == 1)
			if(!ll_isEmpty(listaLibros))
			{
				controller_listLibro(listaLibros);
			}
			else
			{
				puts("\n Tiene que cargar la lista de libros e editoriales para poder imprimir algo\n");
			}
		break;

		case 5:

			//if(flagLibrosCargados == 1 && flagEditorialesCargados == 1)
			if(!ll_isEmpty(listaLibros))
			{
				controller_filterEditorial("ListaFiltradaMinotauro.csv", listaLibros,listaEditoriales);

			}
			else
			{
				puts("\n Tiene que cargar la lista de libros e editoriales para poder imprimir algo\n");
			}
		break;

		case 6:
			//if(flagLibrosCargados == 1 && flagEditorialesCargados == 1)
			if(!ll_isEmpty(listaLibros))
			{
			controller_saveAsText("mapeado.csv",listaLibros);
			}
			else
			{
			puts("No hay nada para guardar");
			}
		break;
		case 7:
			puts("Salgo del programa");
		break;
		default:
			puts("Error, salgo del programa");
		break;
		}

	}while(opciones != 7);

	return EXIT_SUCCESS;
}













