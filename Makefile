CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRC = src/main.c
OUT = main

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)
