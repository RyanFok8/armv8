#include "assembler_symbol_table.h"

static symbol* symbol_table;
static int symbol_table_size;
static int allocated_size;

void initialise_symbol_table(void) {
    allocated_size = INITIAL_SYMBOL_TABLE_SIZE;
    symbol_table = malloc(allocated_size);
    symbol_table_size = 0;
}

void free_symbol_table(void) {
    for (int i = 0; i < symbol_table_size; i++) {
        free(symbol_table[i].label);
    }
    free(symbol_table);
}

void add_item(char* label, int address) {
    if (symbol_table_size >= allocated_size) {
        allocated_size += INITIAL_SYMBOL_TABLE_SIZE;
        symbol_table = realloc(symbol_table, allocated_size);
    }

    symbol_table[symbol_table_size].label = strdup(label);
    symbol_table[symbol_table_size].address = address;
    symbol_table_size++;
}

int find_address(char *label) {
  for (int i = 0; i < symbol_table_size; i++) {
    if (strcmp(symbol_table[i].label, label) == 0) {
      return symbol_table[i].address;
    }
  }

  return -1;
}
