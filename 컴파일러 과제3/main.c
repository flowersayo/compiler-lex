#include "tn.h"
#include "parser.tab.h"
#include "sym_table_lab.h"
#include "hash_func.h"

// lineNumber 관련 변수
int lineNumber = 1;		 // 코드 lineNumber를 담는 변수
int startLineNumber = 0; // 주석 처리시 주석 시작 lineNumber를 담는 변수

extern yyparse();
extern yylex();

// error 관련 변수
ERRORtypes err = noerror; // 에러 타입을 담는 변수

typedef struct
{
	int token;
	const char *name;
} TokenMap;

void PrintHeading()
{
	printf("\n\n");
	printf("-----------        ------------         ------------         ------------ \n");
	printf("Line Number         Token type              Token              ST-index   \n");
	printf("-----------        ------------         ------------         ------------ \n");
	printf("\n");
}

#define BASE_IDX 258 // parser.tab.h 의 토큰 시작 인덱스 담기
const char *str_tokentypes[] = {
	[TEOF - BASE_IDX] = "TEOF",
	[TERROR -
		BASE_IDX] = "TERROR",
	[TCOMMENT -
		BASE_IDX] = "TCOMMENT",
	[TIDENT -
		BASE_IDX] = "TIDENT",
	[TNUMBER -
		BASE_IDX] = "TNUMBER",
	[TFNUMBER -
		BASE_IDX] = "TFNUMBER",
	[TCONST -
		BASE_IDX] = "TCONST",
	[TELSE -
		BASE_IDX] = "TELSE",
	[TIF -
		BASE_IDX] = "TIF",
	[TINT -
		BASE_IDX] = "TINT",
	[TFLOAT -
		BASE_IDX] = "TFLOAT",
	[TRETURN -
		BASE_IDX] = "TRETURN",
	[TVOID -
		BASE_IDX] = "TVOID",
	[TWHILE -
		BASE_IDX] = "TWHILE",
	[TADD -
		BASE_IDX] = "TADD",
	[TSUB -
		BASE_IDX] = "TSUB",
	[TMUL -
		BASE_IDX] = "TMUL",
	[TDIV -
		BASE_IDX] = "TDIV",
	[TMOD -
		BASE_IDX] = "TMOD",
	[TASSIGN -
		BASE_IDX] = "TASSIGN",
	[TADDASSIGN -
		BASE_IDX] = "TADDASSIGN",
	[TSUBASSIGN -
		BASE_IDX] = "TSUBASSIGN",
	[TMULASSIGN -
		BASE_IDX] = "TMULASSIGN",
	[TDIVASSIGN -
		BASE_IDX] = "TDIVASSIGN",
	[TMODASSIGN -
		BASE_IDX] = "TMODASSIGN",
	[TNOT -
		BASE_IDX] = "TNOT",
	[TAND -
		BASE_IDX] = "TAND",
	[TOR -
		BASE_IDX] = "TOR",
	[TEQUAL -
		BASE_IDX] = "TEQUAL",
	[TNOTEQU -
		BASE_IDX] = "TNOTEQU",
	[TLESS -
		BASE_IDX] = "TLESS",
	[TLESSE -
		BASE_IDX] = "TLESSE",
	[TGREAT -
		BASE_IDX] = "TGREAT",
	[TGREATE -
		BASE_IDX] = "TGREATE",
	[TINC -
		BASE_IDX] = "TINC",
	[TDEC -
		BASE_IDX] = "TDEC",
	[TLPAREN -
		BASE_IDX] = "TLPAREN",
	[TRPAREN -
		BASE_IDX] = "TRPAREN",
	[TRBRACE -
		BASE_IDX] = "TRBRACE",
	[TLBRACKET -
		BASE_IDX] = "TLBRACKET",
	[TRBRACKET -
		BASE_IDX] = "TRBRACKET",
	[TSEMI -
		BASE_IDX] = "TSEMI",
	[TCOMMA -
		BASE_IDX] = "TCOMMA",
	[TLBRACE -
		BASE_IDX] = "TLBRACE",
	[LOWER_THAN_ELSE -
		BASE_IDX] = "LOWER_THAN_ELSE"};

void printToken(enum yytokentype tn)
{
	switch (tn)
	{
	case TCOMMENT:
		printf("%-20d %-20s %-20s\n", lineNumber, "TCOMMENT", yytext);
		break;
	case TIDENT:
	{
		HTpointer htp = lookup_hash_table(yytext, divisionMethod(yytext, HASH_TABLE_SIZE));
		int ST_INDEX = htp != NULL ? htp->index : -1;
		printf("%-20d %-20s %-20s %-20d\n", lineNumber, "TIDENT", yytext, ST_INDEX);

		break;
	}
	case TERROR:
		printf("%-20s %-20s\n", "**Error**", error_message);
		break;
	default:
		printf("%-20d %-20s %-20s\n", lineNumber, str_tokentypes[tn - BASE_IDX], yytext);
		break;
	}
}

// Token 인식하여 Token 및 에러 출력
void main()
{
	// int tn;

	init_sym_table();

	PrintHeading();
	/*
		while ((tn = yylex()) != 0)
		{
			// Token 출력
			printToken(tn);
		}
		*/

	printf("start of parser\n");
	yyparse();
	printf("end of parser\n");

	print_sym_table();
	print_hash_table();
}
