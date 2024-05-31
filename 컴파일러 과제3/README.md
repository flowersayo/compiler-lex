# 컴파일

1. flex 명령어로 lex.yy.c 파일 생성하기
   $ flex scanner.l

2. gcc 명령어로 {이름} 파일 생성하기
   $ gcc lex.yy.c main.c -o {이름} -ll

https://velog.io/@sukyeongs/Mac-M1-%ED%99%98%EA%B2%BD%EC%97%90%EC%84%9C-Flex-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0-ft.-%EC%BB%B4%ED%8C%8C%EC%9D%BC%EB%9F%AC-Lex

3. a.out 파일에 데이터 넣기

> $ ./a.out < testdata1.dat

##

- yyleng 출력할 때 %c 대신 %zu 사용
