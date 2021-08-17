#include <stdio.h>	//전처리기로 헤더 파일들 추가
#include <time.h>
#define SWAP(a, b, tmp) ( (tmp)=(a), (a)=(b), (b)=(tmp) )	//SWAP이라는 매크로를 선언
#pragma warning (disable : 4996)

int partition(double arr[], int left, int right) 
{
	double tmp;	//임의의 double 변수 선언

	int low = left;	//맨 왼쪽을 low변수에 대입
	int high = right - 1;	//맨 오른쪽의 한칸 왼쪽을 high에 대입
	double pivot = arr[right]; // 제일 오른쪽의 위치가 피벗의 위치(어느 값이든지 피벗을 선택할 수 있음)
				
	do {
		do {
			low++; // 피벗이 배열의 arr[low]보다 더 크면 계속 증가
		} while (low <= right && arr[low] < pivot);

		do {
			high--; // 피벗이 배열의 arr[high]보다 더 작으면 계속 감소
		} while (high >= left && arr[high] > pivot);

		if (low < high)  // low가 high보다 작으면 arr[low]와 arr[high] 서로 바꿈
			SWAP(arr[low], arr[high], tmp);
	} while (low < high);	//low가 high보다 커질때 까지 반복함

	SWAP(arr[right], arr[low], tmp);	// low가 high보다 커지면 while문 탈출 후 arr[right]와 arr[low]를 swap함
	
	return low; // 피벗의 위치인 low를 반환
}


void quickSort(double A[], int p, int r) {	
	int q;
	if (p < r) {
		q = partition(A, p, r);	//둘로 나누고
		
		quickSort(A, p, q - 1);	//왼쪽 영역을 정렬
		
		quickSort(A, q + 1, r);	//오른쪽 영역을 정렬
	}
}

int main() {
	double *A, reslt;	//A배열을 동적배열로 선언, reslt변수로 시간 차이 측정
	double max = 32767 / 2.0;	//rand()함수의 -1~1까지 범위를 넓이려고 만듦
	srand(1);	//seed를 1로 일정하게 넣음

	clock_t start, end;	//시간 수행 측정 변수

	for (int i = 1; i < 21; i++)	//i를 for문으로 1부터 20까지 증가
	{
		A = malloc(sizeof(double) * (i * 1000));	//1000부터 20000까지 의 배열을 for문으로 돌때마다 생성

		for (int j = 0; j < i * 1000; j++) //0부터 i*1000까지 배열 인덱스를 생성
		{
			A[j] = rand() / max - 1;	//-1~1까지의 값을 넣음
		}

		start = clock();	//처음 시간을 잼

		quickSort(A, 0, i * 1000 - 1); // 퀵 정렬 수행함

		end = clock();	//끝난 시간을 잼

		reslt = (double)(end - start);	//처음과 끝을 재고 실수로 대입
		printf("n = %d 일때 수행시간: %f msec \n", i * 1000, reslt);	//n의 결과에 따라 시간 출력

		free(A);	//동적배열을 해제
	}
	return 0;
}