#include <iostream>

using namespace std;

typedef int element;

typedef struct _ListNode {

	element data;

	struct _ListNode* link;


} ListNode;


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

ListNode* get_max(ListNode* head) {

	element max;
	max = head->data;
	ListNode* pre = head;
	for (ListNode* p = head; p != NULL; p = p->link) {

		if (p->data > max) {

			max = p->data;
			pre = p;
		}
		
	}
	return pre;

}
ListNode* get_min(ListNode* head) {

	element min;
	min = head->data;
	ListNode* pre =head;

	for (ListNode* p = head; p != NULL; p = p->link) {

		if (min > p->data) {

			min = p->data;
			pre = p;
		}

	}
	return pre;

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
	int del_node_count;
	del_node_count = _count(head, value);

	for (ListNode* p = head; p != NULL; ) {

		if (del_node_count == 0) {

			break;

		}

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

			del_node_count -= 1;
		}

		else if ((p->link)!= NULL && (p->link)->data == value) {

			pre = p;
			p = p->link;
		}


		else {

			p = p->link;

		}
	}

	return head;
}

ListNode* search_list(ListNode* head, element x) {

	ListNode* p = head;

	while (p != NULL) {

		if (p->data == x) return p;
		p = p->link;


	}
	return head;

}

ListNode* connect_list(ListNode* list1, ListNode* list2) {

	if (list1 == NULL || list2 == NULL) {

		if (list1 == NULL) return list2;
		else if (list2 == NULL) return list1;

		else {
			cout << endl << "빈 리스트 입니다";
			return NULL;

		}

	}

	else {

		ListNode* p;
		p = list1;
		while (p->link != NULL) {

			p =  p->link;

		}
		p->link = list2;
		return list1;
	}
}

ListNode* reverse(ListNode* head) {
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;
	p = head;         // p는 역순으로 만들 리스트
	q = NULL;        // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q;		// r은 역순으로 된 리스트 
		q = p;	 	// r은 q, q는 p를 차례로 따라간다
		p = p->link;
		q->link = r;      	// q의 링크 방향을 바꾼다
	}
	return q;
}

ListNode* copy_list(ListNode* head) {

	ListNode* coped_head = NULL;

	for (ListNode* p = head; p != NULL; p = p->link) {

		coped_head = insert_first(coped_head, p->data);

	}

	return coped_head;
}

ListNode* sort_list(ListNode* head) {

	ListNode* coped_head = NULL;
	ListNode* sorted_head = NULL;
	ListNode* max_node;	

	coped_head = copy_list(head);


	while (coped_head != NULL) {

		int max_count;
		int node_data;
		max_node = get_max(coped_head);
		max_count = _count(coped_head, max_node->data);
		node_data = max_node->data;
		coped_head = delete_node(coped_head, node_data);

		while (max_count != 0) {

			sorted_head = insert_first(sorted_head, node_data);
			max_count -= 1;
		}
	}
	return sorted_head;
}

ListNode* extract_odd(ListNode* head) {

	ListNode* new_head =NULL;

	for (ListNode* p = head; p != NULL; p = p->link) {

		if (p->data % 2 == 1) {

			new_head = insert_first(new_head,p->data);

		}

	}

	return new_head;

}

ListNode* merge(ListNode* list1, ListNode* list2) {

	ListNode* coped_list1 = copy_list(list1);
	ListNode* coped_list2= copy_list(list2);

	coped_list1 = connect_list(coped_list1, coped_list2);
	return coped_list1;
}


//




int main(void) {

	ListNode* head = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;
	ListNode* merging_head = NULL;
	ListNode* to_ten_head = NULL;
	ListNode* odd_list = NULL;
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	head2 = insert_first(head2, 10);
	print_list(head2);
	head2 = insert_first(head2, 20);
	print_list(head2);
	head2 = insert_first(head2, 30);
	print_list(head2);

	for (int i = 1; i <= 10; i++) to_ten_head = insert_first(to_ten_head, i);

	if (search_list(head, 30) != NULL)
		printf("리스트에서 30을 찾았습니다. \n");
	else
		printf("리스트에서 30을 찾지 못했습니다. \n");

	head = connect_list(head, head2);

	cout << "연결된 리스트 : ";
	print_list(head);

	cout << endl;

	head = reverse(head);
	cout << "역순의 리스트 : ";
	print_list(head);
	head3 = get_max(head);
	cout << endl << "최댓값 : " << head3->data;
	print_list(head3);
	head = sort_list(head);
	print_list(head);
	print_list(head2);
	head2 = sort_list(head2);
	merging_head = merge(head, head2);
	cout << "병합된 리스트 : ";
	print_list(merging_head);

	odd_list = extract_odd(to_ten_head);
	to_ten_head = sort_list(to_ten_head);

	cout << "추출된 리스트 : ";
	print_list(odd_list);
	cout << "원래 리스트 : ";
	print_list(to_ten_head);
	return 0;


}