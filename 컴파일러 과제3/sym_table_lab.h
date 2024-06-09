#pragma once
#include <stdbool.h>

#define SYM_TABLE_SIZE 100
#define HASH_TABLE_SIZE 11
#define MAX_STR_POOL 200
#define MAX_PARAMS 3

void init_sym_table();
void print_sym_table();
void print_hash_table();

typedef struct HTentry *HTpointer;
typedef struct HTentry
{
    int index;
    HTpointer next;
} HTentry;

HTpointer lookup_hash_table(char *sym, int hscode);

typedef enum
{
    NONE_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    DOUBLE_TYPE,
    VOID_TYPE,
    TYPE_COUNT // This should always be the last element
} Type;

typedef enum kind
{
    NONE, // NOT DECLARED
    SCALAR,
    ARRAY,
    FUNC,
    PARAM,
    KIND_COUNT

} Kind;

void update_symbol_kind(char *ident, Kind kind);
void update_symbol_type(char *ident, Type type);
void update_function_param(char *func_name, Type type);
bool is_declared(char *ident);

const char *str_var_types[TYPE_COUNT];
