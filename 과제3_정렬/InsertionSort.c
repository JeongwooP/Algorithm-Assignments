#include <stdio.h>	//전처리기로 헤더 파일들 추가
#include <time.h>
#pragma warning (disable : 4996)

void insertionSort(double A[], int n) 
{
	double c;	//값을 보관하는 double변수 c 선언
	int j;

	for (int i = 1; i < n; i++) 
	{
		c = A[i]; // 배열 A의 i번째 수를 변수 c에 보관

		for (j = i - 1; j >= 0; j--) // i-1부터 시작해 줄어듦면서 j=0까지 탐색
		{
			if (A[j] > c)	//A[j]가 c보다 크면
				A[j + 1] = A[j]; // 비교대상 한 칸 뒤로 이동
			else
				break;	//삽입위치 찾았으니 탈출
		}

		A[j + 1] = c;	//찾은 위치에 정렬대상 삽입
	}
}

int main() {
	double *A, reslt;	//A배열을 동적배열로 선언, reslt변수로 시간 차이 측정
	double max = 32767 / 2.0;	//rand()함수의 -1~1까지 범위를 넓이려고 만듦
	srand(1);	//seed를 1로 일정하게 넣음

	clock_t start, end;	//시간 수행 측정 변수

	for (int i = 1; i < 21; i++) //i를 for문으로 1부터 20까지 증가
	{
		A = malloc(sizeof(double) * (i * 1000));	//1000부터 20000까지 의 배열을 for문으로 돌때마다 생성

		for (int j = 0; j < i * 1000; j++) //0부터 i*1000까지 배열 인덱스를 생성
		{
			A[j] = rand() / max - 1;	//-1~1까지의 값을 넣음
		}

		start = clock();	//처음 시간을 잼

		insertionSort(A, i * 1000); // 삽입 정렬 수행함

		end = clock();	//끝난 시간을 잼

		reslt = (double)(end - start);	//처음과 끝을 재고 실수로 대입
		printf("n = %d 일때 수행시간: %f msec \n", i * 1000, reslt);	//n의 결과에 따라 시간 출력

		free(A);	//동적배열을 해제
	}
	return 0;
}