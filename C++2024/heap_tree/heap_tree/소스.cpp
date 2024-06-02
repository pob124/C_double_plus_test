#include <iostream>
#include <stdlib.h>
#define MAXQUEUESIZE 50
#define MAX_ELEMENT 200
using namespace std;

typedef struct _freq{

	char* character;
	int*  freq;
	int length;
}frequency;


typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

typedef struct _Node {
	char character;
	int frequency;
	struct _Node* left;
	struct _Node* right;
} Node;

typedef struct {
	Node* nodes[MAXQUEUESIZE];
	int size;
} PriorityQueue;

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {

	int i;
	i = ++(h->heap_size); // 힙 크기를 하나 증가

	/* 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 */
	// i가 루트 노트(index: 1)이 아니고, 삽입할 item의 값이 i의 부모 노드(index: i/2)보다 크면
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		// i번째 노드와 부모 노드를 교환환다.
		h->heap[i] = h->heap[i / 2];
		// 한 레벨 위로 올라단다.
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입

}

element delete_max_heap(HeapType* h) {

		int parent, child;
		element item, temp;

		item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
		temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
		parent = 1;
		child = 2;

		while (child <= h->heap_size) {
			// 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
			if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
				child++;
			}
			// 더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
			if (temp.key >= h->heap[child].key) {
				break;
			}

			// 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
			h->heap[parent] = h->heap[child];
			// 한 단계 아래로 이동
			parent = child;
			child *= 2;
		}

		// 마지막 노드를 재구성한 위치에 삽입
		h->heap[parent] = temp;
		// 최댓값(루트 노드 값)을 반환
		return item;

}

void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}

int findKthLargest( element arr[], int size, int k) {

	int i;
	HeapType* h;
	element result;
	h = create();
	init(h);
	for (i = 0; i < size; i++) {
		insert_max_heap(h, arr[i]);
	}
	for (int j = 0; j < k; j++) {
		result = delete_max_heap(h);
	}
	return result.key;
}

Node* createNode(char character, int frequency, Node* left, Node* right) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->character = character;
	node->frequency = frequency;
	node->left = left;
	node->right = right;
	return node;
}
// 빈 우선순위 큐를 생성하여 반환
PriorityQueue* createPriorityQueue() {
	PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	queue->size = 0;
	return queue;
}

// 빈도 내림차순 배열의 적절한 위치에 새 노드 삽입
void enqueue(PriorityQueue* queue, Node* node) {
	if (queue->size >= MAXQUEUESIZE) {
		printf("Queue is full.\n");
		return;
	}
	int i = queue->size;
	while (i > 0 && node->frequency < queue->nodes[i - 1]->frequency) {
		queue->nodes[i] = queue->nodes[i - 1];
		i--;
	}
	queue->nodes[i] = node;
	queue->size++;
}

// 빈도 내림차순 배열에서 마지막 노드를 꺼내서 반환
Node* dequeue(PriorityQueue* queue) {
	if (queue->size <= 0) {
		printf("Queue is empty.\n");
		return NULL;
	}
	queue->size--;
	return queue->nodes[queue->size];
}

// 우선순위 큐로부터 허프만 트리를 생성하여 반환
Node* buildHuffmanTree(PriorityQueue* queue) {
	while (queue->size >= 2) {
		Node* node1 = dequeue(queue);
		Node* node2 = dequeue(queue);

		// 꺼낸 두 노드의 빈도를 합한 새 노드를 우선순위 큐에 삽입
		Node* mergedNode = createNode('$', node1->frequency + node2->frequency, node1, node2);
		enqueue(queue, mergedNode);
		printf("%d+%d->%d \n", node1->frequency, node2->frequency, mergedNode->frequency);
	}
	return dequeue(queue); // 우선순위 큐가 공백이 됨
}
// 허프만 트리를 기반으로 허프만 코드를 출력하는 순환함수
// 현재 root와 직전까지 모아온 코드를 받음. 코드길이도 같이 받음.
void generateHuffmanCodes(Node* root, int code, int length) {
	// 리프이면 직전까지 모아온 코드를 출력
	if (root->left == NULL && root->right == NULL) {
		printf("%c: ", root->character);
		for (int i = length - 1; i >= 0; i--) {
			printf("%d", (code >> i) & 1);
		}
		printf("\n");
		return;
	}
	// 리프가 아니면 왼 자식의 code엔 0을, 오른 자식의 code엔 1을 덧붙임
	generateHuffmanCodes(root->left, code << 1, length + 1);
	generateHuffmanCodes(root->right, (code << 1) | 1, length + 1);
}

frequency get_frequency(char arr[], int size) {
	frequency char_n_freq;
	int* freq_arr = (int*)malloc(256 * sizeof(int));
	char* freq_char = (char*)malloc(256 * sizeof(char));
	int k = 0;

	for (int i = 0; i < size; i++) {
		int freq = 0;
		int stop = 0;
		char a = tolower(arr[i]);
		for (int q = 0; q < k; q++) {
			if (a == freq_char[q]) {
				stop = 1;
				break;
			}
		}
		if (stop == 1 || a == ' ') {
			continue;
		}
		for (int j = 0; j < size; j++) {
			char b = tolower(arr[j]);
			if (a == b) {
				freq++;
			}
		}
		freq_arr[k] = freq;
		freq_char[k] = a;
		k++;
	}
	freq_arr = (int*)realloc(freq_arr, k * sizeof(int));
	freq_char = (char*)realloc(freq_char, k * sizeof(char));
	char_n_freq.freq = freq_arr;
	char_n_freq.character = freq_char;
	char_n_freq.length = k;
	return char_n_freq;
}

void printTopKFrequentElements(char arr[], int k) {

	frequency ex_freq = get_frequency(arr, strlen(arr));;

	PriorityQueue* ex_queue = createPriorityQueue();

	for (int i = 0; i < ex_freq.length; i++) {
		Node* temp_node = createNode(ex_freq.character[i], ex_freq.freq[i], NULL, NULL);
		enqueue(ex_queue, temp_node);
	}
	printf("----------------------------------------------\n");
	for (int i = 0; i < k; i++) {
		Node* temp_node = dequeue(ex_queue);
		printf("문자 : %c 빈도수 %d\n", temp_node->character, temp_node->frequency);
	}
	printf("----------------------------------------------\n");
	free(ex_queue);
	free(ex_freq.character);
	free(ex_freq.freq);
}

int main(void) {
	element arr[] = { 5, 9, 2, 7, 1, 6 };
	element arr1[] = { 5, 9, 2, 7, 1, 6 , 4 ,5 , 10 , 51 , 100};
	element arr2[] = { 12,14,26,38,29,40,55,57,8,66 };
	char ex_str[] = "Outmanned and outgunned:";
	char ex_str1[] = "Red Zepplin , Guns and Roses , Queen :)";
	char ex_str2[] = "sykim gsyang jgann mhkim sgkim";
	int k = 3;    // k번째로 큰 요소

	/*  heap에 arr 원소들을 하나씩 삽입 한 후
		 큰 순서로 k 개를 꺼내되, k 번째 요소를 반환  */
	int kthLargest = findKthLargest(arr, 6, 3);
	int kthLargest1 = findKthLargest(arr1, sizeof(arr1) / sizeof(element), 3);
	int kthLargest2 = findKthLargest(arr2, sizeof(arr2) / sizeof(element), 3);
	printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest);
	printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest1);
	printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest2);


	printTopKFrequentElements(ex_str, 3);
	printTopKFrequentElements(ex_str1, 3);
	printTopKFrequentElements(ex_str2, 3);
}