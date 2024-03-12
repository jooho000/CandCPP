#------------------------------------------------------------------------------
# Jooho Lee
# jlee897
# 2024 Winter CSE101 PA8
# Makefile
# Makefile for CSE 101 Programming Assignment 8
#
#  make                     makes Order
#  make WordFrequency       makes WordFrequency
#  make DictionaryTest      makes DictionaryTest
#  make clean               removes all binaries
#  make OrderCheck          runs Order under valgrind on in5 junk5
#  make WordFrequencyCheck  runs WordFrequency under valgrind on in5 junk5
#  make DictionaryCheck     runs DictionaryClient under valgrind
#------------------------------------------------------------------------------

MAIN           = Order
MAIN2          = WordFrequency
ADT            = Dictionary
SOURCE         = $(MAIN).cpp
OBJECT         = $(MAIN).o
OBJECT2        = $(MAIN2).o
ADT_TEST       = $(ADT)Test
ADT_SOURCE     = $(ADT).cpp
ADT_OBJECT     = $(ADT).o
ADT_HEADER     = $(ADT).h
COMPILE        = g++ -std=c++17 -g -Wall -c
LINK           = g++ -std=c++17 -g -Wall -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full

$(MAIN): $(OBJECT) $(ADT_OBJECT)
	$(LINK) $(MAIN) $(OBJECT) $(ADT_OBJECT)

$(MAIN2): $(OBJECT2) $(ADT_OBJECT)
	$(LINK) $(MAIN2) $(OBJECT2) $(ADT_OBJECT)

$(ADT_TEST): $(ADT_TEST).o $(ADT_OBJECT)
	$(LINK) $(ADT_TEST) $(ADT_TEST).o $(ADT_OBJECT)

$(OBJECT): $(SOURCE) $(ADT_HEADER)
	$(COMPILE) $(SOURCE)

$(ADT_TEST).o: $(ADT_TEST).cpp $(ADT_HEADER)
	$(COMPILE) $(ADT_TEST).cpp

$(ADT_OBJECT): $(ADT_SOURCE) $(ADT_HEADER)
	$(COMPILE) $(ADT_SOURCE)

clean:
	$(REMOVE) $(MAIN) $(MAIN2) $(ADT_TEST) $(OBJECT) $(OBJECT2) $(ADT_TEST).o $(ADT_OBJECT)

$(MAIN)Check: $(MAIN)
	$(MEMCHECK) $(MAIN) testinput.txt testout.txt

$(MAIN2)Check: $(MAIN2)
	$(MEMCHECK) $(MAIN2) testinput.txt testout.txt

$(ADT)Check: $(ADT_TEST)
	$(MEMCHECK) ./$(ADT_TEST)
