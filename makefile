all: update sources/hash.o sources/hash.h sources/lista.o sources/lista.h main.o
	@gcc sources/hash.o sources/lista.o main.o -o exec
update:
	@rm -f sources/hash.o sources/lista.o main.o exec
hash.o:
	@gcc -c sources/hash.c
lista.o:
	@gcc -c sources/lista.c
main.o:
	@gcc -c main.c
debug:
	@gcc sources/lista.c sources/hash.c main.c -g
leak:
	@clear && gcc sources/lista.c sources/hash.c main.c -o exec && valgrind --leak-check=yes ./exec
run:
	@./exec