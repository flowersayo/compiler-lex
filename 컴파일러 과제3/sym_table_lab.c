#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sym_table_lab.h"
#include "hash_func.h"
#include "tn.h"
#include "parser_tab.h"

char separators[] = " ,;\t\n\r\n";
char str_pool[MAX_STR_POOL];

// sym_table 구조
typedef struct symbol
{

    Kind kind;               // ident 의 유형
    Type type;               // 변수일 경우 변수 타입, 함수일 경우 리턴 타입
    Type params[MAX_PARAMS]; // 함수일경우 파라미터 목록 저장 (sym table 의 idx)
    int param_cnt;
    int st_idx; // stringpool index
    int length;
    int line;
} Symbol;

#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_'))
#define isDigit(x) ((x) >= '0' && (x) <= '9')

HTpointer HT[HASH_TABLE_SIZE];
Symbol *sym_table[SYM_TABLE_SIZE]; // 메모리 동적 할당

const char *str_var_types[TYPE_COUNT] = {
    "none",
    "int",
    "float",
    "char",
    "double",
    "void",
    "type_cnt"};

const char *str_kind[KIND_COUNT] = {
    "none",
    "scalar",
    "array",
    "func",
    "param",
};

// Function to get the enum value from the string
int get_type_from_str(const char *type_str)
{
    for (int i = 0; i < TYPE_COUNT; i++)
    {
        if (strcmp(type_str, str_var_types[i]) == 0)
        {
            return i;
        }
    }
    return -1; // Return an invalid type
}

void init_sym_table()
{
    for (int i = 0; i < SYM_TABLE_SIZE; i++)
    {
        sym_table[i] = NULL;
    }
}

void print_sym_table()
{

    printf("\nSymbol Table\n");
    printf("%s\t%s\t%s\t%-10s\t%s\t%s\t%s\t%s\n",
           "Index", "STidx", "Length", "Symbol", "Kind", "Type", "Line", "Params");

    for (int i = 0; i < SYM_TABLE_SIZE; i++)
    {

        if (sym_table[i] == NULL)
        {
            break;
        }

        printf("[%d]\t%d\t%d\t%-10s\t%s\t%s\t%d\t",
               i,
               sym_table[i]->st_idx,
               sym_table[i]->length,
               str_pool + sym_table[i]->st_idx,
               str_kind[sym_table[i]->kind],
               str_var_types[sym_table[i]->type],
               sym_table[i]->line);

        // 함수일 경우 매개변수 출력하기
        int j = 0;
        while (j < sym_table[i]->param_cnt)
        {
            printf("%s ", str_var_types[sym_table[i]->params[j]]);
            j++;
        }

        printf("\n");
    }
}

HTpointer lookup_hash_table(char *sym, int hscode)
{
    HTpointer entry = HT[hscode];

    // ü�̴׵� ����Ʈ�� Ž��
    while (entry != NULL)
    {
        if (strcmp(str_pool + (sym_table[entry->index]->st_idx), sym) == 0)
        {
            return entry; // ã�� �׸� ��ȯ
        }
        entry = entry->next;
    }
    return NULL; // �׸��� ã�� ���� ���
}

void add_hash_table(int id_index, int hscode)
{
    // �� �׸� ���� �� �ʱ�ȭ
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL)
    {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    newEntry->index = id_index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL)
    {
        // ù ��° �׸����� �߰�
        HT[hscode] = newEntry;
    }
    else
    {
        // �̹� �׸��� ������, ����Ʈ�� �� �տ� �߰�
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

void print_hash_table()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        HTpointer entry = HT[i];
        if (entry != NULL)
        {
            printf("[%d]: ", i);
            while (entry != NULL)
            {
                printf("%d -> ", entry->index);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}

int sym_table_index = 0;
int str_pool_index = 0;
void SymbolTable(char *ident, int len)
{
    int hash_value = 0;

    if (str_pool_index + len > MAX_STR_POOL)
    {
        // 해시계산
        // 중복된 식별자 존재할 경우 게속 진행
        // 중복된 식별자가 존재하지 않을 경우는 오버플로우 오류 발생시키고 오류

        hash_value = divisionMethod(ident, HASH_TABLE_SIZE);

        HTpointer htp = lookup_hash_table(ident, hash_value);

        // 다만 이미 심볼테이블에 존재하는 identifier 의 경우에는 오류가 아니고 다음 토큰으로 넘어간다.
        if (htp == NULL)
        {
            ReportError(overst);
            printf("String pool overflow\n");
            print_sym_table();
            print_hash_table();
            exit(0);
        }
        return;
    }

    hash_value = divisionMethod(ident, HASH_TABLE_SIZE);

    HTpointer htp = lookup_hash_table(ident, hash_value);
    if (htp == NULL)
    {
        if (sym_table_index == SYM_TABLE_SIZE) // 오버플로우가 발생 (더이상 symtable에 저장할 공간 x)
        {
            ReportError(overst);
            printf("Symbol Table overflow\n");
            print_sym_table();
            print_hash_table();
            exit(0);
        }

        strncpy(str_pool + str_pool_index, ident, len); // string pool 에 iden

        add_hash_table(sym_table_index, hash_value);

        sym_table[sym_table_index] = malloc(sizeof(Symbol)); // 동적할당

        if (sym_table[sym_table_index] == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        sym_table[sym_table_index]->kind = NONE;
        sym_table[sym_table_index]->type = NONE_TYPE;
        sym_table[sym_table_index]->st_idx = str_pool_index;
        sym_table[sym_table_index]->length = len;
        sym_table[sym_table_index]->param_cnt = 0;

        sym_table[sym_table_index++]
            ->line = lineNumber;

        str_pool[str_pool_index + len] = '\0';
        str_pool_index += len + 1;
    }
}

void update_symbol_kind(char *ident, Kind kind)
{

    printf("%s %d", ident, kind);

    int hash_value = divisionMethod(ident, HASH_TABLE_SIZE);

    HTpointer htp = lookup_hash_table(ident, hash_value);

    if (htp != NULL)
    {
        sym_table[htp->index]->kind = kind;
    }
}

void update_symbol_type(char *ident, Type type)
{

    int hash_value = divisionMethod(ident, HASH_TABLE_SIZE);

    HTpointer htp = lookup_hash_table(ident, hash_value);

    if (htp != NULL)
    {

        sym_table[htp->index]->type = type;
    }
}

void update_function_param(char *func_name, Type type)
{

    printf("update_function_param");

    int func_hash_value = divisionMethod(func_name, HASH_TABLE_SIZE);

    HTpointer func_htp = lookup_hash_table(func_name, func_hash_value);

    if (func_htp != NULL)
    {

        int idx = sym_table[func_htp->index]->param_cnt; // 파라미터 개수
        sym_table[func_htp->index]->params[idx] = type;  // 함수 파라미터 하나 추가
        sym_table[func_htp->index]->param_cnt++;         // 파라미터 개수 1 증가
    }
}
