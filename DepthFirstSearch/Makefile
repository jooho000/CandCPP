#------------------------------------------------------------------------------
# Jooho Lee
# jlee897
# 2024 Winter CSE101 PA3
# Makefile
# Makefile for CSE 101 Programming Assignment 3
#
#       make        		   makes FindComponents
#       make GraphTest         makes GraphTest
#       make checkFind         runs valgrind for FindComponents
#       make checkTest         runs valgrind for GraphTest
#       make clean             removes unwanted files
#------------------------------------------------------------------------------

BASE_SOURCES   = Graph.c List.c
BASE_OBJECTS   = Graph.o List.o
HEADERS        = Graph.h List.h
COMPILE        = gcc -g -std=c17 -Wall -c
LINK           = gcc -std=c17 -Wall -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full -s

FindComponents : FindComponents.o $(BASE_OBJECTS)
	$(LINK) FindComponents FindComponents.o $(BASE_OBJECTS)

GraphTest : GraphTest.o $(BASE_OBJECTS)
	$(LINK) GraphTest GraphTest.o $(BASE_OBJECTS)

FindComponents.o : FindComponents.c $(HEADERS)
	$(COMPILE) FindComponents.c

GraphTest.o : GraphTest.c $(HEADERS)
	$(COMPILE) GraphTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) FindComponents GraphTest FindComponents.o GraphTest.o $(BASE_OBJECTS)

checkFind : FindComponents
	$(MEMCHECK) ./FindComponents inFile.txt outFile.txt

checkTest : GraphTest
	$(MEMCHECK) ./GraphTest