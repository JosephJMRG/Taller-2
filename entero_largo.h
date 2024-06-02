//
//  entero_largo.h
//  Taller 2 - EdD - 2024.1
//
//  Plantilla librería implementación EnteroLargo

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlid_h */

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif /* stdio_h */

#ifndef string_h
#define string_h
#include <string.h>
#endif /* string_h */

#ifndef lista_enlazada_h
#define lista_enlazada_h
#include "lista_enlazada.h"
#endif /* lista_enlazada_h */

//Puede agregar otras librerías implementadas en su proyecto o
//de la librería estandar del lenguaje C.

//
//Definición estructura de datos
//
typedef struct _enterolargo{    //lista para numeros en formato int
    int cantidadDigitos;//cantidad de dígitos
    char signo;//signo 0=menos, 1 = mas   
    struct Nodo *siguiente;//direccion a digitos empezando la lista 
}EnteroLargo;
//
//Prototipos interfaz
//
EnteroLargo *creaEnteroLargoDesdeStr(char *numero);
char *creaStrDesdeEnteroLargo(EnteroLargo *numero);
void copiaEnteroLargo(EnteroLargo *destino, EnteroLargo *fuente);
void eliminaEnteroLargo(EnteroLargo *numero);
// !!!
//La siguiente función es necesaria para que funcionen las pruebas automáticas
//Abajo se porporciona una plantilla de implementación que DEBE modificar para
//que funcione: debe agregar las nombres de los campos de su estructura y la
//función que muestra el contenido de la lista enlazada de dígitos
void muestraEnteroLargo(EnteroLargo *numero);
// !!!
void escribeEnteroLargo(char *nombreArchivo, EnteroLargo *numero);
EnteroLargo *leeEnteroLargo(char *nombreArchivo);
int igualEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *restaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2);
EnteroLargo *multiplicaEnteroLargo(EnteroLargo *multiplicando, EnteroLargo *multiplicador);
EnteroLargo *divideEnteroLargo(EnteroLargo *dividendo, EnteroLargo *divisor);

//
//Implememntaciones
//
EnteroLargo *creaEnteroLargoDesdeStr(char *numero){
    
    EnteroLargo *unEnteroLargo = (EnteroLargo*)malloc(sizeof(EnteroLargo));    //creamos y damos memoria
    unEnteroLargo->siguiente = NULL; //asignamos memoria al siguiente
    int valor,i=0;
    
    //unEnteroLargo ->cantidadDigitos = sizeof(numero)
    unEnteroLargo ->cantidadDigitos = strlen(numero);
        //guardamos la cantidad de digitos 
    
    if(numero[0] == '-'){//preguntamos si el primer dato en el str es - ; si es el caso avanzamos en 1 la lectura del str y asignamos guardamos el signo
        i++;
        unEnteroLargo->signo = '-';
    }else{
        unEnteroLargo->signo = '+';
    }
    
    while(i<(unEnteroLargo->cantidadDigitos)){ //mientras i sea menor o igual a la cantidad de digitos en el str
        valor = convertirCharInt(numero[i]); //convertimos el char en int
        agregarElemento(&(unEnteroLargo->siguiente),valor); //agregamos el int a la lista en la siguiente posicion
        i++;
    }
    
    return(unEnteroLargo);
}


void strToInt(char *num){
    
}

char *creaStrDesdeEnteroLargo(EnteroLargo *numero){
    int tamanoStr = numero->cantidadDigitos; 
    int valor, negativo = 0;
    char digito;
    
    char *auxStr = (char *)malloc((tamanoStr) * sizeof(char)); //espacio para el string satanico lo se

    if (numero->signo == '-') {//preguntamos si el signo es negativo para un int importante
        auxStr[0] = '-'; 
        negativo = 1;
    }else{
        auxStr[0] = '+'; 
    }
                    //NO SACAR, el negativo es importante como dije, si no esta , cuando se trabaje con el signo negativo, al final del string quedara un \ dependiendo de la cantidad de espacios vacios no asignados haya
    for (int i = 0; i < tamanoStr-negativo; i++) {      // mas '\' mas espacio extra tiene el string
        //buscamos el valor segun la posicion
        valor = leerNumeroLista(numero->siguiente, i);
        digito = convertirIntChar(valor);//convertimos el formato del valor a char
        
        auxStr[i + negativo] = digito; //acoplamos en la posicion el valor
    }
    
    auxStr[tamanoStr + negativo] = '\0';//aseguramos que el string termine en el formato correcto
    
    return auxStr;
    
}


