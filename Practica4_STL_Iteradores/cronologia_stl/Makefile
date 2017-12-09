SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -std=c++17 -I$(INC) -c


all: $(BIN)/pruebacronologia $(BIN)/unionCronologias $(BIN)/estadisticaEventos $(BIN)/filtradoIntervalo $(BIN)/filtradoPalabraClave
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(BIN)/unionCronologias: $(OBJ)/unionCronologias.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(BIN)/estadisticaEventos: $(OBJ)/estadisticaEventos.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(BIN)/filtradoIntervalo: $(OBJ)/filtradoIntervalo.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(BIN)/filtradoPalabraClave: $(OBJ)/filtradoPalabraClave.o $(LIB)/libcrono.a
	$(CXX) -o $@ $< -lcrono -L$(LIB)

$(OBJ)/pruebacronologia.o: $(SRC)/pruebacronologia.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/unionCronologias.o: $(SRC)/unionCronologias.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/estadisticaEventos.o: $(SRC)/estadisticaEventos.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/filtradoIntervalo.o: $(SRC)/filtradoIntervalo.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/filtradoPalabraClave.o: $(SRC)/filtradoPalabraClave.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libcrono.a: $(OBJ)/cronologia.o $(OBJ)/fechahistorica.o
	ar -rvs $@ $^

$(OBJ)/cronologia.o: $(SRC)/cronologia.cpp $(INC)/cronologia.h $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/fechahistorica.o: $(SRC)/fechahistorica.cpp $(INC)/fechahistorica.h
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/*

mrproper : clean
	-rm -r $(BIN)/* doc/html doc/latex doc/man
