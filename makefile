CC=gcc
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS= -Wall -g

all: progmain main.o myBank.o
progmain: $(OBJECTS_LIB) $(OBJECTS_MAIN)
	$(CC) $(FLAGS) $(OBJECTS_MAIN) $(OBJECTS_LIB) -o progmain
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c 
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c

.PHONY: all clean

clean:
	rm -f *.o progmain