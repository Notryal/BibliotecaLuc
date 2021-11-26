#include "menus.h"
#include "input.h"
#include "LinkedList.h"

int Menu()
{
	int opciones;

	puts("\n\t>-MENU-<\n");
	puts("\t\t**************\n");
	puts("1 Leer un archivo con los datos de libros, guardandolos en un linkedList de entidades eLibro. \n");
	puts("2 Leer un archivo con los datos de editoriales, guardandolos en un linkedList de entidades eEditorial. \n");
	puts("3 Ordenar la lista generada en el �tem anterior, con la funcion ll_sort, seg�n el criterio de ordenamiento Autor de manera ascendente. \n");
	puts("4 Imprimir por pantalla todos los datos de los libros. \n");
	puts("5 Realizar un listado de los libros de la editorial MINOTAURO. \n");
	puts("6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map. \n");
	puts("7 Salir del programa. \n");
	utn_getInt(&opciones,0,7,3,"\n Ingrese una opcion: ","\n Error! Opcion invalida: ");

	return opciones;
}

int libroMenu()
{
	int opciones;

	puts("\n\t>-MENU-<\n");
	puts("\t\t**************\n");
	puts("1. Ordenar por Autor\n");
	puts("2. Mostrar lista ordenada\n");
	puts("0. Salir\n");

	utn_getInt(&opciones,0,2,3,"\nIngrese una opcion: ","\nError, opcion invalida: ");

	return opciones;
}

