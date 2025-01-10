CC = gcc
CFLAGS = -Wall -g
# include paths for header files
CFLAGS += -I$(COMPILER_DIR) -I$(COMPILER_DIR)/symbolTable
LEX = flex
YACC = bison

# Directories
COMPILER_DIR = compiler
SYMBOL_TABLE_DIR = $(COMPILER_DIR)/symbolTable
INTERMEDIATE_DIR = intermediate

# Source files
SRCS = $(INTERMEDIATE_DIR)/zsharp.tab.c $(INTERMEDIATE_DIR)/lex.yy.c $(SYMBOL_TABLE_DIR)/symbol_table.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = zsharp

$(shell mkdir -p $(INTERMEDIATE_DIR))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(INTERMEDIATE_DIR)/lex.yy.c: $(COMPILER_DIR)/zsharp.l
	$(LEX) -o $(INTERMEDIATE_DIR)/lex.yy.c $(COMPILER_DIR)/zsharp.l

$(INTERMEDIATE_DIR)/zsharp.tab.c $(INTERMEDIATE_DIR)/zsharp.tab.h: $(COMPILER_DIR)/zsharp.y
	$(YACC) -d -o $(INTERMEDIATE_DIR)/zsharp.tab.c $(COMPILER_DIR)/zsharp.y

# dependency for symbol table
$(SYMBOL_TABLE_DIR)/symbol_table.o: $(SYMBOL_TABLE_DIR)/symbol_table.c $(SYMBOL_TABLE_DIR)/symbol_table.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(INTERMEDIATE_DIR)/%.o: $(INTERMEDIATE_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS) $(INTERMEDIATE_DIR)/lex.yy.c $(INTERMEDIATE_DIR)/zsharp.tab.c $(INTERMEDIATE_DIR)/zsharp.tab.h
	rm -rf $(INTERMEDIATE_DIR)

.PHONY: all clean 