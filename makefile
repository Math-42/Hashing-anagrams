all: update sources/hash.o sources/hash.h main.o
	@gcc sources/hash.o main.o -o exec
update:
	@rm -f sources/hash.o main.o exec
hash.o:
	@gcc -c sources/hash.c
main.o:
	@gcc -c main.c
debug:
	@gcc sources/hash.c main.c -g
leak:
	@clear && gcc sources/hash.c main.c -o exec && valgrind --leak-check=yes ./exec
run:
	@./exec