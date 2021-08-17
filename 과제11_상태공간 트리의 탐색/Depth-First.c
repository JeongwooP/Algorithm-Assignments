#include <stdio.h>
#define SIZE 5

int maxprofit = -1;	//값들 설정
int numset, bestset;
int include[5];
int W = 9;
int w[5] = { 2, 5, 7, 3, 1 };
int p[5] = { 20, 30, 35, 12, 3 };
int bound;
int count = 1;

int promising(int i, int profit, int weight);

void knapsack(int i, int profit, int weight){	//knapsack problem function
	if (weight <= W && profit > maxprofit) {	//조건에 맞으면 출력
		maxprofit = profit;
		numset = i;
		bestset = include[i];
		printf("가치: $%d, 무게: %d, 한계치: $%d\n", maxprofit, weight, bound);
	}

	if (promising(i, profit, weight)) {	//유망한지 판단
		include[i + 1] = 1; //yes
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
		include[i + 1] = 0; //no
		knapsack(i + 1, profit, weight);
	}
}

int promising(int i, int profit, int weight) {	//유망한지 보는 함수
	int j, k;
	int totweight;

	if (weight >= W) return 0;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= SIZE) && (totweight + w[j] <= W)) {	//유망한 조건을 계속 반복
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j; 
		if (k <= SIZE)
			bound = bound + (W - totweight)*p[k] / w[k];
		return bound > maxprofit;
	}
}

int main() {
	knapsack(-1, 0, 0);

	return 0;
}