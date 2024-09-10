SRC_DIR = src
BIN_DIR = bin
CC = gcc
CFLAGS = -Wall 


SRC_FILES = $(SRC_DIR)/time.c $(SRC_DIR)/part02_shared.c $(SRC_DIR)/part02_pipe.c

BIN_FILES = $(BIN_DIR)/time $(BIN_DIR)/part02_shared $(BIN_DIR)/part02_pipe

all: $(BIN_FILES)

$(BIN_DIR)/time: $(SRC_DIR)/time.c
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/part02_shared: $(SRC_DIR)/part02_shared.c
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR)/part02_pipe: $(SRC_DIR)/part02_pipe.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN_FILES)

phony: all clean