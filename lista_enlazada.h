#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{
    int digito;
    struct Nodo *siguiente;
}Nodo;

void agregarElemento(struct Nodo** inicio, int nuevoValor) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->digito = nuevoValor;
    nuevoNodo->siguiente = NULL;

    if (*inicio == NULL) {
        *inicio = nuevoNodo;
    } else {
        struct Nodo* ultimo = *inicio;
        while (ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;
        }
        ultimo->siguiente = nuevoNodo;        
    }
}

void invertirLista(struct Nodo** inicio){//damos la vuelta la lista, usar en las sumas y restas de entero largo
    
    struct Nodo* actual = *inicio;
    struct Nodo* siguiente = NULL;
    struct Nodo* anterior = NULL;

    while (actual != NULL)
    {
        siguiente = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = siguiente;
    }
    *inicio = anterior;

}


void imprimirLista(struct Nodo* inicio) {
    struct Nodo* actual = inicio;
    while (actual != NULL)
    {
        printf("%d", actual->digito);
        actual = actual->siguiente;
    }
    
    //printf("NULL\n");
    //printf("\n---\n");
}

//devuelve el valor guardado en la posicion dada ex: 132, pedimos pos 2, devuelve 2. Podemos usarlo para ir valor por valor de la lista y hacer varias operaciones
int leerNumeroLista(struct Nodo* inicio, int posicionDada) {
    struct Nodo* actual = inicio;
    int posicionActual = 0;
  
    while (actual != NULL && posicionActual < posicionDada) {  //revisamos que exista la posicion actual y que no sea mayor al numero dado
        actual = actual->siguiente;  //ya que no podemos simplemente saltar de una en la lista tenemos que ir de dato en dato
        posicionActual++;            //hasta llegar a la posicion dada
    }
    if(actual != NULL){
        return actual->digito; 
    }else{
        return -1; //para revisar por errores
    }
    
}



char leerNumeroListaEnChar(struct Nodo* inicio, int posicionDada){//usar para cuando queramos pasar de entero largo a string
  struct Nodo* actual = inicio;
  int posicionActual = 0;
  char numeroChar;
  while(actual != NULL && posicionActual < posicionDada){//mismo sistema que en leerNumeroLista
    actual = actual->siguiente;
    posicionActual++;
  }
  if(actual != NULL){
    numeroChar = (actual->digito+'0'); //en ASSCI o como se llame, si le sumamos un 0 en formato char a un digito este se convertira en formato char
    return numeroChar;      //ejemplo: en ASCII 053 = 5, http://www.unit-conversion.info/texttools/ascii/
  }else{
    return '?';//mensaje de error, usar para checar que no hay problemas al usar esa funcion
  }
}
//referencia
//https://stackoverflow.com/questions/2279379/how-to-convert-integer-to-char-in-c#:~:text=A%20char%20in%20C%20is,character%20in%20the%20ASCll%20table.
int convertirCharInt(char letra){
    int numero= (letra-'0');
    return numero;
}
char convertirIntChar(int numero){
    char letra = (numero+'0');
    return letra;
}

void liberarMemoria(struct Nodo* inicio){
  struct Nodo* actual = inicio;
  while(inicio != NULL){ //se ejecutara hasta que pase por toda la lista
    actual = actual->siguiente;  //actualizamos el siguiente nodo a eliminar
    free(inicio);  //eliminamos el nodo actual
    inicio = actual;  //actualizamos el nodo actual al siguiente
  }
}
//ni idea como son tan distintos
void liberarDigitos(Nodo *inicio) {//elimina los digitos de un enterolargo 
    Nodo *actual = inicio;
    Nodo *siguiente;

    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}
