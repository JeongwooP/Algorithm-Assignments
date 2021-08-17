#include <stdio.h>	//전처리기를 통해 여러 헤더들을 추가
#include <time.h>
#define SWAP(a, b, tmp) ( (tmp)=(a), (a)=(b), (b)=(tmp) )	//SWAP이라는 매크로를 선언
#pragma warning (disable : 4996)	//scanf의 오류 방지

void bubbleSort(double A[], int n)	//버블정렬의 함수 시작
{
	double tmp;	//임시로 넣을 double 변수

	for (int i = n - 1; i > 0; i--)	//n-1인덱스부터 1까지 -1씩 감소
	{
		for (int j = 0; j < i; j++) //0부터 i까지 증가
		{
			if (A[j] > A[j + 1])	//만약 앞에가 더 작다면 데이터 교환
				SWAP(A[j], A[j + 1], tmp);	//A[j]와 A[j+1]을 교환
		}
	}
}

int main() 
{
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

		bubbleSort(A, i * 1000); // 버블 정렬 수행함

		end = clock();	//끝난 시간을 잼

		reslt = (double)(end - start);	//처음과 끝을 재고 실수로 대입
		printf("n = %d 일때 수행시간: %f msec \n", i * 1000, reslt);	//n의 결과에 따라 시간 출력

		free(A);	//동적배열을 해제
	}
	return 0;
}