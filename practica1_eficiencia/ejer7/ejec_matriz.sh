#!/bin/bash

inicio=10
fin=510
incremento=10

ejecutable="matriz"
salida="tiempos_matriz.dat"

i=$inicio

echo > $salida

while [ $i -lt $fin ]
do
    echo "Ejecucion tam = " $i
    echo `./$ejecutable $i` >> $salida
    i=$[ $i + $incremento ]
done
