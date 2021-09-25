OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Almacen.o Sala.o Inventario.o
	g++ -o program.exe program.o Sala.o Almacen.o Inventario.o $(OPCIONS) 
Almacen.o: Almacen.cc
	g++ -c Almacen.cc $(OPCIONS)
Inventario.o: Inventario.cc
	g++ -c Inventario.cc $(OPCIONS)
Sala.o: Sala.cc
	g++ -c Sala.cc $(OPCIONS)
program.o: program.cc
	g++ -c program.cc $(OPCIONS) 

clean:
	rm *.o
	rm *.exe
	rm *.tar
tar:
	tar -cvf practica.tar *.cc *.hh Makefile html
