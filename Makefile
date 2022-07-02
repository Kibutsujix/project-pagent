CC = gcc
SRC = src/functions.c src/sha256.c src/structdb.c src/utilities.c
DIR = build
MKDIR = $(shell test -d $(DIR) || mkdir $(DIR))
EXEC = structdb
CFLAGS = \
		-s -static -Os \
		-Wall -Wextra -Wpedantic -Wshadow -Werror \
		-Wno-unused-result -Wbad-function-cast -Wcast-align \
		-Wundef -Wpointer-arith -funroll-loops

ifeq ($(OS), Windows_NT)
	EXEC +=-windows-$(PROCESSOR_ARCHITECTURE)
else
	EXEC +=-$(shell uname -s)-$(shell uname -p)
	LIBS =-lcrypt
endif

BUILD = $(shell echo $(EXEC) | tr 'A-Z' 'a-z' | tr -d " ")

build:
	$(MKDIR)
	$(CC) $(CFLAGS) $(SRC) -o $(DIR)/$(BUILD) $(LIBS)

clean:
	rm -rf $(DIR)
