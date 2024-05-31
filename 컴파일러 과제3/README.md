1. flex 명령어로 lex.yy.c 파일 생성하기
   $ flex scanner.l

2. bison 명령어로 parser.tab.h parser.tab.c 생성하기
   $ bison -d cal.y %-d 를 주면 공통된 토큰을 포함한 헤더 파일을 아웃풋으로 산출 할수 있음

3. 컴파일
   gcc main.c parser.tab.h parser.tab.c hash_func.h hash_func.c sym_table_lab.h sym_table_lab.c tn.h reporterror.c
   // lex.yy.c 는 이미 parser.y 에 include 되어있으므로 포함하지 않을 것.

---

# MAC

- lex.yy.c 컴파일 된 결과의 #include <malloc.h> -> #include <stdlib> 로 바꾸어야함 (malloc.h 지원x)
- parser.tab.c 컴파일 된 결과의 #include <malloc.h> -> #include <stdlib> 로 바꾸어야함 (malloc.h 지원x)
- sym_table_lab.c 의 148번째 줄의 strcpy_s -> strncpy 로 변경
- reporterror.c 의 strcpy_s -> strncpy 로 변경
