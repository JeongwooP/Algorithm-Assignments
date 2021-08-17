#include <stdio.h>
#define SIZE 13	//해쉬 테이블 최대 수
#define EMPTY -1	//빈 테이블은 -1로 지정
int arr[SIZE];
int origin;

void init() {	//배열들 -1 값으로 초기화
	for (int i = 0; i < SIZE; i++)
		arr[i] = EMPTY;
}

void linear(int n) {	//선형 조사 방법의 추가 함수
	int rs;

	rs = n % SIZE;	//x mod 13

	if (arr[rs] == EMPTY)	//테이블이 비면 원소 삽입
		arr[rs] = origin;
	else {
		n++;	// x + i
		linear(n);
	}
}

int main() {
	int ins;
	init();	//배열 초기화

	while (1) {
		printf("값 입력: ");
		scanf("%d", &ins);
		origin = ins;
		linear(ins);

		printf("\nindex | value \n");
		for (int i = 0; i < SIZE; i++)
			if(arr[i] != EMPTY)		//값이 EMPTY가 아닐 경우 값 출력
				printf("    %d | %d \n", i, arr[i]);
			else
				printf("    %d | Empty \n", i);		//값이 -1 이면 EMPTY라고 출력하기

		printf("\n");
	}
}