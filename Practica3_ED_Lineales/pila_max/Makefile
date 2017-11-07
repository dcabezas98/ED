SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/usopilas_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(LIB)/libpilamax.a
	$(CXX) -o $@ $< -lpilamax -L$(LIB)

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_max.h $(INC)/Pila_max_VD.h $(INC)/Pila_max_Cola.h $(INC)/vectordinamico.h $(INC)/cola.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamax.a: $(OBJ)/Pila_max_VD.o $(OBJ)/Pila_max_Cola.o $(OBJ)/vectordinamico.o $(OBJ)/cola.o
	ar -rvs $@ $^

$(OBJ)/Pila_max_VD.o: $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_VD.h $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Pila_max_Cola.o: $(SRC)/Pila_max_Cola.cpp $(INC)/Pila_max_Cola.h $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/cola.o: $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/vectordinamico.o: $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/*

mrproper : clean
	-rm -r $(BIN)/* doc/html doc/latex doc/man
