#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#define MAXIDENTLEN 100

extern yylex();      // lex.yy.c 에 정의된 외부 변수를 가져옴
extern char *yytext; // 외부에 선언된 전역변수를 현재 파일에서 사용
extern int yyleng;
extern init_sym_table();
extern symtable();
extern reporterror();
extern get_type();
extern line_num;

extern const char *ERR_ILLEGAL_IDENTIFIER;
extern const char *ERR_SYMBOLTABLE_OVERFFLOW;
extern const char *ERR_TOO_LONG_IDENT;

int linenum = 1;
void print_token(Tnumber tn, int st_idx, char *token);

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
         print_token(tn, symtable(yytext, tn), yytext);
         break;
      case TIDENT: // 식별자일경우 길이 체크

         if (yyleng > MAXIDENTLEN) // 지정된 길이를 넘어가면
            reporterror(
                ERR_TOO_LONG_IDENT);
         else // 길이 이내의 정상 식별자이면 심볼테이블에 저장
         {
            print_token(tn, symtable(yytext, tn), yytext);
         }

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
   printf("Token\tLine number\tToken Type\tST-index");
   printf("====================================");
}

void print_token(Tnumber tn, int st_idx, char *token) // line num 은 전역 변수로 저장
{
   if (tn == TIDENT && st_idx != -1)
   {
      // 1. 식별자인 경우에 토큰, 라인넘버, 토큰타입, 심볼 테이블에 저장된 인덱스 출력하기
      printf("Token: %s, Line number: %d, Token type: %s, ST-index: %d\n", token, linenum, get_type(tn), st_idx);
   }
   else
   {
      // 2. 식별자가 아닌 경우에 토큰, 라인넘버, 토큰타입 출력하기
      printf("Token: %s, Line number: %d, Token type: %s\n", token, linenum, get_type(tn));
   }
}