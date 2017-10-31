SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h $(INC)/vectordinamico.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libcrono.a: $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o $(OBJ)/vectordinamico.o
	ar -rvs $@ $^

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/vectordinamico.o: $(INC)/vectordinamico.h $(SRC)/vectordinamico.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/*

mrproper : clean
	-rm -r $(BIN)/* doc/html doc/latex doc/man
