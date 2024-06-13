#include <iostream>
#include "./list.hpp"
using namespace std;

template <class T>
bool List<T>::isEmpty() {
    return this->head == NULL;
}

template <class T>
void List<T>::insertFirst(Node<T>* node) { 
    Node<T>* temp = head;
    head = node;
    head->setNextNode(temp);
}

template <class T>
void List<T>::insert(T data) { //INSERTAMOS SIN ORDEN PARA LUEGO ACOMODARLOS
    Node<T>* newNode = new Node<T>(data, head);
    head = newNode;
}

template <class T>
void List<T>::ordenarMayorMenor() {
    if(head != NULL){ //COMPROBAMOS SI LA LISTA ESTA VACIA

        //USAMOS EL ALGORITMO DE BUBLE SORT PARA ORDENAR
        for (Node<T>* i = head; i != NULL; i = i->getNextNode()) 
        {
            for (Node<T>* j = i->getNextNode(); j != NULL; j = j->getNextNode()) 
            {
                if (i->getData().cedula < j->getData().cedula) 
                {
                    T temp = i->getData();
                    i->setData(j->getData());
                    j->setData(temp);
                }
            }
        }

    }
}

template <class T>
void List<T>::ordenarMenorMayor(){

    if (head != NULL){ //COMPROBAMOS SI LA LISTA ESTA VACIA

        //USAMOS EL ALGORITMO DE BUBLE SORT PARA ORDENAR
        for (Node<T>* i = head; i != NULL; i = i->getNextNode())
        {
            for (Node<T>* j = i->getNextNode(); j != NULL; j = j->getNextNode())
            {
                if (i->getData().cedula > j->getData().cedula) 
                {
                    T temp = i->getData();
                    i->setData(j->getData());
                    j->setData(temp);
                }
            }
           
        }
    } 
}


template <class T>
void List<T>::print() {
    Node<T>* current = head;
    while (current != NULL) {
        cout<<"Cedula: "<<current->getData().cedula<<endl; 
        cout<<"Nombre: "<<current->getData().nombre<<endl;
        cout<<"Edad: "<<current->getData().edad<<endl<<endl;
        current = current->getNextNode();
    }
}

template <class T>
void List<T>::obtenerReferencia(int punto_partida, int punto_llegada) {
    Node<T>* current = head;

    // Recorrer la lista
    while (current != NULL) {
        if (current->getData().edad >= punto_partida && current->getData().edad <= punto_llegada) {
            // Imprimir los datos
            cout<<"Cedula: "<<current->getData().cedula<<endl; 
            cout<<"Nombre: "<<current->getData().nombre<<endl;
            cout<<"Edad: "<<current->getData().edad<<endl<<endl;
        }
        current = current->getNextNode();
    }
}


template <class T>
void List<T>::borrarElementosIntervalo(int punto_partida, int punto_llegada) {
    Node<T>* current = head;
    Node<T>* last = NULL;

    while (current != NULL)
    {

        if (current->getData().edad >= punto_partida && current->getData().edad <= punto_llegada) 
        {
            //Eliminamos el nodo

            if (last == NULL) //Si el nodo es head
            {
                head = current->getNextNode();
                delete current;
                current = head;
            } 
            else 
            {   //Si el nodo no es head

                last->setNextNode(current->getNextNode());
                delete current;
                current = last->getNextNode();
            }
        } 
        else 
        {
            last = current;
            current = current->getNextNode();
        }
    }
}






