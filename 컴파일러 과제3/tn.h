#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define MAX_LEN 12
/*
enum tokentypes
{
	TEOF,
	TERROR,
	TCOMMENT,
	TNUMBER,
	TFNUMBER,
	TIDENT,
	TCONST,
	TELSE,
	TIF,
	TINT,
	TFLOAT,
	TRETURN,
	TVOID,
	TWHILE,
	TADD,
	TSUB,
	TMUL,
	TDIV,
	TMOD,
	TASSIGN,
	TADDASSIGN,
	TSUBASSIGN,
	TMULASSIGN,
	TDIVASSIGN,
	TMODASSIGN,
	TNOT,
	TAND,
	TOR,
	TEQUAL,
	TNOTEQU,
	TLESS,
	TLESSE,
	TGREAT,
	TGREATE,
	TINC,
	TDEC,
	TLPAREN,
	TRPAREN,
	TCOMMA,
	TLBRACE,
	TRBRACE,
	TLBRACKET,
	TRBRACKET,
	TSEMI
};
*/
enum errorTypes
{
	noerror,
	illid_digit,
	illid_long,
	illch,
	real_num,
	overst
};
typedef enum errorTypes ERRORtypes;

extern int lineNumber;
extern int startLineNumber; // �ּ�ó���� ���� lineNumber�� �����ϴ� ����
extern char error_message[];

// lex ���� ����
extern char *yytext;
// extern int yyleng;
extern int yylex();

// �ܺ� �Լ� ����
extern void SymbolTable(char *, int);
extern void ReportError(ERRORtypes err);
