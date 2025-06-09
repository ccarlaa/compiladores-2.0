# Configurações
CC := gcc
FLEX := flex
BISON := bison
CFLAGS := -Iinclude -Wall
LDFLAGS := -lfl

BUILD_DIR := build
SRC_DIR := src
LEXER_SRC := lexer/lexer.l
PARSER_SRC := parser/parser.y

EXEC := c_to_portugol

# Garante que o diretório build existe
$(shell mkdir -p $(BUILD_DIR))

# Arquivos objeto
OBJS := $(BUILD_DIR)/main.o $(BUILD_DIR)/conversor.o \
        $(BUILD_DIR)/lex.yy.o $(BUILD_DIR)/parser.tab.o

# Regra principal
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Geração do parser
$(BUILD_DIR)/parser.tab.c $(BUILD_DIR)/parser.tab.h: $(PARSER_SRC)
	@echo "Gerando parser..."
	$(BISON) -d -o $(BUILD_DIR)/parser.tab.c $<

# Geração do lexer
$(BUILD_DIR)/lex.yy.c: $(LEXER_SRC) $(BUILD_DIR)/parser.tab.h
	@echo "Gerando lexer..."
	$(FLEX) -o $@ $<

# Regras para objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(EXEC)

.PHONY: all clean