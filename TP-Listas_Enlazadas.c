#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo* sig;
} elem;

void mostrar(elem* elemento){
    if(elemento != NULL){
        printf("Elemento: %d \n", elemento->dato);
        mostrar(elemento->sig);
    }
}

void insertar(int d, elem** elemento){
    if(*elemento == NULL){
        printf("Insertando %d en la lista \n", d);
        *elemento = (elem*) malloc (sizeof (elem));
        (*elemento)->dato = d;
    } else {
        if
    }
}