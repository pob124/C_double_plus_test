#include <iostream>

using namespace std;

typedef int element;

typedef struct _ListNode {

	element data;

	struct _ListNode* link;


} ListNode;


ListNode* insert_first(ListNode* head,element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head=p;
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
	head = head->link;
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

int get_length(ListNode* head) {

	ListNode* p;
	int length;
	length = 0;
	p = head;

	if (head == NULL) {

		return 0;

	}

	else {

		while (p != NULL) {

			p = p->link;
			length += 1;

		}

		return length;
	}

}

int get_sum(ListNode* head) {

	int sum;
	sum = 0;
	for (ListNode* p = head; p != NULL; p = p->link) {

		sum += p->data;

	}
	return sum;

}

element get_max(ListNode* head) {

	element max;
	max = head->data;

	for (ListNode* p = head; p != NULL; p = p->link) {

		if (p->data >= max) {

			max = p->data;

		}

	}
	return max;

}

int _count(ListNode* head, int value) {

	element val = value;
	int cnt = 0;

	for (ListNode* p = head; p != NULL; p = p->link) {

		if (p->data == val) {

			cnt += 1;

		}

	}
	return  cnt;

}




void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {

		cout << p->data << "->";

	}

	cout << "NULL" << endl;

}

ListNode* delete_node(ListNode* head, element value) {

	ListNode* pre = NULL;

	for (ListNode* p = head; p != NULL; ) {

		if (p->data == value) {

			if (pre == NULL || p == head) {
				head = delete_first(head);
				p = head;
				pre = p;
			}

			else if (p->link == NULL) {

				p = _delete(head, pre);
				p = p->link;

			}


			else {

				head = _delete(head, pre);
				p = pre;

			}
		}

		else if ((p->link)->data == value) {

			pre = p;
			p = p->link;
		}


		else {

			p = p->link;
			
		}

		print_list(head);
	}
	return head;
}

int main(void) {

	ListNode* head = NULL;
	ListNode* pre = NULL;

	int count, data , expected_val , del_val;

	cout << "����� ���� : ";

	cin >> count;

	cout << endl << "��� #0 ������: ";

	cin >> data;

	cout << endl;

	head = insert_first(head, data);

	for (int i = 1; i < count; i++) {

		cout << "��� #" << i << "������:";
		cin >> data;
		head = insert_first(head, data);
		cout << endl;

	}

	cout << "������ ���� ����Ʈ :" ;
	print_list(head);
	cout << endl << "ã���� �ϴ� �� : ";
	cin >> expected_val;
	cout << endl << "����� ���� : " << get_length(head);
	cout << endl << "����� �� : " << get_sum(head);
	cout << endl << "max �� : " << get_max(head);
	cout << endl << "ã�� ���� ���� : " << _count(head,expected_val);
	cout << endl << "�����ϰ� ���� �� : ";
	cin >> del_val;
	head = delete_node(head, del_val);
	
	return 0;
}