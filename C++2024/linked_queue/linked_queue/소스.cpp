#include <iostream>

typedef int element;

typedef struct _DequeNode {

	element data;

	_DequeNode* link;

}DequeNode;

typedef struct DequeNodeType {

	DequeNode* front;
	DequeNode* rear;

};

void init_deque(DequeNodeType* s) {

	s->front = s->rear = NULL;
}

void add_front(DequeNodeType* s, element data) {

	DequeNode* tmp = (DequeNode*)malloc(sizeof(DequeNode));
	tmp->data = data;
	if (s->front == NULL && s->rear == NULL) {

		s->front = tmp;
		s->rear = tmp;
		tmp->link = NULL;
	}
	else {
		tmp->link = s->front;
		s->front = tmp;
	}
}

void add_rear(DequeNodeType* s, element data) {

	DequeNode* tmp = (DequeNode*)malloc(sizeof(DequeNode));
	tmp->data = data;
	tmp->link = NULL;
	if (s->front == NULL && s->rear == NULL) {
		s->front = s->rear = tmp;
		
	}
	else {
		s->rear->link = tmp;
		s->rear = tmp;
	}
}

void delete_front(DequeNodeType* s) {

	if (s->front == NULL) {
		return;
	}
	DequeNode* removed = (DequeNode*)malloc(sizeof(DequeNode));
	removed = s->front;
	s->front = s->front->link;
	free(removed);
	if (s->front == NULL) {
		s->rear = NULL;
	}
}

void delete_rear(DequeNodeType* s) {
	if (s->rear == NULL) {
		return;
	}
	DequeNode* removed = s->rear;
	DequeNode* pre = NULL;
	for (DequeNode* p = s->front; p != NULL; p = p->link) {
		if (p->link == s->rear) {
			pre = p;
			break;
		}
	}
	if (pre != NULL) {
		pre->link = NULL;
		s->rear = pre;
	}
	else {
		s->front = s->rear = NULL;
	}
	free(removed);
}

void deque_print(DequeNodeType* s) {




	for (DequeNode* q = s->front ; q != NULL; q = q->link) {

		std::cout << q->data << " |-> ";

	}
	
	std::cout << std::endl;
}


int main() {



		DequeNodeType dq;
		init_deque(&dq);
		for (int i = 0; i < 3; i++) {
			add_front(&dq, i);
			deque_print(&dq);
		}
		for (int i = 0; i < 3; i++) {
			delete_rear(&dq);
			deque_print(&dq);
		}
	
		for (int i = 0; i < 3; i++) {
			add_rear(&dq, i);
			deque_print(&dq);
		}
		for (int i = 0; i < 3; i++) {
			delete_front(&dq);
			deque_print(&dq);
		}

		return 0;




}