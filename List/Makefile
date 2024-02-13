#------------------------------------------------------------------------------
# Makefile for CSE 101 Programming Assignment 1
#
#       make                   makes Lex
#       make ListTest          makes ListTest
#       make check             runs valgrind to check for memory errors
#       make checkTest         runs valgrind to check mem error in test
#------------------------------------------------------------------------------

Lex : Lex.o List.o
	gcc -g -o Lex Lex.o List.o

Lex.o : Lex.c List.h
	gcc -g -c -std=c17 -Wall Lex.c

ListTest: ListTest.o List.o
	gcc -g -std=c17 -o ListTest ListTest.o List.o

ListTest.o : ListTest.c List.h
	gcc -g -c -std=c17 -Wall ListTest.c

List.o : List.c List.h
	gcc -g -c -std=c17 -Wall List.c

clean :
	rm -f Lex ListTest Lex.o ListTest.o List.o

check : Lex
	valgrind --leak-check=full ./Lex inTest1.txt outText1.txt

checkTest : ListTest
	valgrind --leak-check=full ./ListTest