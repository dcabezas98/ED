#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# David Cabezas Berrido

"""
Programa que imprime las parejas (a, c) que dan lugar
a un esquema de hashing válido, evitando que la sucesión
de posiciones no cicle antes de tiempo.
"""

import sys
from itertools import product

M = int(sys.argv[1])

table = {}

a = int()
c = int()

def h(k, i = 0):
    if i == 0:
        return k%M
    
    else:
        return (h(k) + d(i))%M


def d(i):
    if i == 0: return 0
    return (a*d(i-1)+c)%M


def add(k):
    
    global table
    
    i = 0
    j = 1
    while h(k, i) in table and j <= M:
        i +=1
        j +=1

    if j > M:
        return 0

    else:
        table[h(k, i)] = k
        return 1
    
 
if __name__=="__main__":
    
    for i, j in product(range(M), range(M)):

        sigue = 1

        a, c = i, j
    
        for _ in range(M):
        
            if not add(10):
                sigue = 0
                break

        if sigue:
            print("a = ", a, "\t", "c = ", c)

        table = {}
