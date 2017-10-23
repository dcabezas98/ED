#!/bin/bash

inicio=100
fin=30000
incremento=500

ejecutable="nueva/ejercicio_desc"
salida="nueva/tiempos_desc.dat"

i=$inicio

echo > $salida

while [ $i -lt $fin ]
do
    echo "Ejecucion tam = " $i
    echo `./$ejecutable $i ` >> $salida
    i=$[ $i + $incremento ]
done

