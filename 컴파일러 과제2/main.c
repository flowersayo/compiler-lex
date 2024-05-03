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

   init_sym_table();

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
         // print_token();
         break;
      case TIDENT: // 식별자일경우 길이 체크

         int st_idx = -1;          // 심볼 테이블에 저장된 토큰이 있는지
         if (yyleng > MAXIDENTLEN) // 지정된 길이를 넘어가면
            reporterror(
                ERR_TOO_LONG_IDENT);
         else // 길이 이내의 정상 식별자이면 심볼테이블에 저장
         {
            st_idx = symtable(yytext, tn);
         }
         // print_token();
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

void print_token(Tnumber tn, int string_pool_idx, char *token) // line num 은 전역 변수로 저장
{
}