#include <stdio.h>	//헤더파일들을 추가하려 전처리기를 씀
#pragma warning (disable : 4996)
#include <time.h>
#define FULL 25000	//힙의 최대 개수를 2만 5천개로 넉넉히 잡음

typedef struct
{
	double value;	//힙의 값을 저장할 곳
} unit;

typedef struct
{
	unit heap[FULL];	//힙의 최대 개수를 배열로 나타냄
	int heapSize;	//요소의 개수를 heapSize로 선언
} heap;

void set(heap *h)
{
	h->heapSize = 0;	//처음에는 요소의 개수가 0
}

unit deleteSort(heap *h);	//deleteSort와 insert 함수의 원형을 선언
void insert(heap *h, unit node);

void heapSort(unit p[], int n) //힙을 사용해서 정렬하는 heapSort함수
{	
	int i;
	heap h;

	set(&h);	//heap h을 초기화

	for (i = 0; i<n; i++)
		insert(&h, p[i]);	//힙 h에 노드를 추가
	
	for (i = (n - 1); i >= 0; i--) 
		p[i] = deleteSort(&h);	//힙을 제거 후 p배열에 정렬
}

unit deleteSort(heap *h)	//deleteSort로 힙을 삭제하며 정렬을 하게 함
{
	int parent, child;
	unit node, tmp;

	node = h->heap[1]; // 루트 노드의 값을 node에 대입
	tmp = h->heap[(h->heapSize)--]; // 마지막의 힙을 tmp에 대입하고, heapSize을 한번 감소시킴
	parent = 1;
	child = 2;

	while (child <= h->heapSize)
	{
		if ((child < h->heapSize) && ((h->heap[child].value) > h->heap[child + 1].value))
			child++;	//루트의 왼쪽부터 자식 중 작은 것을 찾음
	

		if (tmp.value <= h->heap[child].value)	//작은 자식 보다 마지막이 더 작으면
			break;	//while문을 나감
		

		h->heap[parent] = h->heap[child];	//작은 자식보다 마지막이 더 클시 부모 노드와 작은 자식 노드를 바꿈

		parent = child;	//한 층 아래로 이동
		child *= 2;
	}

	h->heap[parent] = tmp;	//tmp인 마지막의 노드를 heap[parent]에 대입
	return node;	//가장 작은 노드를 반환
}

void insert(heap *h, unit node)
{
	int i;
	i = ++(h->heapSize);	//힙 크기를 하나 증가

		//힙에서 부모와 비교하는 과정
	while ((i != 1) && (node.value < h->heap[i / 2].value))
	{	//i가 1이 아니면서 노드의 값이 부모 노드보다 작을때 while문 들어감
		h->heap[i] = h->heap[i / 2];	//i의 노드와 부모 노드 교환
		i /= 2;	//한층 올라감
	}
	h->heap[i] = node; // 새로운 노드값을 삽입함
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

		heapSort(A, i * 1000); // 힙 정렬 수행함

		end = clock();	//끝난 시간을 잼

		reslt = (double)(end - start);	//처음과 끝을 재고 실수로 대입
		printf("n = %d 일때 수행시간: %f msec \n", i * 1000, reslt);	//n의 결과에 따라 시간 출력

		free(A);	//동적배열을 해제
	}
	return 0;
}