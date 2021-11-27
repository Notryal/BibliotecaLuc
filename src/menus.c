#include "menus.h"
#include "input.h"
#include "LinkedList.h"

int Menu()
{
	int opciones;

	puts("\n\t>-MENU-<\n");
	puts("\t**************");
	puts("1 Leer un archivo con los datos de libros, guardandolos en un linkedList de entidades eLibro. ");
	puts("2 Leer un archivo con los datos de editoriales, guardandolos en un linkedList de entidades eEditorial. ");
	puts("3 Ordenar la lista generada en el item anterior, con la funcion ll_sort, segun el criterio de ordenamiento Autor de manera ascendente. ");
	puts("4 Imprimir por pantalla todos los datos de los libros. ");
	puts("5 Realizar un listado de los libros de la editorial MINOTAURO. ");
	puts("6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map. ");
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

