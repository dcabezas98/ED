SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -std=c++11 -Wall -g  -I$(INC) -c


all: vd cola

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

cola: $(BIN)/usopilas_max_Cola.out

$(BIN)/usopilas_max_Cola.out: $(OBJ)/usopilas_max_Cola.o $(LIB)/libpilamaxCola.a
	$(CXX) -o $@ $< -lpilamaxCola -L$(LIB)

$(OBJ)/usopilas_max_Cola.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_max.h $(INC)/Pila_max_Cola.h $(INC)/cola.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamaxCola.a: $(OBJ)/Pila_max_Cola.o $(OBJ)/cola.o
	ar -rvs $@ $^

$(OBJ)/Pila_max_Cola.o: $(SRC)/Pila_max_Cola.cpp $(INC)/Pila_max_Cola.h $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/cola.o: $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@
	
vd: $(BIN)/usopilas_max_VD.out

$(BIN)/usopilas_max_VD.out: $(OBJ)/usopilas_max_VD.o $(LIB)/libpilamaxVD.a
	$(CXX) -o $@ $< -lpilamaxVD -L$(LIB)

$(OBJ)/usopilas_max_VD.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_max.h $(INC)/Pila_max_VD.h $(INC)/vectordinamico.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamaxVD.a: $(OBJ)/Pila_max_VD.o $(OBJ)/vectordinamico.o
	ar -rvs $@ $^

$(OBJ)/Pila_max_VD.o: $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_VD.h $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/vectordinamico.o: $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(LIB)/*

mrproper: clean
	-rm -r $(BIN)/* doc/html doc/latex doc/man
