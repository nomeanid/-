typedef int element;	// ����� Ÿ��
typedef struct QueueNode {	// ť�� ����� Ÿ�� 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// ť ADT ����
	QueueNode* front, * rear;
} ListLinQueue;

void init_queue(ListLinQueue* q);
int is_empty(ListLinQueue* q);
void enqueue(ListLinQueue* q, element data);
element dequeue(ListLinQueue* q);
