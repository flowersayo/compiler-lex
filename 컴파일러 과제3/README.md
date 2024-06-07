# Requirement

- bison 1.23
- flex 2.6.4 Apple(flex-34)

# Run

1. flex 명령어로 lex.yy.c 파일 생성하기
   $ flex scanner.l

2. bison 명령어로 parser.tab.h parser.tab.c 생성하기
   $ bison -d parser.y %-d 를 주면 공통된 토큰을 포함한 헤더 파일을 아웃풋으로 산출 할수 있음

3. 컴파일
   gcc main.c parser_tab.h parser_tab.c hash_func.h hash_func.c sym_table_lab.h sym_table_lab.c tn.h reporterror.c
   // lex.yy.c 는 parser.y 에 이미 포함됨

! parser.y 의 union 에서 커스텀 구조체를 사용할 경우 결과 parser.tab.h에 수동으로 #include "sym_table_lab.h” 넣어주어야 한다. 아니면 해당 구조체를 찾지 못했다는 에러가 뜬다.

! union 을 사용할 경우 YYSTYPE가 중복정의되어있다는 오류가 있다. 따라서 parser_tab.c 의 71번째 줄에서 아래 구문을 제거해주어야 한다.

typedef union{
int ival;
float fval;
char \*sval;
int type;
} YYSTYPE;

4. 결과 파일 넣기
   ./a.out < input_noerror.mc

---

# MAC

- lex.yy.c 컴파일 된 결과의 #include <malloc.h> -> #include <stdlib> 로 바꾸어야함 (malloc.h 지원x)
- parser.tab.c 컴파일 된 결과의 #include <malloc.h> -> #include <stdlib> 로 바꾸어야함 (malloc.h 지원x)
- sym_table_lab.c 의 148번째 줄의 strcpy_s -> strncpy 로 변경
- reporterror.c 의 strcpy_s -> strncpy 로 변경, s_printf -> snprintf 로 변경
- bison.exe가 실제로 Windows 실행 파일인 경우, Wine을 사용하여 macOS에서 실행가능

```
brew install --cask wine-stable // wine  설치
wine bison.exe -d parser.y // bison 실행

```

--

# 참고사항

- tn.h 의 토큰 정의와 파서에 %token 으로 정의한 토큰 결과(parser.tab.~)가 겹쳐서 덮어씌워지는 문제가 있어서 tn.h 에 존재하던 기존 토큰 정의는 없애고 parser가 #define 으로 동작헐 수 있도록 기존 코드를 일부 수정하였다.
