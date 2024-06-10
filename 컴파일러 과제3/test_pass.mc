
const int h = 5;
int add(int,int); // 함수 선언시 함수 정의 저장

int multiply(float a,float b){

    return a*b;
}

int main()
{

    int i = 0;
    float f = 3.0;
    int arr[3];

    add(3,5); // 정상 호출
    multiply(3.0,5.4); // 자료형 일치

   
    while(i <= h) {
		
		if (i == 2) add(1,3); 
		i++;
	}


}

