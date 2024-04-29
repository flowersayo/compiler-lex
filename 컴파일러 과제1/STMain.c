#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "STMain.h"
#include "HashFunc.h"
#include "HashFunc.c"

char separators[] = " ,;\t\n\r\n"; // 구분자 문자열
char str_pool[100]; // 문자열 풀
int sym_table[SYM_TABLE_SIZE][2]; // 심볼 테이블

typedef struct HTentry* HTpointer;

typedef struct HTentry {
    int index; // symbol table 의 index 
    HTpointer next;
} HTentry;

HTpointer HT[HASH_TABLE_SIZE];

// id_index : string pool 에서 문자열의 시작 주소. index_start
// hscode : identifier 의 hash_value 를 계산한 것 
HTpointer lookup_hash_table(int id_index, int hscode) {
    HTpointer entry = HT[hscode];

    while (entry != NULL) {
        // string pool 의 id_index부터 시작하는 문자열과
        // symbol 테이블의 인덱스 값에 해당하는 문자열 비교 
        if (strcmp(str_pool + entry->index, str_pool + id_index) == 0) { // 동일하면 0반환
            return entry;
        }

        entry = entry->next;
    }
    return NULL;
}

void add_hash_table(int id_index, int hscode) {
    // 새 항목 생성 및 초기화
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));

    if (newEntry == NULL) {
        printf("메모리 할당 실패 \n");
        exit(1);
    }

    newEntry->index = id_index;
    newEntry->next = NULL;

    /*HT 에 추가*/

    if (HT[hscode] == NULL) {
        HT[hscode] = newEntry;
    }
    else {
        // 전위법
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
        // 후위법
    }
}

void init_sym_table() {
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        sym_table[i][0] = -1;
        sym_table[i][1] = -1;
    }
}

void print_sym_table() {
    int i;
    printf("\n심볼 테이블\n");
    printf("인덱스\t길이\t심볼\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        if (sym_table[i][0] != -1) {
            printf("%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], str_pool + sym_table[i][0]);
        }
    }
}

int main() {
    char test_data[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
                  
    int c; // 현재 문자를 저장할 변수
    int index_start = 0; //  string pool 에서 현재 문자열의 시작점
    int index_next = 0; //  string pool 에서 다음 원소가 들어갈 점 
    int index = 0; // sym table 에 새로운 항목을 추가할 때 사용되는 인덱스  

    init_sym_table();

    for (int i = 0; i < strlen(test_data); ++i) {
        c = test_data[i];

        if (strchr(separators, c) != NULL || index_next >= sizeof(str_pool) - 1) {
            
            // 구분자이거나 문자열 풀의 크기를 초과한 경우 
            if (index_start < index_next) { // 문자열의 시작 인덱스가 끝 인덱스보다 작은 경우 ( start = next 인 경우는 ,가 처음에 들어온 것 )
                str_pool[index_next] = '\0'; // 문자열의 끝을 표시

                if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9') { // 문자열이 숫자로 시작하는 경우
                    printf("에러 - 숫자로 시작됨 (%s)\n", str_pool + index_start); // 에러 출력
                    index_next = index_start; // 다음 인덱스를 현재 인덱스로 설정 (= string pool 에 저장 x 무시)
                }
                else {  // 정상적인 변수라면 sym table {시작,길이}  저장 

                // 
                    sym_table[index][0] = index_start;
                    sym_table[index++][1] = (int)strlen(str_pool + index_start);
                    /*

                    // key 값을 사전에 계산할 경우 
                     while(str_pool[index_start+i]!='\0'){
                        hash_key += str_pool[index_start + i ++]; 
                     }
                    */

                   // 현재 identifier 의 hash 값 구하기 
                    int hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);

                    HTpointer htp = lookup_hash_table(index_start, hash_value);

                    if (htp == NULL) { // 동일한 값이 없는 경우 
                        add_hash_table(index_start, hash_value);
                        printf("%s (Hash: %d)\n", str_pool + index_start, hash_value); // 문자열 출력
                        index_start = ++index_next; // 버퍼 인덱스 초기화 -> 다음 들어올 identifier 를 위해
                    }
                    else { // 동일한 값이 있는 경우
                        printf("%s (Already exists. Hash: %d)\n", str_pool + index_start, hash_value);
                        index_start = ++index_next;
                    }

                    //printf("%s (Hash: %d)\n", str_pool + index_start, hash_value); // 문자열 출력
                    //index_start = ++index_next; // 다음 인덱스 설정l
                }
            }
             
            if (strchr(separators, c) == NULL) { // 구분자인 경우
                str_pool[index_next++] = (char)c; // 구분자가 아닌 문자는 문자열 풀에 저장
            }
            continue; // 다음 문자로 이동
        }

        // 구분자가 아니라면 
        str_pool[index_next++] = (char)c; // 문자를 문자열 풀에 저장
    }

    // 입력 문자열 끝까지 다 본후 처리

    if (index_start < index_next) { // 남은 문자열이 있는 경우
        str_pool[index_next] = '\0'; // 문자열의 끝을 표시
        sym_table[index][0] = index_start;
        sym_table[index++][1] = (int)strlen(str_pool + index_start);

        int hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);

        HTpointer htp = lookup_hash_table(index_start, hash_value);

        if (htp == NULL) { // 동일한 값이 없는 경우 
            add_hash_table(index_start, hash_value);
            printf("%s (Hash: %d)\n", str_pool + index_start, hash_value); // 문자열 출력
        }
        else {
            printf("%s (Already exists. Hash: %d)\n", str_pool + index_start, hash_value);
        }
        printf("%s (Hash: %d)\n", str_pool + index_start, hash_value); // 문자열 출력
    }

    print_sym_table(); // 심볼 테이블 출력

    return 0;
}