void copiaEnteroLargo(EnteroLargo *destino, EnteroLargo *fuente){
    int num,negativo=0;

    //printf("%c",fuente->signo);
    liberarDigitos(destino->siguiente);//eliminamos los digitos guardados dentro del entero largo via liberando la memoria
    destino->siguiente = NULL; //aseguramos que existe donde guardar dichos valores

    //cambiamos directamente los valores de destino por los de fuente
    destino->signo = fuente->signo;
    if(destino->signo == '-'){//preguntamos si hay negativo
        negativo = 1;
    }
    destino->cantidadDigitos = fuente->cantidadDigitos-negativo;

                        //NO SACAR ESTO, el negativo asegura que no haya datos fanatasma"" por decirlo de un modo. 
    for (int i = 0; i < fuente->cantidadDigitos-negativo; i++) { //si lo eliminan cuando se trabaje con negativos el enterolargo finalizara con un -1 , que es un valor de error dentro de lista_enlazada
        num = leerNumeroLista(fuente->siguiente, i); //buscamos el valor dentro de la fuente
        agregarElemento(&(destino->siguiente), num);//se lo pegamos al destion y fin
    }
}


void eliminaEnteroLargo(EnteroLargo *numero){
    //...
}

//ESTA FUNCIÓN DEBE EXISTIR PARA QUE FUNCIONEN LAS PRUEBAS AUTOMÁTICAS
//PARA QUE FUNCIONE DEBE HACER LOS CAMBIOS INDICADOS EN LOS COMENTARIOS
void muestraEnteroLargo(EnteroLargo *numero){
    if(numero !=NULL){
        //reemplace <CANTIDAD_DIGITOS> por el campo de EnteroLargo que contiene
        //la cantidad de dígitos del número
        printf("[%d]",numero->cantidadDigitos);
        //reemplace <SIGNO> por el campo de EnteroLargo que contiene
        //el signo del número en su estructura
        printf("%c",numero->signo);
        //reemplace <muestraListaDigitos(<DIGITOS>)> por la función de la lista
        //enlazada que muestra el contenido de la lista de digitos (<DIGITOS>)
        //del EnteroLargo
        //<muestraListaDigitos(<DIGITOS>)>;
        imprimirLista(numero->siguiente);
    }else{
        printf("NULL");
    }
}


void escribeEnteroLargo(char *nombreArchivo, EnteroLargo *numero) {
    // Verificar que el número no sea nulo
    if (numero == NULL) {
        printf("El número proporcionado es nulo.\n");
        return;
    }

    // Abrir el archivo en modo binario para escritura
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para escribir.\n", nombreArchivo);
        return;
    }

    // Escribir el signo en el archivo
    if (fwrite(&(numero->signo), sizeof(char), 1, archivo) != 1) {
        printf("Error al escribir el signo en el archivo.\n");
        fclose(archivo);
        return;
    }

    // Escribir la cantidad de dígitos en el archivo
    if (fwrite(&(numero->cantidadDigitos), sizeof(int), 1, archivo) != 1) {
        printf("Error al escribir la cantidad de dígitos en el archivo.\n");
        fclose(archivo);
        return;
    }

    // Escribir los dígitos en el archivo recorriendo la lista enlazada
    Nodo *actual = numero->siguiente;
    while (actual != NULL) {
        if (fwrite(&(actual->digito), sizeof(int), 1, archivo) != 1) {
            printf("Error al escribir un dígito en el archivo.\n");
            fclose(archivo);
            return;
        }
        actual = actual->siguiente;
    }

    // Cerrar el archivo y finalizar escritura
    fclose(archivo);
}


EnteroLargo *asignarMemoriaEnteroLargo();
int leerSigno(FILE *archivo, EnteroLargo *unEnteroLargo);
int leerCantidadDigitos(FILE *archivo, EnteroLargo *unEnteroLargo);
int construirListaDigitos(FILE *archivo, EnteroLargo *unEnteroLargo);

