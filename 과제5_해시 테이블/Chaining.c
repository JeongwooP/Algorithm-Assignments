#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

int hash[SIZE];
int origin, i = 0;	//origin - ó�� �Է��� ��,
int index;	//�־��� ������ mod 13�� ó�� ������

typedef struct _node {	//��� ����
	int data;
	struct _node * next;
}Node;

Node *chainedHashInsert(Node *table, int hashIndex, int val) {	//ü�̴� ���� �Լ�
	Node *n, *cur;	

	n = (Node*)malloc(sizeof(Node));	//��� �߰�
	n->data = val;
	n->next = NULL;

	if (table[hashIndex].next == NULL) {	//�ƹ��͵� ���� �ε���ĭ�� ���ο� ���� ����
		table[hashIndex].next = n;
		return table;
	}

	cur = table[hashIndex].next;

	n->next = cur;	//���� �����ִ� ĭ �� �տ� ��带 �߰�
	table[hashIndex].next = n;

	return table;
}

int main(){
	Node *table;
	int ins;

	table = (Node*)malloc(SIZE * sizeof(Node));	//�ؽ� ���̺� ����
	
	for (i = 0; i < SIZE; i++) {	//���̺��� ������ NULL�� ����
		table[i].next = NULL;
	}

	while (1) {
		printf("�� �Է�: ");
		scanf("%d", &ins);
		origin = ins;
		index = ins % SIZE;
		table = chainedHashInsert(table, index, ins);	//ü�̴� �ؽ� ���̺� ���� ����
		
		int i;
		Node* cur;

		for (i = 0; i < SIZE; i++) { // ����Ʈ�� ����
			if (table[i].next == NULL) { // ���� �ƹ��͵� �ȵ���ִٸ� �̰��� ���
				printf("Table[%d] is empty\n", i);
				continue;
			}
			cur = table[i].next;
			printf("Table[%d]", i);
			while (cur != NULL) { // �ƴϸ� ����ִ� ���� ������ ���
				printf("->%d", cur->data);
				cur = cur->next; //cur=cur+1 �ؼ� ���� ����Ʈ ���
			}
			printf("\n");
		}
		printf("\n");
	}
}