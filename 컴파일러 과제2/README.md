# homework 2 Mini C를 위한 Scanner를 Lex (flex)

## 0. 디버깅

- acvfxgf$ -> 서연
- " ->

## 1. 토큰 인식

- 각 토큰에 해당하는 ENUM 생성
- 각 토큰에 해당하는 정규 표현식 작성

## 2. 심볼 테이블 토큰 저장

## 3. 예외처리

1. too long identifier: identifier의 길이가 15자 이상인 경우. 예: ababababababababababab
2. illegal identifier: identifier가 숫자로 시작하거나, identifier에서 허용하지 않는
   문자를 포함하고 있는 경우 등. 예: 123id, l@ve 등
3. overflow: symbol table에 저장 가능한 공간이 부족할 때

## 4. 토큰 결과 함수 구현하기 printtoken()

## 5. 테스트케이스 4개 + 제출

## FAQ

- ST-index 심볼 테이블 인덱스는 넣는것인지. (형식)
- 심볼 테이블 정보를 출력
- 해시테이블도 구현을 해야하는 것인지.
