#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define MAX_LEN		12

enum tokentypes {
	TEOF,
	TERROR, TCOMMENT, TNUMBER, TFNUMBER, TIDENT,
	TCONST, TELSE, TIF, TINT, TFLOAT, TRETURN, TVOID, TWHILE,
	TADD, TSUB, TMUL, TDIV, TMOD,
	TASSIGN, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN,
	TNOT, TAND, TOR,
	TEQUAL, TNOTEQU, TLESS, TLESSE, TGREAT, TGREATE,
	TINC, TDEC,
	TLPAREN, TRPAREN, TCOMMA, TLBRACE, TRBRACE, TLBRACKET, TRBRACKET, TSEMI
};
enum errorTypes { noerror, illid_digit, illid_long, illch, real_num, overst};
typedef enum errorTypes ERRORtypes;

extern int lineNumber;
extern int startLineNumber;//주석처리시 시작 lineNumber를 저장하는 변수
extern char error_message[];

//lex 관련 변수
extern char* yytext;
extern int yyleng;
extern int yylex();

//외부 함수 선언
extern void SymbolTable(char*, int);
extern void ReportError(ERRORtypes err);





