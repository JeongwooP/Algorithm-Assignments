#include <stdio.h>
#include <stdlib.h>
#include "P_queue.h"

#define PERF         1
#define LENGTH       5
#define MAX_WEIGHT   9
#define QUEUE_LENGTH 10000

#if PERF
#include <time.h>
#define PERF_TIMES(X) clock_t X = clock()	//시간을 재기위한 매크로
#define PRINT_PERF(X) \
                printf("Best-First execution time: %f sec.\n", (double) (X) / CLOCKS_PER_SEC)
#else
#define PERF_TIMES(...)
#define PRINT_PERF(...)
#endif

typedef struct _Item {
	int profit;
	int weight;
} Item;

int   compare(const void *, const void *);	//함수 원형
int   knapsack3(Item *);
float bound(Node, Item *);

_Priority_Queue_Algo *algo = &Priority_Queue_Algo;

int main(void)
{
	int  max_profit;
	Item item[] = { { 20, 2 },{ 30, 5 },{ 35, 7 },{ 12, 3 },{ 3, 1 } };	//문제에 주어진 값들

	/* 가격대 무게로 아이템들을 내림차순으로 정렬 */
	qsort(item, LENGTH, sizeof(item[0]), compare);

	PERF_TIMES(start_time);
	max_profit = knapsack3(item);
	PERF_TIMES(end_time);

	printf("\nBest-First maximum profit: $%d.\n", max_profit);
	PRINT_PERF(end_time - start_time);

	return 0;
}

int compare(const void *numberA, const void *numberB)	//비교 함수
{
	Item *itemA = (Item *)numberA;
	Item *itemB = (Item *)numberB;

	return (itemB->profit / itemB->weight) - (itemA->profit / itemA->weight);
}

int knapsack3(Item *item)	//knapsack Best-First
{
	Queue queue;
	Node  u, v;

	algo->Create(&queue, QUEUE_LENGTH);

	/* v를 루트노드로 설정 */
	v.level = -1; v.profit = 0; v.weight = 0;
	v.bound = bound(v, item);

	int max_profit = 0;
	algo->Insert(&queue, v);

	while (!algo->Is_Empty(queue)) {
		algo->Remove(&queue, &v);

		/* 유망한지 아닌지를 판단 */
		if (v.bound > max_profit) {
			u.level = v.level + 1;

			/* 다음 물건을 포함하는 자식노드로 노드 u를 설정 */
			u.weight = v.weight + item[u.level].weight;
			u.profit = v.profit + item[u.level].profit;

			if (u.weight <= MAX_WEIGHT && u.profit > max_profit) {
				max_profit = u.profit;
				printf("최대 이윤: %d 무게: %d\n", max_profit, u.weight);
			}

			u.bound = bound(u, item);

			if (u.bound > max_profit) {
				algo->Insert(&queue, u);
			}

			/* 다음 물건을 포함하지 않는 자식노드로 노드 u를 설정 */
			u.weight = v.weight;
			u.profit = v.profit;
			u.bound = bound(u, item);

			if (u.bound > max_profit) {
				algo->Insert(&queue, u);
			}
		}
	}

	algo->Delete(queue);

	return max_profit;
}

float bound(Node u, Item *item)	//한계치 판단 함수
{
	int   j, totweight;
	float result;

	if (u.weight >= MAX_WEIGHT) {
		return 0.0;
	}
	else {
		/* 값을 초기화 */
		j = u.level + 1;
		result = u.profit;
		totweight = u.weight;

		/* 최대한 많은 물건을 집어넣자 */
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