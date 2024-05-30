#!/bin/sh

echo "Ejecutando prueba r2-2: funciones básicas (parte 2: archivos)"
echo

output=$(./pruebas/r2-2)
expected_output="[1]+0 0 [18]+987654321987654321 987654321987654321 [18]-987654321987654321 -987654321987654321 "

if [ $? -eq 0 ] ; then
  echo "Pasa: Programa retorno 0"
else
  echo "Falla prueba r2-2: Programa NO retorno 0"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pasa: Salida es correcta"
else
  echo "Falla prueba r2-2: Se esperaba '$expected_output' pero produjo: $output"
  exit 1
fi

echo
echo "Pasa prueba r2-2: funciones básicas (parte 2: archivos)"

exit 0
