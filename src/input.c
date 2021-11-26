#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

//-----------------------------------CHAR-----------------------------------
int isChar(char string[])
{
	int rtn = 0;
	int i;
	int stringTam = strlen(string);

	for(i = 0; i<stringTam; i++)
	{
		if((string[i] != ' ') && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
		{
			rtn = -1;
			break;
		}
	}
	return rtn;
}

int getString(char input[], int tam)
{
    char auxString[tam];
    int rtn = -1;

    if (input != NULL && tam > 0)
    {
        fflush(stdin);
        fgets(auxString,tam,stdin);
        if (auxString[strlen(auxString)-1]=='\n')//le cambia el enter por el final
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= tam)
        {
            strncpy(input, auxString, tam);//copia cadena en la variable destino
            rtn=0;
        }
    }

    return rtn;
}

int SizeString(char string[])
{
	int rtn = -1;
	int i = 0;

	if(string != NULL)
	{

		strlwr(string);//convierte la cadena en minuscula
		string[0] = toupper(string[0]); //toupper convierte la primer letra en mayuscula
		while(string[i] != '\0')
		{
			if(string[i] == ' ')
			{
				string[i + 1] = toupper(string[i + 1]);
				rtn = 0;
			}
			i++;
		}
	}

	return rtn;
}
int utn_getString(char input[],int tam, int reintentos,char mensaje[], char mensajeError[])
{
	int rtn = -1;
    char auxString[tam];

    if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
    {
        do{
        	printf("%s", mensaje);
            if(!(getString(auxString,sizeof(auxString))) && !(isChar(auxString)))
            {
                strncpy(input,auxString,tam);
                rtn = 0;
                break;
            }
            else
            {
            	printf("%s", mensajeError);
            	reintentos--;
            }

        }while(reintentos>=0);
    }

    return rtn;
}

