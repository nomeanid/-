#include <stdio.h>
#include <stdbool.h>
#include "q.h"

#define MAX_NODE 5

int adj_mat[MAX_NODE][MAX_NODE] = {
	0,1,1,0,1,
	1,0,1,0,0,
	1,1,0,1,1,
	0,0,1,0,1,
	1,0,1,1,0
};
bool visited[MAX_NODE];

void init(void) {

	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
	}
}

// ���� ��ķ� ǥ���� �׷����� ���� ���� �켱 Ž��
void dfs_mat(int v) {

	visited[v] = true;		// ���� v�� �湮 ǥ�� 
	printf("���� %d �湮\n", v);		// �湮�� ���� ���
	for (int w = 0; w < MAX_NODE; w++) { 		// ���� ���� Ž��
		if (adj_mat[v][w] && !visited[w]) {
			dfs_mat(w);	//���� w���� DFS ���� ����
			continue;
		}
		if (adj_mat[v][w] && visited[w])
			printf("\t���� %d���� Ž��: ���� %d�� �̹� �湮����\n", v, w);
	}
}

void bfs_mat(int v) {

	ListLinQueue q;
	init_queue(&q);     			// ť �ʱ�ȭ 
	visited[v] = true;        		// ���� v �湮 ǥ�� 
	printf("���� %d �湮\n", v);
	enqueue(&q, v);			// ���� ������ ť�� ���� 
	while (!is_empty(&q)) {
		v = dequeue(&q);	// ť�� ���� ���� 
		for (int w = 0; w < MAX_NODE; w++) { // ���� ���� Ž�� 
			if (adj_mat[v][w] && !visited[w]) {
				visited[w] = true;	// �湮 ǥ��
				printf("���� %d �湮\n", w);
				enqueue(&q, w); 	// �湮�� ������ ť�� ����
				continue;
			}
			if (adj_mat[v][w] && visited[w]) {
				printf("���� %d���� Ž��: ���� %d�� �̹� �湮����\n", v, w);
			}
		}
	}
}


int main(void) {
	//init();
	//printf("���� �켱 Ž��\n");
	//dfs_mat(0);
	init();
	printf("\n�ʺ� �켱 Ž��\n");
	bfs_mat(0);
	printf("\n");
	return 0;
}
