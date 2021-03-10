#
# CSF Assignment 3 Makefile
#

CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

csim: csim.o
	$(CC) -o csim csim.o

csim.o: csim.cpp csim.h
	$(CC) $(CFLAGS) -c csim.cpp

clean:
	rm -f *.s *.o *~ csim depend.mak
