#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "symtable.c"
#include "glob.h"
#include "reporterror.c"

extern yylex();      // lex.yy.c 에 정의된 외부 변수를 가져옴
extern char *yytext; // 외부에 선언된 전역변수를 현재 파일에서 사용
extern int linenum;
extern int yyleng;

void main()
{
   enum tnumber tn; // token number

   // 에러를 제외한 모든 의미있는 토큰 출력
   // 에러라면 토큰 출력하지 않고 에러메시지만 출력

   while ((tn = yylex()) != TEOF)
   {

      switch (tn)
      {

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
      case TINTEGER:
      case TFLOAT:
         symtable(yytext, tn);
         printf("%s: %s\n", get_type(tn), yytext); // print token
         break;

      case TIDENT: // 식별자일경우 길이 체크

         if (yyleng > MAXIDENTLEN) // 지정된 길이를 넘어가면
            reporterror(
                ERR_TOO_LONG_IDENT);
         else // 길이 이내의 정상 식별자이면 심볼테이블에 저장
         {
            symtable(yytext, tn);
         }
         // sym table에 토큰 넣기
         printf("%s: %s\n", get_type(tn), yytext); // print token
         break;

      case TLINE:
         linenum++;
         break;
      case TERROR:
         reporterror(ERR_ILLEGAL_IDENTIFIER);
      }
   }
}

void print_header()
{
   printf("====================================");

   printf("====================================");
}

void print_token(int line_num, Tnumber tn, int string_pool_idx, char *token)
{
}