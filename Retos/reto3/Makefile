CPPFLAGS = -std=c++11 -Wall -g -c

all: teststack.out

teststack.out: teststack.o Stack_List.o
	g++ -o $@ $<

teststack.o: teststack.cpp Stack_List.h
	g++ $(CPPFLAGS) -o $@ $<

Stack_List.o: Stack_List.h Stack_List.cpp
	g++ $(CPPFLAGS) -o $@ $<

clean: 
	-rm *.o

mrproper: clean
	-rm teststack.out
