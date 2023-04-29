main: main.o graph.o ldd.o
	g++ -o  main main.o graph.o ldd.o

main.o: ../src/main.cpp ../src/graph.h 
	g++ -c -g ../src/main.cpp

graph.o: ../src/graph.cpp ../src/graph.h 
	g++ -c -g ../src/graph.cpp 

ldd.o: ../src/ldd.cpp ../src/ldd.h ../src/graph.h 
	g++ -c -g ../src/ldd.cpp

