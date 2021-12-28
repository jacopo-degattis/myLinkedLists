exec:	main.o lib/linkedlist/linkedlist.o
	g++ -std=c++17 main.o linkedlist.o -o exec
	rm linkedlist.o main.o

main.o:	src/main.cpp
	g++ -std=c++17 src/main.cpp -c -Wall

lib/linkedlist/linkedlist.o:	src/lib/linkedlist/linkedlist.cpp
	g++ -std=c++17 src/lib/linkedlist/linkedlist.cpp -c -Wall
