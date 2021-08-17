#include <stdio.h>
#include <conio.h>

int W = 52;	//sum value
int w[6] = { 2, 10, 13, 17, 22, 42 }; //주어진 weights
int include[6]; //각 포함 여부
int count = 0;	//step 출력 위한 count

int promising(int i, int weight, int total);

void sumOfSubsets(int i, int weight, int total) { //부분집합 합 함수
	count++;
	if (promising(i, weight, total)) {	//유망한 노드면
		if (weight == W) {				//총 weight이 목표와 같다면
			printf("\n최종 subsets: [ ");
			for (int n = 0; n <= i; n++)
				if (include[n])			//Sum-of-Subset의 맞는 노드들 출력
					printf("%d ", w[n]);
			printf("]\n");
		}
		else {
			include[i + 1] = 1;	//yes
			if (count < 5) {
				printf("\step%d: ( ", count);	//3~4단계 출력
				for (int n = 0; n <= i; n++)
					if (include[n])
						printf("%d ", w[n]);
				printf(")\n");
			}
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
	sumOfSubsets(-1, 0, 106);	//sumOfSubsets함수 실행
	return 0;
}