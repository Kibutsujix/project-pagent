CC = gcc
WINCC = x86_64-w64-mingw32-gcc
SRC = modules/functions.c modules/utilities.c
LNXBLD = modules/structdb-lnx.c
WINBLD = modules/structdb-win.c
INC = include/
BUILD = build
EXEC = structdb
CFLAGS = -static -Werror -Wall -Wextra -Wshadow -Wunused-parameter -I
LIBS = -lcrypt
CDIR = mkdir -p

all: linux mingw-win

linux:
	$(CDIR) $(BUILD) && $(CC) $(CFLAGS) $(INC) $(SRC) $(LNXBLD) -o $(BUILD)/$(EXEC)-linux-x86_64 $(LIBS)

mingw-win:
	$(CDIR) $(BUILD) && $(WINCC) $(CFLAGS) $(INC) $(SRC) $(WINBLD) -o $(BUILD)/$(EXEC)-windows-x86_64.exe

windows:
	$(WINCC) $(CFLAGS) $(INC) $(SRC) $(WINBLD) -o $(EXEC)-windows-x86_64.exe