int getStringPath(char input[],int tam, int reintentos,char mensaje[], char mensajeError[])
{
	int isOk = 1;
	char auxString[tam];

	if(input != NULL && mensaje != NULL && mensajeError != NULL && tam > 0 && reintentos >= 0)
	{
		do{
			printf("%s", mensaje);
			if(!(getString(auxString,tam)))
			{
				strncpy(input,auxString,tam);
				strcat(input,".csv");
				isOk = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>=0);
	}

	return isOk;
}
//-----------------------------------INT-----------------------------------
int isInt(char input[])
{
    int rtn = 0;
    int i = 0;
    int stringTam = strlen(input); //devuelve la longitud de la cadena sin contar el nulo final \0

    for(i=0; i<stringTam ;i++)
    {
    	if(input[i]< '0' || input[i]> '9' )
        {
    		rtn=-1;
            break;
        }
    }

    return rtn;
}
int getInt(int* input)
{
    char auxString[400];
    int rtn = -1;

    if(!(getString(auxString,sizeof(auxString))) && !(isInt(auxString))) //podria usar sizeof(auxString) en vez del valor fijo 400
    {
    	*input=atoi(auxString); // RECIBE UNA CADENA Y DEVUELVE UN VALOR INT
    	rtn=0;
    }

    return rtn;
}
int utn_getInt(int* input,int min,int max,int reintentos, char mensaje[],char mensajeError[])
{
    int rtn=-1;
    int auxInt;

   if(mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0 && input != NULL)
   {
	   do
	   {
			reintentos--;
			printf("%s", mensaje);
			if(!(getInt(&auxInt)) && auxInt >= min && auxInt <= max)
			{
				*input= auxInt;
				rtn = 0;
				break;
			}
			else
			{
				printf("%s ",mensajeError);
			}
	   }
	   while(reintentos >= 0);
   }

    return rtn;
}
//-----------------------------------FLOAT-----------------------------------
int isFloat(char input[])
{
    int rtn = 0;
    int i;
    int stringTam = strlen(input);

    for(i=0; i<stringTam ;i++)
    {
        if((input[i]< '0' || input[i]> '9' ) && (input[i]!='.'))
        {
        	rtn = -1;
            break;
        }
    }

    return rtn;
}
int getFloat(float* input)
{
    char auxString[200];
    int rtn =-1;

    if(!(getString(auxString,200)) && !(isFloat(auxString)))
    {
        *input = atof(auxString); //CONVIERTE A FLOAT LA CADENA
        rtn = 0;
    }

    return rtn;
}
int utn_getFloat(float* input,float min, float max, int reintentos,char mensaje[], char mensajeError[])
{
    int rtn = -1;
    float auxFloat;

    if(input != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
    {
        do
        {
        	printf("%s", mensaje);
        	if(!(getFloat(&auxFloat)) && auxFloat >= min && auxFloat <= max)
        	{
        		*input= auxFloat;
        		rtn = 0;
        		break;
        	}
        	else
        	{
        		printf("%s ",mensajeError);
        		reintentos--;
        	}
        }
        while(reintentos >= 0);
    }

    return rtn;
}



//-----------------------------------CUIT-----------------------------------




int myGets(char cadena[],int tam,char mensaje[])
{
	int retorno;
    char auxiliar[tam];
    int largo;

    retorno = 0;

    if(cadena != NULL && tam > 0)
    {
    	printf("%s", mensaje);
		fflush(stdin);
		fgets(auxiliar,tam,stdin);
		largo = strlen(auxiliar);

		if(auxiliar[largo-1] == '\n')
		{
			auxiliar[largo-1] = '\0';
		}

		if(auxiliar[0] != '\0')
		{
			strcpy(cadena, auxiliar);
			retorno = 1;
		}

    }


    return retorno;
}

int isNumber(char cadena[])
{
	int retorno;
	int i;
	int largo;
	int validar;

	i = 0;
	retorno = 1;
	largo = strlen(cadena);

	if(cadena[0] == '-' || cadena[0] == '+')
	{
		i = 1;
	}

	if(cadena[i] == '\0')
	{
		retorno = 0;
	}

	for( ; i < largo ; i++)
	{
		validar = isdigit(cadena[i]);

		if(validar == 0)
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}



int isCuit(char cadena[])
{
	int retorno;
	int i;
	int largo;
	int validar;


	i = 0;
	retorno = 0;
	largo = 13;

	if(cadena != NULL && cadena[2] == '-' && cadena[11] == '-')
	{
		retorno = 1;
		for(i = 0; i < largo ; i++)
		{
			validar = isdigit(cadena[i]);

			if((i == 2 || i == 11) && cadena[i] == '-')
			{
				continue;
			}

			if(validar == 0)
			{
				retorno = 0;
				break;
			}

		}
	}

	return retorno;
}



int getCuit(char cadena[], int tam, char mensaje[])
{
	int retorno;
	char textoAuxiliar[256];
	int retornoAuxiliar;

	retorno = 0;

	if(cadena != NULL)
	{
		retornoAuxiliar = myGets(textoAuxiliar, sizeof(textoAuxiliar), mensaje);

		if(retornoAuxiliar == 1)
		{
			retornoAuxiliar = isCuit(textoAuxiliar);

			if(retornoAuxiliar == 1)
			{
				strncpy(cadena,textoAuxiliar,tam-1);
				retorno = 1;
			}

		}

	}
	return retorno;
}

int utn_GetCuit(char input[], int tam,int reintentos, char mensaje[], char mensajeError[])
{
	int retornoAuxiliar;
	int retorno;
	char auxiliar[256];

	retorno = -1;

	if(input != NULL && tam > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			retornoAuxiliar = getCuit(auxiliar, sizeof(auxiliar), mensaje);

			if(retornoAuxiliar == 1)
			{
				strncpy(input,auxiliar,tam-1);
				retorno = -1;
				if(strlen(auxiliar)<tam)
				{
					retorno = 0;
				}
				break;
			}

			printf("%s\n", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}

	return retorno;
}



