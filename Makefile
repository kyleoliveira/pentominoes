pentominoes.out: pentominoes.o
	g++ -Wall -ansi -g -o pentominoes.out pentominoes.o
pentominoes.o: pentominoes.cpp
	g++ -Wall -ansi -g -c pentominoes.cpp
clean: 
	rm -f pentominoes.out pentominoes.o core
