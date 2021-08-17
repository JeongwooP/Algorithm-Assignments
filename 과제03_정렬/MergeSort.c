#include <stdio.h>	//여러 헤더파일들을 전처리기로 추가
#include <math.h>
#include <time.h>
#pragma warning (disable : 4996)

double *margin; // 추가적인 공간이 필요함으로 margin이라는 동적배열 생성하기 위해 선언

void merge(double list[], int left, int mid, int right);	//merge 함수 원형 선언

void mergeSort(double A[], int p, int r)	//병합배열 함수
{
	int q;

	if (p < r) 
	{
		q = (int)floor((p + r) / 2);	//중간 지점을 계산, floor 함수 사용

		mergeSort(A, p, q);	//배열을 전반부, 후반부 둘로 나눠 각각 정렬
		mergeSort(A, q + 1, r);

		merge(A, p, q, r);	//정렬된 두 배열을 병합함

	}
}

void merge(double list[], int left, int center, int right) //2개의 배열을 병합하는 함수
{
   
	int sortedL = left;	//정렬된 가장왼쪽을 sortedL
	int sortedR = center + 1;	//정렬된 중간의 오른쪽을 sortedR
	int sortedIndx = left;	//정렬된 배열의 인덱스가 sortedIndx

	int i;

	while (sortedL <= center && sortedR <= right) //나눈 배열의 합병을 while문으로 작성
	{
		if (list[sortedL] <= list[sortedR])	//병합 할 두 영역의 데이터들을 비교, 정렬 순서대로 margin에 하나씩 옮겨 담음
			margin[sortedIndx] = list[sortedL++];
		else
			margin[sortedIndx] = list[sortedR++];

		sortedIndx++;
	}

	if (sortedL>center)		//배열 값들을 복사하는 과정(뒷 부분)
	{
		for (i = sortedR; i <= right; i++, sortedIndx++)
			margin[sortedIndx] = list[i];
	}
	else	//배열 값들을 복사하는 과정(앞 부분)
	{
		for (i = sortedL; i <= center; i++, sortedIndx++)
			margin[sortedIndx] = list[i];
	}

	for (i = left; i <= right; i++) 
	{
		list[i] = margin[i];	//임시배열을 초기 배열에 하나하나 복사시킴
	}

}

int main() 
{
	double *A, reslt;	//A배열을 동적배열로 선언, reslt변수로 시간 차이 측정
	double max = 32767 / 2.0;	//rand()함수의 -1~1까지 범위를 넓이려고 만듦
	srand(1);	//seed를 1로 일정하게 넣음

	clock_t start, end;	//시간 수행 측정 변수

	for (int i = 1; i < 21; i++)	//i를 for문으로 1부터 20까지 증가
	{
		A = malloc(sizeof(double) * (i * 1000));	//1000부터 20000까지 의 배열을 for문으로 돌때마다 생성
		margin = malloc(sizeof(double) * (i * 1000));	//1000부터 20000까지 의 배열을 for문으로 돌때마다 생성

		for (int j = 0; j < i * 1000; j++) //0부터 i*1000까지 배열 인덱스를 생성
		{
			A[j] = rand() / max - 1;	//-1~1까지의 값을 넣음
		}

		start = clock();	//처음 시간을 잼

		mergeSort(A,0, i * 1000-1); // 병합 정렬 수행함

		end = clock();	//끝난 시간을 잼

		reslt = (double)(end - start);	//처음과 끝을 재고 실수로 대입
		printf("n = %d 일때 수행시간: %f msec \n", i * 1000, reslt);	//n의 결과에 따라 시간 출력

		free(A);	//동적배열 A을 해제
		free(margin); //동적배열 margin을 해제
	}
	return 0;
}