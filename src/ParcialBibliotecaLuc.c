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
//LinkedList* listaFiltro = ll_newLinkedList();
int flagLibrosCargados = 0;
int flagEditorialesCargados = 0;

int opciones;
char path[200];

ll_clear(listaLibros);
ll_clear(listaEditoriales);
//ll_clear(listaFiltro);

	do
	{
		opciones = Menu();

		switch(opciones)
		{
		case 1:
			if(flagLibrosCargados == 0 || ll_isEmpty(listaLibros))
			{
				getStringPath(path,200,3,"Ingrese el nombre del archivo a cargar: (libros) \n","Error, intente nuevamente");

				if(!controller_loadFromText(path,listaLibros))
				{
					puts("Se cargo el archivo libros.csv");
					flagLibrosCargados=1;
				}
				else
				{
					puts("No se encontro el nombre del archivo! libros \n");
				}
			}else{
				puts("Ya cargo un archivo de libros");
			}
		break;
		case 2:
			if(flagEditorialesCargados == 0 || ll_isEmpty(listaLibros))
			{
				getStringPath(path,200,3,"Ingrese el nombre del archivo a cargar: (editoriales) \n","Error, intente nuevamente");

				if(!controller_loadEditorialFromText(path, listaEditoriales))
				{
					puts("Se cargo el archivo editoriales.csv");
					flagEditorialesCargados=1;
				}
				else
				{
					puts("No se encontro el nombre del archivo! libros \n");
				}
			}else{
				puts("Ya cargo un archivo de editoriales");
			}
		break;
		case 3:
			if(!ll_isEmpty(listaLibros))
			{
				controller_ListLibros(listaLibros,listaEditoriales);

				puts("\n*********************************************************************");
				puts("*********************************************************************\n");

				controller_sortLibros(listaLibros);
				controller_ListLibros(listaLibros,listaEditoriales);

			}
			else
			{
				puts("\n Tiene que cargar la lista de libros e editoriales para poder ordenar algo\n");
			}

		break;
		case 4:
			if(!ll_isEmpty(listaLibros))
			{
				controller_ListLibros(listaLibros,listaEditoriales);
			}
			else
			{
				puts("\n Tiene que cargar los libros y las editoriales primero\n");
			}
		break;
		case 5:
			if(!ll_isEmpty(listaLibros))
			{
				if(!Controller_FilterEditorial("librosFiltrados.csv", listaLibros, listaEditoriales))
				{
					puts("Se cargo con exito");
				}
				else
				{
					puts("\n Tiene que cargar los libros y las editoriales primero\n");
				}
			}
		break;
		case 6:
			if(!ll_isEmpty(listaLibros))
			{
				if(Controller_Mapeado("mapeado.csv", listaLibros, listaLibros) == 1)
				{
						printf("ERROR");
				}
				else
				{
						printf("FUNCIONO");
				}
			}
		break;
		case 7:
			puts("hasta luego");
		break;
		default:
			puts("Error");
		break;
		}

	}while(opciones != 7);

    ll_deleteLinkedList(listaLibros);
    ll_deleteLinkedList(listaEditoriales);

	return EXIT_SUCCESS;
}













