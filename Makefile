CC = clang
CFLAGS = -Wall -Wextra -g -Iinclude -I./include
LDFLAGS = -Llib -lraylib -Wl,-rpath=./lib
TARGET = build/main
SRC = src/main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
