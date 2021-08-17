#include <stdio.h>
#define N 7	//그래프의 정점 개수
#define INF 999	//연결 안된 정점 표현

void printPath(int p[][N], int start, int end) {	//start부터 end까지의 이어지는 경로 출력
	if (p[start - 1][end - 1] != 0)		//0값이 아닌, 다른 노드 경유시 if문 실행
	{
		printPath(p, start, p[start - 1][end - 1]);	//재귀적, start노드에서 경유하는 노드까지 경로 검사
		printf("%2d->", p[start - 1][end - 1]);
		printPath(p, p[start - 1][end - 1], end);  // 재귀적, 경유하는 노드에서 end노드까지 경로 검사
	}
}

void floyd2(int n, const W[][N], int D[][N], int P[][N]) {	//Floyd's 최단경로 알고리즘
	int i, j, k;
	for (i = 0; i < n; i++)	//0으로 초기화
		for (j = 0; j < n; j++)
			P[i][j] = 0;

	for (i = 0; i < n; i++)	//D = W
		for (j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for(k = 0; k < n ; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) 
				if (D[i][k] + D[k][j] < D[i][j]) {	//k를 거쳐가는 것이 더 빠르면
					P[i][j] = k + 1;				//k를 포함한 거리를 D에 업데이트
					D[i][j] = D[i][k] + D[k][j];
				}	
		
}

int main() {
	int i, j;

	int W[N][N] = {	//W행렬 초기화
		{ 0, 4, INF, INF, INF, 10, INF },
		{ 3, 0, INF, 18, INF, INF, INF },
		{ INF, 6, 0, INF, INF, INF, INF },
		{ INF, 5, 15, 0, 2, 19, 5 },
		{ INF, INF, 12, 1, 0, INF, INF },
		{ INF, INF, INF, INF, INF, 0, 10 },
		{ INF, INF, INF, 8, INF, INF, 0 }
	};

	int P[N][N];	//행렬 P
	int D[N][N];	//행렬 D

	floyd2(N, W, D, P);

	printf("2번)\nP = \n");
	for (i = 0; i < N; i++) {	//P행렬 출력
		for (j = 0; j < N; j++)
			printf("%2d ", P[i][j]);

		printf("\n");
	}

	printf("\nD = \n");
	for (i = 0; i < N; i++) {	//D행렬 출력
		for (j = 0; j < N; j++)
			printf("%2d ", D[i][j]);

		printf("\n");
	}

	printf("\n");
	printf("V3 -> V6:\n");
	printf("최단경로: 3->");
	printPath(P, 3, 6);	//V3부터 시작해 V6까지의 최단 경로 출력
	printf(" 6\n");
	printf("최단거리: %2d\n\n", D[2][5]);

	int A[N][N] = {	//바뀐 문제 3의 A행렬 초기화
		{ 0, INF, INF, 8, INF, INF, INF },
		{ 10, 0, INF, INF, INF, INF, INF },
		{ INF, INF, 0, 1, 12, INF, INF },
		{ 5, 19, 2, 0, 15, 5, INF },
		{ INF, INF, INF, INF, 0, 6, INF },
		{ INF, INF, INF, 18, INF, 0, 3 },
		{ INF, 10, INF, INF, INF, 4, 0 }
	};

	floyd2(N, A, D, P);

	printf("3번)\nP = \n");
	for (i = 0; i < N; i++) {	//P 출력
		for (j = 0; j < N; j++)
			printf("%2d ", P[i][j]);

		printf("\n");
	}

	printf("\nD = \n");
	for (i = 0; i < N; i++) {	//D출력
		for (j = 0; j < N; j++)
			printf("%2d ", D[i][j]);

		printf("\n");
	}

	printf("\n");
	printf("a5 -> a2:\n");
	printf("최단경로: 5->");
	printPath(P, 5, 2);	//A5부터 시작해 A2까지의 최단 경로 출력 
	printf(" 2\n");
	printf("최단거리: %2d\n\n", D[4][1]);

	return 0;
}