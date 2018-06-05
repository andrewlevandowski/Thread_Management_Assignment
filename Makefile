###########################################################
# Makefile for CS570 Assignment #1
# Cody Morgan, Andrew Levandowski
###########################################################

CC = g++
CPPFILES = driver.cpp Threads.cpp
FLAG = -lpthread
EXEC = player

all:
	$(CC) $(CPPFILES) -o $(EXEC) $(FLAG)
	rm -f *.o

run: all
	./$(EXEC)

clean:
	rm -f *.o core a.out $(EXEC)

#######################[ EOF: Makefile ]###################
