#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define NUM 1000	//subset 함수를 NUM번 반복 (Monte Carlo) 

int W = 52;	//sum value
int w[6];	//weights
int include[6];	//포함 여부
int point = 0;	//promising한 완료 트리 세는 변수
int whole = 0;	//총 subset의 만든 노드 개수

int promising(int i, int weight, int total);

void sumOfSubsets(int i, int weight, int total) {	//부분집합 합 함수
	whole++;

	if (promising(i, weight, total)) {	//유망한 노드면
		if (weight == W) {	//총 weight이 목표와 같다면
			for (int n = 0; n <= i; n++)
				if (include[n])		//point를 +1해 완료된 트리 1개 추가
					point++;
				
		}
		else {
			include[i + 1] = 1;	//yes
			sumOfSubsets(i + 1, weight + w[i + 1], total - w[i + 1]);	//재귀적 호출
			include[i + 1] = 0;	//no
			sumOfSubsets(i + 1, weight, total - w[i + 1]);	//재귀적 호출
		}
	}
}

int promising(int i, int weight, int total) {	//유망한지 검사
	return (weight + total >= W) && ((weight == W) || (weight + w[i + 1] <= W));
}


int main() {

	float res;
	int sum = 0;
	int temp = 0;

	srand(time(NULL));	//매번 돌릴 때마다 난수가 다르게

	clock_t start = clock();	//시간 측정

	for (int i = 0; i < NUM; i++) {	//Monte Carlo Method NUM만큼 돌림
		sum = 0;
		for (int j = 0; j < 6; j++) {
			w[j] = rand() % 53;
			sum += w[j];
		}
		
		for (int m = 0; m <= 6; m++)
			for (int k = 0; k < 5; k++)
				if (w[k] > w[k + 1]) {	//오름차순 정렬
					temp = w[k];
					w[k] = w[k + 1];
					w[k + 1] = temp;
				}
		
		sumOfSubsets(-1, 0, sum);
	}

	clock_t end = clock();

	res = (float)(end - start) / CLOCKS_PER_SEC;	//시간 계산
													//결과 출력
	printf("효율성 = %d/%d (유망한 마디 수 / 전체 마디 수) \n\n시간 : %fsec\n\n", point, whole, res);

	return 0;
}