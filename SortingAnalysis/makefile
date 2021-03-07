# Project: 202hw1
# Makefile created by Dev-C++ 5.11

CC=g++
CFLAGS=-c -Wall

all: do

do: sorting.o main.o
	$(CC) sorting.o main.o -o hw1

sorting.o: sorting.cpp
	$(CC) $(CFLAGS) sorting.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *o hw1