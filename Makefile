CC = gcc
CFLAGS = -Wall -I./include
SRC_DIR = ./src
EXEC = ./quiz-system

# List of all source files
SRCS = $(SRC_DIR)/config.c $(SRC_DIR)/file_manager.c $(SRC_DIR)/main.c $(SRC_DIR)/quiz.c

# Corresponding object files (directly in the root directory)
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: clean
