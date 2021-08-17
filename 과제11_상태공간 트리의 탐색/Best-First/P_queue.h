#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <stdint.h>
#include <stdbool.h>

/*노드들과 우선순위 큐 구조체들 선언*/
typedef struct _Node {
	int   level;      /* 트리의 레벨 */
	int   profit;	  /* 이익 */
	int   weight;	  /* 무게 */
	float bound;	  /* 한계 */
} Node;

typedef struct _Queue {
	int  front, rear;
	int  length;
	Node *data;
} Queue;

typedef struct _Priority_Queue_Algo {
	void(*Create)(Queue *, int);
	void(*Delete)(Queue);

	bool(*Is_Empty)(Queue);
	bool(*Is_Full)(Queue);

	void(*Insert)(Queue *, Node);
	void(*Remove)(Queue *, Node *);
} _Priority_Queue_Algo;

extern _Priority_Queue_Algo Priority_Queue_Algo;

#endif /* P_QUEUE */