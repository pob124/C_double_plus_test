#include <iostream>
#define MAX_NAME_SIZE 100
using namespace std;

typedef struct {

	char name[MAX_NAME_SIZE];
	double height;
	int age;

}element;


typedef struct _ListNode {

	element data;
	struct _ListNode* link;


}ListNode;

void error(char* message) {

	cerr << endl <<message;
	exit(1);

}

void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link) {

		cout << p->data.name << " : " << "Å°(" << p->data.height << " )" << " , ³ªÀÌ(" << p->data.age << ") -> ";
		
	}
	cout << endl;
}

ListNode* insert_first(ListNode* head, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;

}


ListNode* delete_first(ListNode* head) {

	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* _delete(ListNode* head, ListNode* pre) {

	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}



int main(void) {

	ListNode* head = NULL;

	element data;

	strcpy_s(data.name, "choi");

	data.age = 30;

	data.height = 1.3;

	head = insert_first(head, data);

	strcpy_s(data.name, "lee");

	data.age = 48;

	data.height = 1.4;

	head = insert_first(head, data);

	strcpy_s(data.name, "park");

	data.age = 27;

	data.height = 1.2;

	head = insert_first(head, data);

	strcpy_s(data.name, "kim");

	data.age = 34;

	data.height = 1.7;

	head = insert_first(head, data);

	print_list(head);


}