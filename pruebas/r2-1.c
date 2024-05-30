//
//  r2-1.c
//  Taller 2 - EdD - 2024.1
//  Prueba requisito 2, parte 1 - funciones básicas
//  Creado por Mauro San Martín el 20/03/2021 - actualizado 10/05/2024.
//

#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif /* stdlid_h */

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif /* stdio_h */

#ifndef entero_largo_lista_h
#define entero_largo_lista_h
#include "../entero_largo.h"
#endif /* entero_largo_lista_h */

int main(int argc, const char * argv[]) {
    //creación y muestra
    EnteroLargo *numero1 = creaEnteroLargoDesdeStr("0");
    EnteroLargo *numero2 = creaEnteroLargoDesdeStr("987654321987654321");
    EnteroLargo *numero3 = creaEnteroLargoDesdeStr("-987654321987654321");

    
    EnteroLargo *numero4 = creaEnteroLargoDesdeStr("0");
    copiaEnteroLargo(numero4, numero1);
    muestraEnteroLargo(numero4);
    printf(" %s ", creaStrDesdeEnteroLargo(numero1));
    
    EnteroLargo *numero5 = creaEnteroLargoDesdeStr("0");
    copiaEnteroLargo(numero5, numero2);
    muestraEnteroLargo(numero5);
    printf(" %s ", creaStrDesdeEnteroLargo(numero2));
    
    EnteroLargo *numero6 = creaEnteroLargoDesdeStr("0");
    copiaEnteroLargo(numero6, numero3);
    muestraEnteroLargo(numero6);
    printf(" %s ", creaStrDesdeEnteroLargo(numero3));
    
    eliminaEnteroLargo(numero1);
    eliminaEnteroLargo(numero2);
    eliminaEnteroLargo(numero3);
    eliminaEnteroLargo(numero4);
    eliminaEnteroLargo(numero5);
    eliminaEnteroLargo(numero6);
 return 0;
}
