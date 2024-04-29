#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "STMain.h"
#include "HashFunc.h"
#include "HashFunc.c" // 이부분 window 에서는 제거
#include <ctype.h>
#include <stdbool.h>

char separators[] = " ,;\t\n\r\n";
char str_pool[20]; // 
int sym_table[SYM_TABLE_SIZE][2];

typedef struct HTentry *HTpointer;

typedef struct HTentry
{
    int index;
    HTpointer next;
} HTentry;

HTpointer HT[HASH_TABLE_SIZE];

HTpointer lookup_hash_table(int id_index, int hscode)
{
    HTpointer entry = HT[hscode];
    while (entry != NULL)
    {
        // 새롭게 sym_table 에 저장된 identifier 가 hash table 에 이미 존재하는지 확인
        if (strcmp(str_pool + sym_table[entry->index][0], str_pool + sym_table[id_index][0]) == 0)
        {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

void add_hash_table(int id_index, int hscode)
{

    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL)
    {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newEntry->index = id_index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL)
    {
        HT[hscode] = newEntry;
    }
    else
    {
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

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
    printf("\n=== SYMBOL TABLE ===\n\n");
    printf("Index\tLength\tSymbol\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++)
    {
        if (sym_table[i][0] != -1)
        {
            printf("%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], str_pool + sym_table[i][0]);
        }
    }
}

void print_hash_table()
{
    printf("\n=== HASH TABLE ===\n\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {

        HTpointer entry = HT[i];

        if (entry)
        {
            printf("[%d]: ", i);
            while (entry != NULL)
            {

                printf("%d -> ", sym_table[entry->index][0]);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}

bool isValid(int start, int next)
{
    for (int idx = start; idx < next; idx++)
    {
        char cur_char = str_pool[idx];
        if (!(isdigit(cur_char) || isalpha(cur_char) || cur_char == '_'))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FILE *fp;
    int result;
    int c;
    int index_start = 0;
    int index_next = 0;
    int index = 0;
    int hash_value = -1;

    init_sym_table();
/*

    result = fopen_s(&fp, "example.txt", "r");
    if (result != 0)
    {
        printf("파일 열기 실패(%d)\n", result);
        return -1;
    }
    */
 

    
    char test_data[] = "abc$ ghj^";


    for (int i = 0; i < strlen(test_data); ++i) {
        c = test_data[i];

        // string pool 의 마지막 인덱스에 도달했는데 그 문자가 구분자가 아닌 경우
        if (strchr(separators, c) == NULL && index_next >= sizeof(str_pool) - 1) // string pool 이 꽉차면
        {
            printf("Error - string buffer over flow (MAX_SIZE : %lu)", sizeof(str_pool));
            index_next = index_start; // 유효한 식별자로 인식되어 sym_table 에 등록되지 않도록
            break;
        }

        if (strchr(separators, c) != NULL) // 구분자이면
        {

            if (index_start < index_next)
            {

                str_pool[index_next] = '\0';

                if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9')
                {
                    printf("Error - start with digit (%s)\n", str_pool + index_start);
                    index_next = index_start; // 버퍼 초기화
                }

                else if (!isValid(index_start, index_next))
                { 

                    printf("Error - contains invalid character. other than English letters (both uppercase and lowercase), underscores, digits, and delimiters(%s)\n", str_pool + index_start);
                    index_next = index_start;
                }
                else if ((index_next - index_start) > 15)
                {
                    printf("Error - Identifier too long (%s)\n", str_pool + index_start);
                    index_next = index_start;
                }
                else
                {

                    int i = 0;
                    int hash_key = 0;
                    sym_table[index][0] = index_start;
                    sym_table[index++][1] = (int)strlen(str_pool + index_start);

                    while (str_pool[index_start + i] != '\0')
                    {
                        hash_key += str_pool[index_start + i++];
                    }

                    hash_value = divisionMethod(hash_key, HASH_TABLE_SIZE);

                    HTpointer htp = lookup_hash_table(index - 1, hash_value);
                    if (htp == NULL)
                    {
                        add_hash_table(index - 1, hash_value);
                        printf("%s (Hash: %d)\n", str_pool + sym_table[index - 1][0], hash_value);
                        index_start = ++index_next;
                    }
                    else
                    {
                        printf("%s (Already exists. Hash: %d , index: %d , length : %d )\n", str_pool + sym_table[htp->index][0], hash_value, sym_table[htp->index][0], sym_table[htp->index][1]);
                        index_next = index_start; // string pool 에서도 중복된 식별자 제거

                        // symbol table 에 중복된 식별자 제거
                        index--;
                        sym_table[index][0] = -1;
                        sym_table[index][1] = -1;


                    }
                }
            }

            continue;
        }

        str_pool[index_next++] = (char)c;
    }


    if (index_start < index_next)
    {

        if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9')
                {
                    printf("Error - start with digit (%s)\n", str_pool + index_start);
                    index_next = index_start; // 버퍼 초기화
                }

                else if (!isValid(index_start, index_next))
                { 

                    printf("Error - contains invalid character. other than English letters (both uppercase and lowercase), underscores, digits, and delimiters(%s)\n", str_pool + index_start);
                    index_next = index_start;
                }
                else if ((index_next - index_start) > 15)
                {
                    printf("Error - Identifier too long (%s)\n", str_pool + index_start);
                    index_next = index_start;
                }
                else
                {
        int i = 0;
        int hash_key = 0;

        str_pool[index_next] = '\0';
        sym_table[index][0] = index_start;
        sym_table[index++][1] = (int)strlen(str_pool + index_start);

        while (str_pool[index_start + i] != '\0')
        {
            hash_key += str_pool[index_start + i++];
        }
        hash_value = divisionMethod(hash_key, HASH_TABLE_SIZE);

        HTpointer htp = lookup_hash_table(index - 1, hash_value);
        if (htp == NULL)
        {
            add_hash_table(index - 1, hash_value);
            printf("%s (Hash: %d)\n", str_pool + sym_table[index - 1][0], hash_value);
        }
        else
        {
            printf("%s (Already exists. Hash: %d , index: %d , length : %d )\n", str_pool + sym_table[htp->index][0], hash_value, sym_table[htp->index][0], sym_table[htp->index][1]);
              index_next = index_start; // string pool 에서도 중복된 식별자 제거
             
             // symbol table 에 중복된 식별자 제거
                index--;
                sym_table[index][0] = -1;
                sym_table[index][1] = -1;
        }
                }
    }

    print_sym_table();
    print_hash_table();


    fclose(fp);
    return 0;
}