#!/bin/bash

inicio=100
fin=30000
incremento=500

ejecutable="ordenacion_mejor"
salida="tiempos_ordenacion_mejor_1.dat"

i=$inicio

echo > $salida

while [ $i -lt $fin ]
do
    echo "Ejecucion tam = " $i
    echo `./$ejecutable $i ` >> $salida
    i=$[ $i + $incremento ]
done
