//
//  r3.c
//  Taller 2 - EdD - 2024.1
//  Prueba requisito 3 - suma y resta
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
    EnteroLargo *numero0 = creaEnteroLargoDesdeStr("0");
    EnteroLargo *numero1 = creaEnteroLargoDesdeStr("1");
    EnteroLargo *numero1n = creaEnteroLargoDesdeStr("-1");
    EnteroLargo *numero1_17 = creaEnteroLargoDesdeStr("100000000000000000");
    EnteroLargo *numero1_17n = creaEnteroLargoDesdeStr("-100000000000000000");
    EnteroLargo *numero9_17 = creaEnteroLargoDesdeStr("99999999999999999");
    EnteroLargo *numero9_17n = creaEnteroLargoDesdeStr("-99999999999999999");

    //suma
    //resultado1 debería ser 100000000000000001
    EnteroLargo *resultado1 = sumaEnteroLargo(numero1, numero1_17);
    
    //resultado2 debería ser 0
    EnteroLargo *aux1 = sumaEnteroLargo(numero1, numero1_17n);
    EnteroLargo *resultado2 = sumaEnteroLargo(aux1, numero9_17);
    
    //resultado3 debería ser 0
    EnteroLargo *aux2 = sumaEnteroLargo(numero1n, numero1_17);
    EnteroLargo *resultado3 = sumaEnteroLargo(aux2, numero9_17n);

    //resta
    //resultado4 debería ser -99999999999999999
    EnteroLargo *resultado4 = restaEnteroLargo(numero1, numero1_17);
    
    //resultado5 debería ser 2
    EnteroLargo *aux3 = restaEnteroLargo(numero1, numero1_17n);
    EnteroLargo *resultado5 = restaEnteroLargo(aux3, numero9_17);
    
    //resultado6 debería ser -2
    EnteroLargo *aux4 = restaEnteroLargo(numero1n, numero1_17);
    EnteroLargo *resultado6 = restaEnteroLargo(aux4, numero9_17n);

    muestraEnteroLargo(resultado1);
    muestraEnteroLargo(resultado2);
    muestraEnteroLargo(resultado3);
    muestraEnteroLargo(resultado4);
    muestraEnteroLargo(resultado5);
    muestraEnteroLargo(resultado6);

    eliminaEnteroLargo(numero0);
    eliminaEnteroLargo(numero1);
    eliminaEnteroLargo(numero1n);
    eliminaEnteroLargo(numero1_17);
    eliminaEnteroLargo(numero1_17n);
    eliminaEnteroLargo(numero9_17);
    eliminaEnteroLargo(numero9_17n);
    eliminaEnteroLargo(aux1);
    eliminaEnteroLargo(aux2);
    eliminaEnteroLargo(aux3);
    eliminaEnteroLargo(aux4);
    eliminaEnteroLargo(resultado1);
    eliminaEnteroLargo(resultado2);
    eliminaEnteroLargo(resultado3);
    eliminaEnteroLargo(resultado4);
    eliminaEnteroLargo(resultado5);
    eliminaEnteroLargo(resultado6);

 return(0);
}
