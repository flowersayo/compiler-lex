#include <stdio.h>
#include <string.h> // strcmp
#include <stdlib.h> // malloc
#include "tn.h"
#define MAXIDENTLEN 100
#define SYM_TABLE_SIZE 100
#define HASH_TABLE_SIZE 13 // 소수를 많이 활용

typedef struct HTentry *HTpointer;

const char *get_type(Tnumber num);

int sym_index = 0; // sym table 에 새로운 항목을 추가할 때 사용되는 인덱스

typedef struct Symbol
{
    Tnumber tnumber; // 토큰 타입
    int line_number;
    int st_idx;      // identifier 인 경우 string pool 의 idx
    char *token_str; // identifier 제외 토큰 문자열
} Symbol;

Symbol SymbolTable[SYM_TABLE_SIZE];

typedef struct HTentry
{
    int index; // symbol table 의 index
    HTpointer next;
} HTentry;

HTpointer HT[HASH_TABLE_SIZE]; // 해시테이블

// symbol table 초기화
void init_sym_table()
{
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++)
    {
        SymbolTable[i].line_number = -1;
        SymbolTable[i].st_idx = -1;
        SymbolTable[i].token_str = NULL;
    }
}

// 해시값 계산
int computeHS(char *key, int tableSize)
{
    unsigned int hash_key = 0;
    int c;
    while ((c = *key++))
    {
        hash_key += c;
    }
    return hash_key % tableSize;
}

// 해시 테이블에 토큰이 이미 존재하는지 확인
HTpointer lookupHT(char *token, int hscode)
{

    HTpointer entry = HT[hscode];

    while (entry != NULL)
    {
        if (strcmp(token, SymbolTable[entry->index].token_str) == 0)
        { // 동일하면 0반환
            return entry;
        }

        entry = entry->next;
    }
    return NULL;
}

// 해시테이블에 토큰 추가하기
void addHT(char *token, int hscode)
{
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));

    if (newEntry == NULL)
    {
        printf("메모리 할당 실패 \n");
        exit(1);
    }

    newEntry->index = sym_index - 1; // 심볼 테이블에 저장하고 나서 sym_idx 를 하나 증가시켰으므로 토큰에 대한 심볼 테이블의 인덱스는 -1 해주어야한다.
    newEntry->next = NULL;

    if (HT[hscode] == NULL)
    {
        HT[hscode] = newEntry;
    }
    else
    {
        // 전위법
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

void addSymbolTable(char *token, Tnumber tnumber)
{

    SymbolTable[sym_index].line_number = -1; // TODO line number 구별하기
    SymbolTable[sym_index].st_idx = -1;      // TODO identifier의 경우에는 token_str 대신에 string pool에 저장하기
    SymbolTable[sym_index].token_str = token;
    SymbolTable[sym_index].tnumber = tnumber;
}

// symbol table 에 존재하는지 여부에 따라서 토큰을 저장하는 함수
int symtable(char *token, Tnumber tnumber)
{
    // 해당 토큰의 해시 값 구하기
    int hash_value = computeHS(token, HASH_TABLE_SIZE);
    HTpointer htp = lookupHT(token, hash_value);

    if (htp == NULL)
    { // 동일한 토큰이 없는 경우
        addSymbolTable(token, tnumber);
        sym_index++;
        addHT(token, hash_value);

        return sym_index - 1; // 직전 토큰이 저장된 인덱스
    }
    else
    { // 동일한 토큰이 이미 있는 경우

        printf("%s (Already exists. Hash: %d)\n", token, hash_value);
        return htp->index; // 그 토큰이 저장된 심볼테이블의 인덱스
    }
}

void print_sym_table()
{
    int i;
    printf("\n=== SYMBOL TABLE ===\n\n");
    printf("Line number\tToken type\tST-index\ttoken\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++)
    {
        if (SymbolTable[i].tnumber != -1)
        {
            printf("%d\t%s\t%d\t%s\n", SymbolTable[i].line_number, get_type(SymbolTable[i].tnumber), SymbolTable[i].st_idx, SymbolTable[i].token_str);
        }
    }
}

const char *get_type(Tnumber num)
{
    switch (num)
    {
    case TEOF:
        return "TEOF";
    case TCONST:
        return "TCONST";
    case TELSE:
        return "TELSE";
    case TIF:
        return "TIF";
    case TINT:
        return "TINT";
    case TRETURN:
        return "TRETURN";
    case TVOID:
        return "TVOID";
    case TWHILE:
        return "TWHILE";
    case TEQUAL:
        return "TEQUAL";
    case TNOTEQU:
        return "TNOTEQU";
    case TLESSE:
        return "TLESSE";
    case TGREATE:
        return "TGREATE";
    case TAND:
        return "TAND";
    case TOR:
        return "TOR";
    case TINC:
        return "TINC";
    case TDEC:
        return "TDEC";
    case TADDASSIGN:
        return "TADDASSIGN";
    case TSUBASSIGN:
        return "TSUBASSIGN";
    case TMULASSIGN:
        return "TMULASSIGN";
    case TDIVASSIGN:
        return "TDIVASSIGN";
    case TMODASSIGN:
        return "TMODASSIGN";
    case TEXCLAM:
        return "TEXCLAM";
    case TMOD:
        return "TMOD";
    case TLPAREN:
        return "TLPAREN";
    case TRPAREN:
        return "TRPAREN";
    case TSTAR:
        return "TSTAR";
    case TPLUS:
        return "TPLUS";
    case TCOMMA:
        return "TCOMMA";
    case TMINUS:
        return "TMINUS";
    case TDIV:
        return "TDIV";
    case TSEMICOLON:
        return "TSEMICOLON";
    case TLESS:
        return "TLESS";
    case TEQUALS:
        return "TEQUALS";
    case TGREATER:
        return "TGREATER";
    case TLBRACKET:
        return "TLBRACKET";
    case TRBRACKET:
        return "TRBRACKET";
    case TLBRACE:
        return "TLBRACE";
    case TRBRACE:
        return "TRBRACE";
    case TASSIGN:
        return "TASSIGN";
    case TIDENT:
        return "TIDENT";
    case TINTEGER:
        return "TINTEGER";
    case TFLOAT:
        return "TFLOAT";
    case TERROR:
        return "TERROR";
    default:
        return "UNKNOWN";
    }
}