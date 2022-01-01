CC = gcc
WINCC = x86_64-w64-mingw32-gcc
SRC = modules/functions.c modules/utilities.c
L_MAIN = modules/l_structdb.c
W_MAIN = modules/w_structdb.c
INC = include
BUILD = build
EXEC = structdb
CFLAGS = -static -Werror -Wall -Wextra -Wshadow -Wunused-parameter -I
LIBS = -lcrypt
CDIR = mkdir -p

all: b_linux b_windows

b_linux:
	$(CDIR) $(BUILD) && $(CC) $(CFLAGS) $(INC) $(SRC) $(L_MAIN) -o $(BUILD)/$(EXEC)-linux-x86_64 $(LIBS)

b_windows:
	$(CDIR) $(BUILD) && $(WINCC) $(CFLAGS) $(INC) $(SRC) $(W_SRC) $(W_MAIN) -o $(BUILD)/$(EXEC)-windows-x86_64.exe
