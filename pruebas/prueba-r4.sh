#!/bin/sh

echo "Ejecutando prueba r4: multiplicación y división"
echo

output=$(./pruebas/r4)
expected_output="[6]+100000[4]-1000[4]-1000[4]+7000[2]+33[2]-33[3]-333[3]+333[1]+0"

if [ $? -eq 0 ] ; then
  echo "Pasa: Programa retorno 0"
else
  echo "Falla prueba r4: Programa NO retorno 0"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pasa: Salida es correcta"
else
  echo "Falla prueba r4: Se esperaba '$expected_output' pero produjo: $output"
  exit 1
fi

echo
echo "Pasa prueba r4: multiplicación y división"

exit 0
