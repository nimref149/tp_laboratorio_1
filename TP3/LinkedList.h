/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
//se guarda la dirrecion de memoria del primer estructura y del ultimo
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


///trabajaremos con algunas funciones
///linkedlist.a biblioteca encapsulada
///Publicas
LinkedList* ll_newLinkedList(void);
///crea una lista con malloc

int ll_len(LinkedList* this);
///devuelve la cantidad de elementos que estan enganchados a la
///lista,en este caso estructuras cuenta cuantos hay
///en el tp4 esta todos lo que devuelve el linkedlist

///---------------------------------no usar
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
///---------------------------------

int ll_add(LinkedList* this, void* pElement);
///agrega una estructura puntero,recibe puntero a void por que es para cualquier tipo generico,deuvleve si pudo agregarlo o no
//
void* ll_get(LinkedList* this, int index);
///le paso lista e indice y dice cual es el objeto que esta en ese indice,como buscar por indice me devuelve esa entidad

int ll_set(LinkedList* this, int index,void* pElement);
///pone un elemento arriva de otro lo reemplasa si quiero unset en la ultima posicion lo que hace es agregar uno nuevo

int ll_remove(LinkedList* this,int index);
///me saca un elemento de la lista,devueve entero si pudo elminarlo o no

int ll_clear(LinkedList* this);
///elimina todos los elementos de la lista pero no borra la lista

int ll_deleteLinkedList(LinkedList* this);
///se encarga de borrar la lista con todos los elementos

int ll_indexOf(LinkedList* this, void* pElement);
///le pasa un elemento y te dice en que indice esta, es como el buscar por id pero en ves de pasar un id le pasas un elemento devuelv donde esta

int ll_isEmpty(LinkedList* this);
///me dice si hay algo en la lista o no,nesesito saber si hay elementos , no cuantos hay si hay almenos uno

int ll_push(LinkedList* this, int index, void* pElement);
///pone algo en el medio de algo, agrega uno mas

void* ll_pop(LinkedList* this,int index);
///elimina elemento, antes de borrarlo lo recupera y lo devuelve,  saca de una lista para meterlo en otra lista

int ll_contains(LinkedList* this, void* pElement);
///le pasas un elemento y dice si est aen la lista

int ll_containsAll(LinkedList* this,LinkedList* this2);
///me dice si todos los elementos de segunda estan en la primera lista

LinkedList* ll_subList(LinkedList* this,int from,int to);
///creo una lista que esta en otra,devuelve un pedaso de la listadesde doinde hasta donde quiero la sub listadesd el quinto hasta el septimo entonces me devuelve desde el 5 hasta el 6

LinkedList* ll_clone(LinkedList* this);
///crea una copia identica de la lista, no impacta en otra lista

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
//devuelve si son iguales si uno es mayor o menor al otro
//el sort llama a la funcion levanta 2 punteros y los lleva a la funcion si quiero que
//ordene por legajo tengo una funcion que compara por legajo,puedo tener distintos tipos de comparacion
//doy el comportamiento de una funcion a otra funcion
//
//ordena una lista, hace un swap con los elementos
