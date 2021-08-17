#include <stdio.h>
#include <stdlib.h>
#include "C_queue.h"

#define PERF         1
#define LENGTH       5
#define MAX_WEIGHT   9
#define QUEUE_LENGTH 10000

#if PERF
#include <time.h>
#define PERF_TIMES(X) clock_t X = clock()	//�ð��� ��������� ��ũ��
#define PRINT_PERF(X) \
                printf("Breadth-First execution time: %f sec\n", (double) (X) / CLOCKS_PER_SEC)
#else
#define PERF_TIMES(...)
#define PRINT_PERF(...)
#endif

typedef struct _Item {
	int profit;
	int weight;
} Item;

int   compare(const void *, const void *);	//�Լ� ����
int   knapsack2(Item *);
float bound(Node, Item *);

_Queue_Algo *algo = &Queue_Algo;	

int main(void)
{
	int  max_profit;
	Item item[] = { { 20, 2 },{ 30, 5 },{ 35, 7 },{ 12, 3 },{ 3, 1 } };	//���� ����

	/* ������ �������� ���Է� ������ ������ ������ ���� */
	qsort(item, LENGTH, sizeof(item[0]), compare);

	PERF_TIMES(start_time);
	max_profit = knapsack2(item);
	PERF_TIMES(end_time);

	printf("\nBreadth-First maximum profit: $%d.\n", max_profit);
	PRINT_PERF(end_time - start_time);

	return 0;
}

int compare(const void *numberA, const void *numberB)	//���ϴ� �Լ�
{
	Item *itemA = (Item *)numberA;
	Item *itemB = (Item *)numberB;

	return (itemB->profit / itemB->weight) - (itemA->profit / itemA->weight);
}

int knapsack2(Item *item)	//knapsack BFS
{
	Queue queue;
	Node  u, v;

	algo->Create(&queue, QUEUE_LENGTH);

	/* V�� ��Ʈ���� ���� */
	v.level = -1; v.profit = 0; v.weight = 0;

	int max_profit = 0;
	algo->Enqueue(&queue, v);

	while (!algo->Is_Empty(queue)) {
		algo->Dequeue(&queue, &v);
		u.level = v.level + 1;

		/* ������ ������ �����ϴ� �ڽ� ���� u�� ���� */
		u.weight = v.weight + item[u.level].weight;
		u.profit = v.profit + item[u.level].profit;

		if (u.weight <= MAX_WEIGHT && u.profit > max_profit) {
			max_profit = u.profit;
			printf("�ִ� ����: %d ����: %d\n", max_profit, u.weight);
		}
		if (bound(u, item) > (float)max_profit) {
			algo->Enqueue(&queue, u);
		}

		/* ������ ������ �������� �ʴ� �ڽ� ���� u�� ���� */
		u.weight = v.weight;
		u.profit = v.profit;

		if (bound(u, item) > (float)max_profit) {
			algo->Enqueue(&queue, u);
		}
	}

	algo->Delete(queue);

	return max_profit;
}

float bound(Node u, Item *item)	//�Ѱ�ġ �Ǵ�
{
	int   j, totweight;
	float result;

	if (u.weight >= MAX_WEIGHT) {
		return 0;
	}
	else {
		/* ���� �ʱ�ȭ */
		j = u.level + 1;
		result = u.profit;
		totweight = u.weight;

		/* �ִ����� ������ ����ֱ� */
		while ((j < LENGTH) && (totweight + item[j].weight <= MAX_WEIGHT)) {
			totweight = totweight + item[j].weight;
			result = result + item[j].profit;
			j++;
		}

		int k = j;
		if (k < LENGTH) {
			result += (MAX_WEIGHT - totweight) * item[k].profit / item[k].weight;
		}

		return result;
	}
}