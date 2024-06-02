#include <iostream>

using namespace std;

typedef struct _TreeNode {
	int key;
	struct _TreeNode* left, * right;
} TreeNode;


TreeNode* search(TreeNode* node, int  key)
{
	if (node == NULL)
		return NULL;
	if (key == node->key)
		return node;
	else if (key < node->key)
		return  search(node->left, key);
	else
		return  search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// 왼쪽서브트리
		printf("%d ", root->key); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리
	}
}

void decrement(TreeNode* p) {
	if (p != NULL) {
		decrement(p->left);
		p->key = p->key - 1;
		decrement(p->right);
	}
}


TreeNode* max_value_node(TreeNode* node)
{
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current-> right != NULL)
		current = current->right;

	return current;
}

TreeNode* delete_node(TreeNode* root, int key) { // key 노드 삭제 후 루트 반환
	if (root == NULL) return root;
	if (key < root->key) 			// 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		// 키가 루트보다 크면 오른쪽 서브 트리에 있음
		root->right = delete_node(root->right, key);
	else {				// 키가 루트와 같으면 이 노드를 삭제하면 됨
		if (root->left == NULL) {	// 첫 번째나 두 번째 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// 두 번째 경우
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = max_value_node(root->left); 		// 세 번째 경우
		root->key = temp->key; 				// 직전 키 복사
		root->left = delete_node(root->left, temp->key); 	// 직전 노드 삭제
	}
	return root;
}

int main(void)
{
	TreeNode* root = NULL;
	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n");
	decrement(root);
	printf("1씩 감소한 후 이진 탐색 트리 중위 순회 결과 \n");
		inorder(root);
		printf("\n");
		printf("\n");
	printf("노드 삭제후 중위 순회 결과 (삭제 5 ) \n");
	delete_node(root, 5);
	inorder(root);
	printf("\n");
	printf("\n");
	printf("노드 삭제후 중위 순회 결과 (삭제 55 ) \n");
	delete_node(root, 55);
	printf("\n");
	inorder(root);
	return 0;
}
