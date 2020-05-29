typedef int element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// 큐 ADT 구현
	QueueNode* front, * rear;
} ListLinQueue;

void init_queue(ListLinQueue* q);
int is_empty(ListLinQueue* q);
void enqueue(ListLinQueue* q, element data);
element dequeue(ListLinQueue* q);
