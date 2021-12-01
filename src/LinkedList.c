#include "LinkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;//la inicio en cero
    	this->pFirstNode = NULL;// final de la lista NULL
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    	//devuelvo el tamaño
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;
	int i;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode = this->pFirstNode;//le asigno el primer nodo para recorrer en busca del que pide

		for(i=0; i<nodeIndex ;i++)//recorro hasta la cantidad que ingreso
		{
			auxNode = auxNode->pNextNode;//va igualando hasta llegar al ultimo
		}
	}

    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodeNew = NULL;
    Node* pNodePrev = NULL;

    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
    {
		pNodeNew = (Node*) malloc(sizeof(Node));

		if(pNodeNew != NULL)
		{
			pNodeNew->pElement = pElement;
			pNodeNew->pNextNode = NULL;

			if(nodeIndex == 0)//si es mi primer elemento en la lista
			{
				pNodeNew->pNextNode = this->pFirstNode;
				this->pFirstNode = pNodeNew;
			}
			else //si es ultimo o en el medio
			{
				pNodePrev = getNode(this,nodeIndex-1);

				if(pNodePrev != NULL)
				{
					pNodeNew->pNextNode = pNodePrev->pNextNode;
					pNodePrev->pNextNode = pNodeNew;
				}
			}
			this->size++;
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this !=NULL){
    	returnAux = addNode(this,ll_len(this),pElement);
    	//ll_len me va a dar el tamano de la lista para saber que posicion
    }


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index) //paso posicion
{
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
		pNode = getNode(this, index);

		if(pNode != NULL)
		{
	    	returnAux = pNode->pElement;
		}

    }

    return returnAux; //devuelvo elemento
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) //seteo valores
{
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this,index);

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* pNodeAux = NULL;
    Node* pNodePrev = NULL;


    if(this != NULL && index > -1)
    {
    	len = ll_len(this);

    	if(index < len)
    	{
    		pNodeAux = getNode(this,index);
    		if(pNodeAux != NULL)
    		{
    			if(index == 0)//si mi posicion es la primera
    			{
    				this->pFirstNode = pNodeAux->pNextNode;
    				free(pNodeAux);
    				this->size--;
    				returnAux = 0;
    			}
    			else // en el medio o final
    			{
    				pNodePrev = getNode(this,index-1);

    				if(pNodePrev != NULL)
    				{
    		        	pNodePrev->pNextNode = pNodeAux->pNextNode;//al anterior nodo le paso la direccion del siguiente nodo que apuntaba el nodo que quiero eliminar
    		        	free(pNodeAux);
    		        	this->size--;
    					returnAux = 0;
    				}
    			}
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int index;

    if(this != NULL)
    {
    	if(!ll_isEmpty(this))
    	{
    		for(index=0; index<ll_len(this) ;index++)
    		{
    			ll_remove(this,index);//borro en todas las posiciones hasta el final del len
    			returnAux = 0;
    		}
    	}
    	else
    	{
        	this->pFirstNode = NULL;
        	this->size = 0;
        	returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
        	free(this);
        	returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* pNode = NULL;

    if(this != NULL && !ll_isEmpty(this))
    {
        for(i=0; i<ll_len(this) ;i++)
        {
        	pNode = getNode(this,i);//agarro el nodo en esa posicion
        	if(pNode != NULL && pNode->pElement == pElement)
        	{
        		returnAux = i;
        		break;
        	}
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);

    	returnAux = 1;

    	if(len>0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;


    if(this != NULL && index > -1 && index <= ll_len(this)){



    	returnAux = addNode(this,index,pElement);//le paso su posicion y lo que quiero guardar


    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* aux = NULL;


    if(this != NULL && index > -1 && index <= ll_len(this)){

    	aux = ll_get(this, index);

    	if(aux != NULL){

    	ll_remove(this,index);

    		returnAux = aux;
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int aux;


    if(this != NULL){

    	returnAux=0;

    	aux = ll_indexOf(this,pElement);

    	if(!aux){
    		returnAux= 1;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pElement = NULL;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	if(!ll_isEmpty(this2) && !ll_isEmpty(this))
    	{
    		for(i=0; i<ll_len(this2) ;i++)
    		{
    			pElement = ll_get(this2,i);

    			if(pElement != NULL)
    			{
    				if(!ll_contains(this,pElement))
    				{
    					returnAux = 0;
    					break;//si no encuentra algo, termina
    				}
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* clonelist = NULL;
    void* pElement = NULL;
    int i;

    if(this != NULL && from > -1 && to > -1 && from <= ll_len(this) && to <= ll_len(this))
    {
    	clonelist = ll_newLinkedList();//malloc y inicio
    	if(clonelist != NULL)
    	{
    		for(i=from; i<to ;i++)//recorro hasta to
    		{
    			pElement = ll_get(this,i);//agarro elemento de mi lista
    			ll_add(clonelist,pElement);//añado a la lista
    		}
    	}
    }

    return clonelist;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clone = NULL;

    if(this != NULL)
    {
    	clone = ll_subList(this,0,ll_len(this));

    }

    return clone;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len;
    int i;
    int j;

    void* element1;
    void* element2;

    if(this != NULL && pFunc!= NULL && (order ==0 || order==1))//order>=0 && order<=1)
    {
    	len= ll_len(this);
    	for(i=0; i<len-1; i++)
    	{
    		for(j= i+1 ; j<len; j++)
    		{
    			element1 = ll_get(this, i);
				element2 = ll_get(this, j);

				if ((pFunc(element1, element2) > 0 && order)
				 || (pFunc(element1, element2) < 0 && !order))
				{
					ll_set(this, i, element2);
					ll_set(this, j, element1);
				}
    		}
    	}
    	returnAux=0;
    }

    return returnAux;
}

/*
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{



	int returnAux = -1;
    int i;
    int j;
    int len;
    void* pElementA = NULL;
    void* pElementB = NULL;


    if(this != NULL &&  pFunc!=NULL && (order==1 || order==0) )
    {
    	len = ll_len(this);

    	for(i=0; i<len-1 ;i++)
    	{
    		pElementA = ll_get(this,i);//primer recorrida

    		for(j=i+1; j<len ;j++)
    		{

    			pElementB = ll_get(this,j);//elemento de mi segunda recorrida

    			if((pFunc(pElementA,pElementB)>0 && order==1) ||
    			(pFunc(pElementA,pElementB)<0 && order==0))
    				//si es p1 es mayor a p2, ascendente
    			{
    				 ll_set(this,i,pElementB);//pongo al menor
    				 ll_set(this,j,pElementA);
    				 returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;

}
*/

/*
 *La función “ll_count” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasárselos a la funcion “fn”. La función “fn” devolverá la cantidad que debe contarse segun
el criterio. La función “ll_count” almacenará un acumulador al cual sumará el valor de retorno de “fn” en
cada iteración. Al finalizar las iteraciones, la función “ll_count” devolverá el valor acumulado.
 *
 */


int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int returnAux = -1;
	int acumulador = 0;
	int i;
	int len = ll_len(this);

	if(this != NULL && fn != NULL){
		returnAux = 0;
		if(ll_isEmpty(this) == 0){
			returnAux = 1;
			void* pElement;
			for(i=0;i<len;i++){
				pElement = ll_get(this,i);
				if(pElement != NULL){
					acumulador += fn(pElement);
				}
			}
		}
	} else {
		return returnAux;
	}

	return acumulador;
}

/*
 * La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.
 *
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*fn) (void*) )
{
	LinkedList* newLsFilter;
	newLsFilter=NULL;
	int len;


	void* pAuxElem;
	int criterio;

	if(this != NULL && fn != NULL)
	{
		len= ll_len(this);
		if(len>0)
		{
			newLsFilter= ll_newLinkedList();

			for(int i= 0 ; i<len ; i++)
			{
				pAuxElem= ll_get(this,i);
				if(pAuxElem != NULL)
				{
					criterio= fn(pAuxElem);
					if(criterio==1)
					{
						ll_add(newLsFilter, pAuxElem);
					}
				}
			}

		}
	}
	return newLsFilter;
}


/*
Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una función.
La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista, de
este modo se realizarán descuentos a los precios según se detalla:
 *
 */
LinkedList* ll_map(LinkedList* this, void* (pFunc)(void*))
{
    void* pElement;
    LinkedList* listaMapeada;
    int i;

    listaMapeada = NULL;

    if(this != NULL && *pFunc != NULL)
    {
    	listaMapeada = ll_newLinkedList();

    	if(listaMapeada != NULL)
    	{
    		for (i = 0; i < ll_len(this); i++)
    		{
    			pElement = ll_get(this, i);
    		    pElement = pFunc(pElement);

    		    if(pElement!=NULL)
    		    {
    		        ll_add(listaMapeada, pElement);
    		    }
    		}
    	}
    }

    return listaMapeada;
}






