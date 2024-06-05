#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sym_table_lab.h"
#include "hash_func.h"
#include "tn.h"
#include "parser.tab.h"

char separators[] = " ,;\t\n\r\n";
char str_pool[MAX_STR_POOL];
// sym_table 구조
// StringPoolIndex | Length | Line ( 과제 3에서는 Type 까지 저장! )

int sym_table[SYM_TABLE_SIZE][3];

#define isLetter(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_'))
#define isDigit(x) ((x) >= '0' && (x) <= '9')

HTpointer HT[HASH_TABLE_SIZE];

void init_sym_table()
{
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++)
    {
        sym_table[i][0] = -1;
        sym_table[i][1] = -1;
    }
}

void print_sym_table()
{
    int i;
    printf("\nSymbol Table\n");
    printf("Index\tStrPool\tLength\tLine\tSymbol\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++)
    {
        if (sym_table[i][0] != -1)
        {
            printf("[%d]\t%d\t%d\t%d\t%s\n", i, sym_table[i][0], sym_table[i][1], sym_table[i][2], str_pool + sym_table[i][0]);
        }
    }
}

HTpointer lookup_hash_table(char *sym, int hscode)
{
    HTpointer entry = HT[hscode];

    // ü�̴׵� ����Ʈ�� Ž��
    while (entry != NULL)
    {
        if (strcmp(str_pool + (sym_table[entry->index][0]), sym) == 0)
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

        strncpy(str_pool + str_pool_index, ident, MAX_STR_POOL); // string pool 에 iden

        add_hash_table(sym_table_index, hash_value);

        // 2차원 배열 형태로 sym table 구성 -> string pool index, length, line_number

        sym_table[sym_table_index][0] = str_pool_index;
        sym_table[sym_table_index][1] = len;
        sym_table[sym_table_index++][2] = lineNumber;

        str_pool[str_pool_index + len] = '\0';
        str_pool_index += len + 1;
    }
}
