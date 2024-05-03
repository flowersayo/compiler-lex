#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tn.h"
extern char* yytext;
extern int linenum;

void reporterror(enum tnumber tn) {
	switch (tn) {
	case TLONGIDENT:
		printf("%-15d %-20s %-15s %s - identifier too long\n", linenum, "Error", " ", yytext);
		break;
	case TILLIDENT:
		printf("%-15d %-20s %-15s %s is illegal identifier\n", linenum, "Error", " ", yytext);
		break;
	case TOVERFLOW:
		printf("%-15s %-20s Symbol table overflow - cannot save %s", "Error", " ", yytext);
		break;
	}
}