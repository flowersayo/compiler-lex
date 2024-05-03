#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
extern char *yytext;
extern int linenum;

// 에러 타입 별 메시지
const char *ERR_TOO_LONG_IDENT = "ERROR!! llegal identifier";
const char *ERR_SYMBOLTABLE_OVERFFLOW = "ERROR!! Symbol table overflow";
const char *ERR_ILLEGAL_IDENTIFIER = "ERROR!! illegal identifier";

void reporterror(char *err_msg)
{
	printf(err_msg);
}