EnteroLargo *leeEnteroLargo(char *nombreArchivo) {
    // Asignar memoria para EnteroLargo
    EnteroLargo *unEnteroLargo = asignarMemoriaEnteroLargo();
    if (unEnteroLargo == NULL) return NULL;

    // Abrir el archivo en modo binario para lectura
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para leer.\n", nombreArchivo);
        free(unEnteroLargo);
        return NULL;
    }

    // Leer el signo del número
    if (leerSigno(archivo, unEnteroLargo) == -1) {
        free(unEnteroLargo);
        fclose(archivo);
        return NULL;
    }

    // Leer la cantidad de dígitos
    if (leerCantidadDigitos(archivo, unEnteroLargo) == -1) {
        free(unEnteroLargo);
        fclose(archivo);
        return NULL;
    }

    // Ajustar la cantidad de dígitos para números negativos
    if (unEnteroLargo->signo == '-') {
        unEnteroLargo->cantidadDigitos--; 
    }

    // Construir la lista enlazada de dígitos
    if (construirListaDigitos(archivo, unEnteroLargo) == -1) {
        Nodo *temp = unEnteroLargo->siguiente;
        while (temp != NULL) {
            Nodo *siguiente = temp->siguiente;
            free(temp);
            temp = siguiente;
        }
        free(unEnteroLargo);
        fclose(archivo);
        return NULL;
    }

    // Cerrar el archivo
    fclose(archivo);
    return unEnteroLargo;
}

EnteroLargo *asignarMemoriaEnteroLargo() {
    EnteroLargo *unEnteroLargo = (EnteroLargo *)malloc(sizeof(EnteroLargo));
    if (unEnteroLargo == NULL) {
        printf("No se pudo asignar memoria para EnteroLargo.\n");
    } else {
        unEnteroLargo->siguiente = NULL;
    }
    return unEnteroLargo;
}

int leerSigno(FILE *archivo, EnteroLargo *unEnteroLargo) {
    if (fread(&(unEnteroLargo->signo), sizeof(char), 1, archivo) != 1) {
        printf("Error al leer el signo del archivo.\n");
        return -1;
    }
    // printf("Leyendo signo: %c\n", unEnteroLargo->signo);
    return 0;
}

int leerCantidadDigitos(FILE *archivo, EnteroLargo *unEnteroLargo) {
    if (fread(&(unEnteroLargo->cantidadDigitos), sizeof(int), 1, archivo) != 1) {
        printf("Error al leer la cantidad de dígitos del archivo.\n");
        return -1;
    }
    // printf("Cantidad de dígitos leída: %d\n", unEnteroLargo->cantidadDigitos);
    return 0;
}

int construirListaDigitos(FILE *archivo, EnteroLargo *unEnteroLargo) {
    int cantidadDigitos = unEnteroLargo->cantidadDigitos;
    Nodo *anterior = NULL;
    for (int i = 0; i < cantidadDigitos; i++) {
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevoNodo == NULL) {
            printf("No se pudo asignar memoria para Nodo.\n");
            return -1;
        }

        if (fread(&(nuevoNodo->digito), sizeof(int), 1, archivo) != 1) {
            printf("Error al leer un dígito del archivo.\n");
            free(nuevoNodo);
            return -1;
        }
        // Debug
        // printf("Dígito leído: %d\n", nuevoNodo->digito);

        nuevoNodo->siguiente = NULL;
        if (anterior == NULL) {
            unEnteroLargo->siguiente = nuevoNodo;
        } else {
            anterior->siguiente = nuevoNodo;
        }
        anterior = nuevoNodo;
    }

    return 0;
}


int igualEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2){
    //...
    return(0);
}


EnteroLargo *sumaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2){
    EnteroLargo *resultado = NULL;
    //...
    return (resultado);
}


EnteroLargo *restaEnteroLargo(EnteroLargo *numero1, EnteroLargo *numero2){
    EnteroLargo *resultado = NULL;
    //...
    return (resultado);
}


EnteroLargo *multiplicaEnteroLargo(EnteroLargo *multiplicando, EnteroLargo *multiplicador){
    EnteroLargo *resultado = NULL;
    //...
    return (resultado);
}


EnteroLargo *divideEnteroLargo(EnteroLargo *dividendo, EnteroLargo *divisor){
    EnteroLargo *resultado = NULL;
    //...
    return (resultado);
}


