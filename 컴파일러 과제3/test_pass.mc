
const int h = 5;
int add(int,int); // 함수 선언시 함수 정의 저장

int multiply(int a,int b){

    return a*b;
}

int main()
{

    int a = 1;
    float f = 3.0;
    int i,j,k;
    int i=2;


    add(3,5); // 정상 호출
    multiply(3,5);

    int i = 2;
    while(i <= h) {
		
		if (i == 2) add(1,3); 
		++i;
	}


}

