.PHONY:clean all
CC=g++
CFLAGS=-Wall -g
BIN=linkList
all:$(BIN)
%.o:%.cpp
	$(CC) $(CFLAGS) _-c_$< -o $@
clean:
	rm -f *.o $(BIN)