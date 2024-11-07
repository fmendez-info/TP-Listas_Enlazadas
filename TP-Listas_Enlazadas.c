/* listas.c */

#include <stdio.h>
#include <stdlib.h>
#include "TP-Listas_Enlazadas.h"

int main(){
    char voto;
    char nombre;
    char mandato[12];
    Nodo* chicos_malos;
    Nodo* chicos_buenos;
    chicos_malos = NULL;
    chicos_buenos = NULL;

    do{ //bucle para validar el ingreso del voto
        printf("Ingrese voto\n");
        scanf(" %c", &voto);
    } while (voto!='F' && voto!='D' && voto!='E');    
    while (voto!='E'){ //bucle para pedir todos los mandatos
        printf("Ingrese nombre\n");
        scanf(" %c", &nombre);
        switch (voto){
    /* do{
        printf("Ingrese mandato\n");
        scanf("%11[^\n]", mandato);
        switch (mandato[0]){ */
            case 'F':
                //inserta(nombre, &chicos_buenos); //le paso el elemento y la direccion de la lista
                miembro(nombre, chicos_malos) ? suprime(nombre, &chicos_malos) : 0;
                !miembro(nombre, chicos_buenos) ? inserta(nombre, &chicos_buenos) : 0;
                break;
            case 'D':
                //inserta(nombre, &chicos_malos);
                miembro(nombre, chicos_buenos) ? suprime(nombre, &chicos_buenos) : 0;
                !miembro(nombre, chicos_malos) ? inserta(nombre, &chicos_malos) : 0;
                break;
        }
        do{ //bucle para validar el ingreso del voto
            printf("Ingrese voto\n");
            scanf(" %c", &voto);
        } while (voto!='F' && voto!='D' && voto!='E');  
    }
    /* }while (mandato[0]!='E'); */
    
    printf("Chicos buenos: \n");
    mostrar(chicos_buenos);
    printf("Chicos malos: \n");
    mostrar(chicos_malos);

    return 0;
}

void inserta(char n, Nodo** lista){
    Nodo* nuevo = (Nodo*) malloc (sizeof(Nodo)); //1: reservo espacio para un nuevo nodo
    nuevo->nombre = n;                           //2: cargo el dato en el nuevo nodo
    nuevo->sig = *lista;                         //3: almaceno la direccion del siguiente (que antes era el primero)
    *lista = nuevo;                              //4: ahora lista apunta al nuevo elemento (que ahora es el primero)
    return;
}

void suprime(char n, Nodo** lista){
    if(*lista!=NULL){
        if((*lista)->nombre == n){  //si encontre el que hay que borrar
            Nodo* aux = *lista;     //guardo en aux la direccion
            *lista = (*lista)->sig; //ahora el elemento anterior apunta al siguiente
            free(aux);              //libero la direccion del que se borra
        } else {                        //si no lo encontre
            suprime(n,&(*lista)->sig);  //llamo a la funcion recursivamente apuntando al sig del proximo elemento
        }
    }
    return;
}

int miembro(char n, Nodo* lista){
    if(lista != NULL){
        if(lista->nombre == n){
            return 1;
        }
        return miembro(n, lista->sig);
    }
    return 0;
}

void mostrar(Nodo* lista){          //funcion recursiva, muestro el primer elemento y recurso con la lista restante
    if(lista != NULL){                  //si llegue al ultimo elemento (puntero null) termino la recursion
        printf("%c\n", lista->nombre);  //muestro el elemento
        mostrar(lista->sig);            //llamo a la funcion con el elemento siguiente (pasandole el puntero del siguiente)
    }
    return;
}