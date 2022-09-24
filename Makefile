BIN := way_home


BIN_TARGET := WAY_HOME



.PHONY = all clean uninstall reinstall

CC = clang -std=c11 -Wall -Wextra -Werror -Wpedantic #compiler

SOURCE := $(wildcard src/*.c)

HEAD := $(wildcard inc/*.h)

OBJECTS := $(notdir $(SOURCE:.c=.o))

all: $(BIN_TARGET) 

$(BIN_TARGET): $(SOURCE) $(HEAD)
	mkdir -p obj 
	$(CC) -c $(SOURCE)
	mv $(OBJECTS) ./obj
	$(CC) -o $(BIN) $(addprefix obj/, $(OBJECTS))


uninstall: clean
	rm -f $(BIN)

clean:
	rm -drf obj
	rm -f $(wildcard *.o)

reinstall: $(BIN_TARGET)
