#include <stdio.h>

int divisionMethod(int key, int tableSize) {
	return key % tableSize;
}

int divisionMethod2(char* key, int tableSize) {
	unsigned int hash_key = 0;
	int c;

	while (c = *key++) {
		hash_key += c;
	}
	return hash_key % tableSize;
}

int midsquareMethod(int key, int tableSize) {
	int squared = key * key;
	int midPart = squared / 100 % 1000; // 제곱값의 중간 부분 추출
	return midPart % tableSize;
}

int foldingMethod(int key, int tableSize) {
	int fold = 0;
	while (key > 0) {
		fold += key % 10000; // 4자리씩 나누어 더함
		key /= 10000;
	}
	return fold % tableSize;
}