/* listas.h */

typedef struct nodo{
    char nombre;
    struct nodo* sig;
} Nodo;

void inserta(char, Nodo**);
void suprime(char, Nodo**);
int miembro(char, Nodo*);
void mostrar(Nodo*);