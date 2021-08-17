#ifndef CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_H_

#include <stdint.h>
#include <stdbool.h>

//노드들과 원형 큐 선언
typedef struct _Node {
	int level;      /* 트리의 레벨 */
	int profit;		/* 이익 */
	int weight;		/* 무게 */
} Node;

typedef struct _Queue {
	int  front, rear;
	int  length;
	Node *data;
} Queue;

typedef struct _Queue_Algo {
	void(*Create)(Queue *, int);
	void(*Delete)(Queue);

	bool(*Is_Empty)(Queue);
	bool(*Is_Full)(Queue);

	void(*Enqueue)(Queue *, Node);
	void(*Dequeue)(Queue *, Node *);
} _Queue_Algo;

extern bool queue_flag;

extern _Queue_Algo Queue_Algo;

#endif /* C_Queue */