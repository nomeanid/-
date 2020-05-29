#include <stdio.h>
#include <stdlib.h>
#include "q.h"



void init_queue(ListLinQueue* q)
{
	q->front = q->rear = NULL;
}

int is_empty(ListLinQueue* q)
{
	return (q->front == NULL);
}


// ���� �Լ�
void enqueue(ListLinQueue* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; 		// ������ ����
	temp->link = NULL; 		// ��ũ �ʵ带 NULL
	if (is_empty(q)) { 		// ť�� �����̸�
		q->front = temp;
		q->rear = temp;
	}
	else { 		// ť�� ������ �ƴϸ�
		q->rear->link = temp;  // ������ �߿�
		q->rear = temp;
	}
}

// ���� �Լ�
element dequeue(ListLinQueue* q)
{
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {		// �������
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data; 	// �����͸� ������.
		q->front = q->front->link; // front�� �������
		if (is_empty(q)) 	// ���� ����
			q->rear = NULL;
		free(temp); 		// �����޸� ����
		return data; 		// ������ ��ȯ
	}
}