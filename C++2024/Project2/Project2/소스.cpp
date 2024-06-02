#include <iostream>

using namespace std;

typedef struct _TreeNode {
	int data;
	struct _TreeNode* left, * right;
} TreeNode;

int get_node_count(TreeNode* node) {
	int count = 0;

	if (node == NULL)
		return  0;
	else if (node->left == NULL && node->right == NULL)
		return  0;

	else
		return (count + 1 + get_node_count(node->left) + get_node_count(node->right));
	
}


	
bool isEqual(TreeNode * p, TreeNode * q){
	if (p == NULL && q == NULL)
		return 1;
	else if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
		return 0;
	}
	else if (p->data == q->data) {
		return ((isEqual(p->left, q->left)) && (isEqual(p->right, q->right)));
	}
	else {
		return 0;
	}

}



int main(void) {

	TreeNode n6 = { 1,NULL,NULL };
	TreeNode n5 = { 2,NULL,NULL };
	TreeNode n4 = { 3, &n6, &n5 };
	TreeNode n3 = { 4, NULL , NULL };
	TreeNode n2 = { 5, NULL , NULL };
	TreeNode n1 = { 6, &n3, &n2 };
	TreeNode n0 = { 7, &n4 , &n1 };
	cout << "테스트 1 : *(비단말 노드의 개수 : ";
	cout << get_node_count(&n0) << endl;
	TreeNode b7 = { 0, NULL , NULL };
	TreeNode b6 = { 1,&b7,NULL };
	TreeNode b5 = { 2,NULL,NULL };
	TreeNode b4 = { 3, &b6, &b5 };
	TreeNode b3 = { 4, NULL , NULL };
	TreeNode b_2 = { 5 , NULL, NULL };
	TreeNode b2 = { 5, &b_2 , NULL };	
	TreeNode b1 = { 6, &b3, &b2 };
	TreeNode b0 = { 7, &b4 , &b1 };
	cout << "테스트 2 : *(비단말 노드의 개수 : ";
	cout << get_node_count(&b0) << endl;
	TreeNode c7 = { 0, NULL , NULL };
	TreeNode c6 = { 1,&c7,NULL };
	TreeNode c5 = { 2,NULL,NULL };
	TreeNode c4 = { 3, &c6, &c5 };
	TreeNode c3 = { 4, NULL , NULL };
	TreeNode c_2l_l = { 5, NULL , NULL };
	TreeNode c_2l = { 5 , &c_2l_l, NULL };
	TreeNode c_2r = { 5 , NULL, NULL };
	TreeNode c2 = { 5, &c_2l , &c_2r };
	TreeNode c1 = { 6, &c3, &c2 };
	TreeNode c0 = { 7, &c4 , &c1 };
	cout << "테스트 3 : *(비단말 노드의 개수 : ";
	cout << get_node_count(&c0) << endl;
	cout << "노드 테스트# 2 : isEqual" << endl;
	cout << "1의 리턴 값 (같은 트리) : " << isEqual(&n0,&n0) << endl;
	cout << "2의 리턴 값 (다른 트리) : " << isEqual(&n0, &b0) << endl;
	cout << "3의 리턴 값 (다른 트리) : " << isEqual(&c0, &b0) << endl;
}