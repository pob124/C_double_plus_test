#include <iostream>
#include <cmath>
using namespace std;

typedef struct _ListNode {
	int coef;
	int expon;
	struct _ListNode* link;

}ListNode;

typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(const char* message) {

	cerr << message << endl;
	exit(1);

}

ListType* create() {

	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {

	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		
		plist->tail->link = temp;
		plist->tail = temp;

	}
	plist->size++;
}

void insert_first(ListType* plist, int coef, int expon) {

	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->head == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		
		temp->link = plist->head;
		plist->head = temp;

	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {

	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;

		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_print(ListType* plist)
{
	ListNode* p;

	cout << "polynomial= ";
	for (p = plist->head; p != NULL; p = p->link) {

		if (p->coef < 0) {

			cout <<  p->coef << "x^" << p->expon << "+ ";
		}
		else {
			cout << p->coef << "x^" << p->expon << "+ ";
		}
	}
	cout << endl;
}

int poly_eval(ListType* plist, int x)
{
	int	result = 0;

	for (ListNode* p = plist->head; p != NULL; p = p->link) {

		result += p->coef * pow(p->expon, x);

	}
	return result;
}

void add_item(ListType* plist, int coef, int expon) {

	ListNode* pre =NULL;

	if (plist->head == NULL) {

		insert_first(plist,coef, expon);
		return;
	}

	for (ListNode* p = plist->head; p != NULL; p = p->link) {
		if (p->expon == expon) {
			p->expon += expon;
			return;
		}

		else if (expon > p->expon) {
			if (p == plist->head){			
				insert_first(plist, coef, expon);
			}
			else {
				ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
				temp->coef = coef;
				temp->expon = expon;
				pre->link = temp;
				temp->link = p;
				plist->size++;
			}
			return;
		}
		else if ((p == plist->tail) && (expon < p->expon)) {

			insert_last(plist, coef, expon);
			return;
		}
		else if ((p == plist->tail) && (expon > p->expon)) {

			insert_last(plist, coef, expon);
			return;
		}
		pre = p;
	}
}

void poly_mul(ListType* plist1, ListType* plist2, ListType* plist3) {



	for (ListNode* p = plist2->head; p != NULL; p = p->link) {

		for (ListNode* q = plist1->head; q != NULL; q = q->link) {

			if (plist1->head == NULL || plist2->head == NULL) error("빈 헤더 오류");

			add_item(plist3, p->coef * q->coef, p->expon + q->expon);

		}


	}

}


int main(void) {
	ListType* list1, * list2, * list3 ,*mul_list;
	int x;
	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	mul_list = create();

	// 다항식 1을 생성 
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	cout << "x의 값은? : ";
	cin >> x;
	cout<< endl << "x에 대한 다항식의 값 : " << poly_eval(list3, x);
	add_item(list1,7,-1);
	poly_print(list1);
	poly_mul(list1, list2, mul_list);
	poly_print(mul_list);
	free(list1); free(list2); free(list3);
}