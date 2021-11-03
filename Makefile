exec:	main.o
	g++ -std=c++17 main.o -o exec
	
main.o:	src/main.cpp
	g++ -std=c++17 src/main.cpp -c -Wall
