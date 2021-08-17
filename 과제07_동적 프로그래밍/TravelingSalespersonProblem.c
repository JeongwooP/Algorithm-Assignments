#include<stdio.h>
#define SIZE 5	//도시 개수

int bag[12], sum = 0;

int w[5][5] = {	//행렬 W
	{ 0, 8, 13, 18, 20 },
	{ 3, 0, 7, 8, 10 },
	{ 4, 11, 0, 10, 7 },
	{ 6, 6, 7, 0, 11 },
	{ 10, 6, 2, 1, 0 }
};

int optimal(int c);

void minimum(int vertex)	//최적 경로 출력
{
	int m;
	bag[vertex] = 1;	//bag[도시] = 1

	printf("%d -> ", vertex + 1);

	m = optimal(vertex);	//가중치가 최소인 도시 반환

	if (m == 999)	//조건문
	{
		m = 0;
		printf("%d", m + 1);
		sum += w[vertex][m];
		return;
	}

	minimum(m);
}

int optimal(int c)	//최적 경로 탐색
{
	int i;
	int opN = 999;
	int min = 999;
	int minL;

	for (i = 0; i < SIZE; i++)
	{
		if ((w[c][i] != 0) && (bag[i] == 0))	//행렬[c][0-4] 0이 아니고 bag 값이 0일때
			if (w[c][i] + w[i][c] < min)	//정점 2개의 쌍방향 가중치 < 최소값이면
			{
				min = w[i][0] + w[c][i];	//min에 최소값 저장
				minL = w[c][i];
				opN = i;
			}
	}

	if (min != 999)	//가중치를 더함
		sum += minL;

	return opN;
}

int main()
{
	printf("\n최적 회로:\n");
	minimum(0); //정점의 시작으로 0을 대입

	printf("\n\n최적 회로의 총 값: %d\n\n", sum);

	return 0;
}
