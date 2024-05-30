//
//  r4.c
//  Taller 2 - EdD - 2024.1
//  Prueba requisito 4  - multiplicación y división 
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
    //creación 
    EnteroLargo *numero40 = creaEnteroLargoDesdeStr("1000");
    EnteroLargo *numero41 = creaEnteroLargoDesdeStr("100");
    EnteroLargo *numero42 = creaEnteroLargoDesdeStr("-1");
    EnteroLargo *numero43 = creaEnteroLargoDesdeStr("-1000");
    EnteroLargo *numero44 = creaEnteroLargoDesdeStr("-7");

    EnteroLargo *numero70 = creaEnteroLargoDesdeStr("100");
    EnteroLargo *numero71 = creaEnteroLargoDesdeStr("3");
    EnteroLargo *numero72 = creaEnteroLargoDesdeStr("-3");
    EnteroLargo *numero73 = creaEnteroLargoDesdeStr("-1000");

    //multiplicación
    EnteroLargo *numero45 = multiplicaEnteroLargo(numero40, numero41);
    EnteroLargo *numero46 = multiplicaEnteroLargo(numero40, numero42);
    EnteroLargo *numero47 = multiplicaEnteroLargo(numero42, numero40);
    EnteroLargo *numero48 = multiplicaEnteroLargo(numero43, numero44);
   
    //división
    EnteroLargo *numero75 = divideEnteroLargo(numero70, numero71);
    EnteroLargo *numero76 = divideEnteroLargo(numero70, numero72);
    EnteroLargo *numero77 = divideEnteroLargo(numero73, numero71);
    EnteroLargo *numero78 = divideEnteroLargo(numero73, numero72);
    EnteroLargo *numero79 = divideEnteroLargo(numero72, numero73);
   
    //EnteroLargo *unNumero2 = creaEnteroLargoDesdeStr("2");
    //EnteroLargo *unNumeroGrande = creaEnteroLargoDesdeStr("100000000");
    //EnteroLargo *unResultado = divideEnteroLargo(unNumeroGrande, unNumero2);
    //imprime("unResultado: 100000000/2=50000000 -> ",unResultado,"\n");

    muestraEnteroLargo(numero45);
    muestraEnteroLargo(numero46);
    muestraEnteroLargo(numero47);
    muestraEnteroLargo(numero48);

    muestraEnteroLargo(numero75);
    muestraEnteroLargo(numero76);
    muestraEnteroLargo(numero77);
    muestraEnteroLargo(numero78);
    muestraEnteroLargo(numero79);

    eliminaEnteroLargo(numero40);
    eliminaEnteroLargo(numero41);
    eliminaEnteroLargo(numero42);
    eliminaEnteroLargo(numero43);
    eliminaEnteroLargo(numero44);
    eliminaEnteroLargo(numero45);
    eliminaEnteroLargo(numero46);
    eliminaEnteroLargo(numero47);
    eliminaEnteroLargo(numero48);

    eliminaEnteroLargo(numero70);
    eliminaEnteroLargo(numero71);
    eliminaEnteroLargo(numero72);
    eliminaEnteroLargo(numero73);
    eliminaEnteroLargo(numero75);
    eliminaEnteroLargo(numero76);
    eliminaEnteroLargo(numero77);
    eliminaEnteroLargo(numero78);
    eliminaEnteroLargo(numero79);
    

 return(0);
}
