#!/bin/sh

echo "Ejecutando prueba r3: suma y resta"
echo

output=$(./pruebas/r3)
expected_output="[18]+100000000000000001[1]+0[1]+0[17]-99999999999999999[1]+2[1]-2"

if [ $? -eq 0 ] ; then
  echo "Pasa: Programa retorno 0"
else
  echo "Falla prueba r3: Programa NO retorno 0"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pasa: Salida es correcta"
else
  echo "Falla prueba r3: Se esperaba '$expected_output' pero produjo: $output"
  exit 1
fi

echo
echo "Pasa prueba r3: suma y resta"

exit 0
