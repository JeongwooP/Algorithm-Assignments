#include <stdio.h>
#define N 7	//그래프의 정점 개수
#define INF 999	//연결 안된 정점 표현

int arr[7][7] = {
 {0, 4, INF, INF, INF, 10, INF},
 {3, 0, INF, 18, INF, INF, INF},
 {INF, 6, 0, INF, INF, INF, INF},
 {INF, 5, 15, 0, 2, 19, 5},
 {INF, INF, 12, 1, 0, INF, INF},
 {INF, INF, INF, INF, INF, 0, 10},
 {INF, INF, INF, 8, INF, INF, 0}
};
int d[7][7];	//d는 최단 경로 저장 행렬

void simpleShortestPath() {	//최단 경로 함수

	/*처음 그래프, 즉 가장 가까운 거리를 행렬d에 복사*/
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = arr[i][j];	//행렬 d는 arr와 같아짐

	/*모든 정점들을 하나씩 중간 정점에 더함*/
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (d[i][k] + d[k][j] < d[i][j])   //정점 k가 i -> j로 가는 가장 짧은 path면 
					d[i][j] = d[i][k] + d[k][j];	//d[i][j]를 갱신함

	printf("최단경로 가중치 행렬\n D=\n");
	for (int i = 0; i < N; i++) {			//행렬 D 결과 출력
		for (int j = 0; j < N; j++)
			if (d[i][j] == INF)
				printf("경로존재 안함\n");
			else
				printf(" %2d ", d[i][j]);

		printf("\n");
	}
}


int main() {
	simpleShortestPath();	//최단 경로 함수 호출

	return 0;
}