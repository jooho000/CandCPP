#------------------------------------------------------------------------------
# Jooho Lee
# jlee897
# 2024 Winter CSE101 PA2
# Makefile
# Makefile for CSE 101 Programming Assignment 2
#
#       make        		   makes FindPath
#       make GraphTest         makes GraphTest
#       make checkFind        runs valgrind for FindPath
#       make checkTest         runs valgrind for GraphTest
#------------------------------------------------------------------------------

BASE_SOURCES   = Graph.c List.c
BASE_OBJECTS   = Graph.o List.o
HEADERS        = Graph.h List.h
COMPILE        = gcc -g -std=c17 -Wall -c
LINK           = gcc -std=c17 -Wall -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full

FindPath : FindPath.o $(BASE_OBJECTS)
	$(LINK) FindPath FindPath.o $(BASE_OBJECTS)

GraphTest : GraphTest.o $(BASE_OBJECTS)
	$(LINK) GraphTest GraphTest.o $(BASE_OBJECTS)

FindPath.o : FindPath.c $(HEADERS)
	$(COMPILE) FindPath.c

GraphTest.o : GraphTest.c $(HEADERS)
	$(COMPILE) GraphTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE) FindPath GraphTest FindPath.o GraphTest.o $(BASE_OBJECTS)

checkFind : FindPath
	$(MEMCHECK) ./FindPath inFile.txt outFile.txt

checkTest : GraphTest
	$(MEMCHECK) GraphTest