exec:	main.o lib/linkedlist/linkedlist.o
	g++ main.o linkedlist.o -o exec
	rm linkedlist.o main.o

main.o:	src/main.cpp
	g++ src/main.cpp -c -Wall

lib/linkedlist/linkedlist.o:	src/lib/linkedlist/linkedlist.cpp
	g++ src/lib/linkedlist/linkedlist.cpp -c -Wall