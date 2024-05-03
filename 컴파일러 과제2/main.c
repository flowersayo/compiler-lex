#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "symtable.c"

extern yylex(); // lex.yy.c 에 정의된 외부 변수를 가져옴
extern char *yytext;
extern int linenum;
extern int yyleng;

void main()
{
   enum tnumber tn; // token number

   while ((tn = yylex()) != TEOF)
   {
      switch (tn)
      {
      case TEOF:
      case TCONST:
      case TELSE:
      case TIF:
      case TINT:
      case TRETURN:
      case TVOID:
      case TWHILE:
      case TEQUAL:
      case TNOTEQU:
      case TLESSE:
      case TGREATE:
      case TAND:
      case TOR:
      case TINC:
      case TDEC:
      case TADDASSIGN:
      case TSUBASSIGN:
      case TMULASSIGN:
      case TDIVASSIGN:
      case TMODASSIGN:
      case TEXCLAM:
      case TMOD:
      case TLPAREN:
      case TRPAREN:
      case TSTAR:
      case TPLUS:
      case TCOMMA:
      case TMINUS:
      case TDIV:
      case TSEMICOLON:
      case TLESS:
      case TEQUALS:
      case TGREATER:
      case TLBRACKET:
      case TRBRACKET:
      case TLBRACE:
      case TRBRACE:
      case TASSIGN:
      case TIDENT:
      case TINTEGER:
      case TFLOAT:
         symtable(yytext, tn);                     // sym table에 토큰 넣기
         printf("%s: %s\n", get_type(tn), yytext); // print token
         break;
      case TERROR:
         printf("err! invalid identifier %s", yytext);
      }
   }

   // print_sym_table();
}
