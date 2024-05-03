#include <stdio.h>
#include <string.h>
#include "tn.h"
extern int linenum;
extern int yyleng;
extern char* yytext;
extern reporterror(enum tnumber tn);
#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 13

int index_start = 0;
int index_next = 0;
int index = 0;
int hash_value = -1;

int SymbolTable()
{

	

	// symbol table overflow
	if () {
		reporterror(TOVERFLOW);
		return 0;
	}
}