#include <stdio.h>
#define SIZE 13	//해시 테이블 최대 개수
#define EMPTY -1

int arr[SIZE];
int origin, i = 0;	//origin - 처음 입력한 값,
int index;	//주어진 값에서 mod 13한 처음 나머지

void init() {	//모든 테이블 값을 EMPTY로 설정
	for (int i = 0; i < SIZE; i++)
		arr[i] = EMPTY;
}

void quadratic(int n) {		//이차원 조사 함수
	int rs;

	rs = n % SIZE;

	if (arr[rs] == EMPTY) {	//해시 테이블이 비면 삽입
		arr[rs] = origin;
		i = 0;
	}
	else {	//아니면 x + i^2 으로 넘어감
		i++;
		n = index + i * i;
		quadratic(n);
	}
}

int main() {
	int ins;
	init();

	while (1) {
		printf("값 입력: ");
		scanf("%d", &ins);
		origin = ins;
		index = ins % SIZE;
		quadratic(ins);

		printf("\nindex | value \n");
		for (int i = 0; i < SIZE; i++)
			if (arr[i] != EMPTY)		//값이 EMPTY가 아닐 경우 값 출력
				printf("    %d | %d \n", i, arr[i]);
			else
				printf("    %d | Empty \n", i);		//값이 -1 이면 EMPTY라고 출력하기

		printf("\n");
	}
}