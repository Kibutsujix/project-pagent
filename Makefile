CC = gcc
SRC = modules/functions.c modules/utilities.c modules/structdb.c
INC = include
BUILD = build
EXEC = structdb
CFLAGS = -Werror -Wall -Wextra -Wshadow -Wunused-parameter -I
LIBS = -lcrypt
CDIR = mkdir -p

build:
	$(CDIR) $(BUILD) && $(CC) $(CFLAGS) $(INC) $(SRC) -o $(BUILD)/$(EXEC) $(LIBS)
