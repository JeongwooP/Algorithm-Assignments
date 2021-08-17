#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

int hash[SIZE];
int origin, i = 0;	//origin - 처음 입력한 값,
int index;	//주어진 값에서 mod 13한 처음 나머지

typedef struct _node {	//노드 선언
	int data;
	struct _node * next;
}Node;

Node *chainedHashInsert(Node *table, int hashIndex, int val) {	//체이닝 삽입 함수
	Node *n, *cur;	

	n = (Node*)malloc(sizeof(Node));	//노드 추가
	n->data = val;
	n->next = NULL;

	if (table[hashIndex].next == NULL) {	//아무것도 없는 인덱스칸은 새로운 원소 삽입
		table[hashIndex].next = n;
		return table;
	}

	cur = table[hashIndex].next;

	n->next = cur;	//기존 원소있는 칸 맨 앞에 노드를 추가
	table[hashIndex].next = n;

	return table;
}

int main(){
	Node *table;
	int ins;

	table = (Node*)malloc(SIZE * sizeof(Node));	//해시 테이블 생성
	
	for (i = 0; i < SIZE; i++) {	//테이블의 헤드들을 NULL로 설정
		table[i].next = NULL;
	}

	while (1) {
		printf("값 입력: ");
		scanf("%d", &ins);
		origin = ins;
		index = ins % SIZE;
		table = chainedHashInsert(table, index, ins);	//체이닝 해시 테이블 원소 삽입
		
		int i;
		Node* cur;

		for (i = 0; i < SIZE; i++) { // 리스트의 각각
			if (table[i].next == NULL) { // 만약 아무것도 안들어있다면 이것을 출력
				printf("Table[%d] is empty\n", i);
				continue;
			}
			cur = table[i].next;
			printf("Table[%d]", i);
			while (cur != NULL) { // 아니면 들어있는 원소 값들을 출력
				printf("->%d", cur->data);
				cur = cur->next; //cur=cur+1 해서 여러 리스트 출력
			}
			printf("\n");
		}
		printf("\n");
	}
}