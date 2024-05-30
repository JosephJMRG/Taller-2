//
//  r2-2.c
//  Taller 2 - EdD - 2024.1
//  Prueba requisito 2, parte 2 - archivos
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

    escribeEnteroLargo("enterolargo.bin", numero1);
    EnteroLargo *numero4 = leeEnteroLargo("enterolargo.bin");
    muestraEnteroLargo(numero4);
    printf(" %s ", creaStrDesdeEnteroLargo(numero1));
    
    escribeEnteroLargo("enterolargo.bin", numero2);
    EnteroLargo *numero5 = leeEnteroLargo("enterolargo.bin");
    muestraEnteroLargo(numero5);
    printf(" %s ", creaStrDesdeEnteroLargo(numero2));
    
    escribeEnteroLargo("enterolargo.bin", numero3);
    EnteroLargo *numero6 = leeEnteroLargo("enterolargo.bin");
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
