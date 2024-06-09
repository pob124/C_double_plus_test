#include <iostream>
#include <stdlib.h>
#include <windows.h>
#define MAXQUEUESIZE 50
#define MAXSCHEDULES 50
#define MAX_ELEMENT 200
using namespace std;

typedef struct _freq{
	char* character;
	int*  freq;
	int length;
}frequency;


typedef struct _schedule {

	int processTime;
	int reachTime;

}schedule;


typedef struct element {
	int key;
	int machineNum;
	schedule schedules[MAXSCHEDULES]; int schedSize;
	int processingTime; int totalProcessingTime;
	int recentEndProcess;
	int compelteTime;
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
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		// i번째 노드와 부모 노드를 교환환다.
		h->heap[i] = h->heap[i / 2];
		// 한 레벨 위로 올라단다.
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입

}


void insert_min_heap(HeapType* h, element item) {

	int i;
	i = ++(h->heap_size); // 힙 크기를 하나 증가

	/* 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정 */
	// i가 루트 노트(index: 1)이 아니고, 삽입할 item의 값이 i의 부모 노드(index: i/2)보다 크면
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
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

element delete_m_heap(HeapType* h) {

	int parent, child;
	element item, temp;

	item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
	temp = h->heap[(h->heap_size)--]; // 마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
		if ((child < h->heap_size) && ((h->heap[child].key) > h->heap[child + 1].key)) {
			child++;
		}
		// 더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
		if (temp.key < h->heap[child].key) {
			break;
		}

		// 더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;

		// 한 단계 아래로 이동

	}

	// 마지막 노드를 재구성한 위치에 삽입

	h->heap[parent] = temp;

	for (int i = 1; i <= h->heap_size; i++) {

		if (h->heap[i].key == h->heap[i - 1].key && (h->heap[i].machineNum < h->heap[i-1].machineNum && (h->heap[i].key == 0))) {
			element temp_element1 = h->heap[i];
			element temp_element2 = h->heap[i-1];
			h->heap[i] = temp_element2;
			h->heap[i-1] = temp_element1;
		}


	}

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
//---------------------------------------24.06.06--------------------------------------------------//

HeapType* creatingMachines(int numOfMachines) {

		HeapType* machine_heap = create();
		init(machine_heap);
		for (int i = 1; i <= numOfMachines; i++) { //기계 힙 트리 구현
			element machine;
			machine.machineNum = i;
			machine.schedSize = 0; //SJF 에서 구현할 예정
			machine.key = 0; //schedule의 총합
			insert_min_heap(machine_heap, machine);
		}
		return machine_heap;
}

HeapType* creatingMachines_LPT(int numOfMachines) {

	HeapType* machine_heap = create();
	init(machine_heap);
	for (int i = 1; i <= numOfMachines; i++) { //기계 힙 트리 구현
		element machine;
		machine.machineNum = i;
		machine.schedSize = 0; //SJF 에서 구현할 예정
		machine.key = 0; //schedule의 총합
		insert_min_heap(machine_heap, machine);
	}
	return machine_heap;
}

void sortSchedules_LPT(schedule schedules[], int size) {
	for (int i = 1; i < size; i++) {
		schedule key = schedules[i];
		int j = i - 1;
		while (j >= 0 && schedules[j].processTime < key.processTime) {
			schedules[j + 1] = schedules[j];
			j = j - 1;
		}
		schedules[j + 1] = key;
	}
}

float averageWatingTimeLPT(int jobs[], int numOfJobs, int numOfMachines) {

	HeapType* machine_heap = creatingMachines_LPT(numOfMachines);
	float sum = 0.0;

	for (int i = 0; i < numOfJobs; i++) {
		//cout << "삽입전 기계 트리 : " << endl;
		//for (int j = 1; j <= machine_heap->heap_size; j++) {
		//	element temp_machine = machine_heap->heap[j];
		//	cout << "기계 번호 : (" << temp_machine.machineNum << ") ";

	//	}
		//cout << endl;
	//	cout << endl;



		element shortMachine = delete_m_heap(machine_heap);
		//cout << "제거후 기계 트리 :" << endl;
		//for (int j = 1; j <= machine_heap->heap_size; j++) {
		//	element temp_machine = machine_heap->heap[j];
		//	cout << "기계 번호 : (" << temp_machine.machineNum << ") ";

		//}
		//cout << endl;
		shortMachine.schedules[shortMachine.schedSize++].processTime = jobs[i];
		shortMachine.key += jobs[i];
		insert_min_heap(machine_heap, shortMachine);  //작업 기계 삽입
		//cout << "삽입후 기계 트리 : " << endl;
		//for (int j = 1; j <= machine_heap->heap_size; j++) {
		//	element temp_machine = machine_heap->heap[j];
		//	cout << "기계 번호 : (" << temp_machine.machineNum << ") ";

		//}
		//cout << endl;
		//cout << endl;

	}

	for (int i = 1; i <= machine_heap->heap_size; i++) {
		element machines = machine_heap->heap[i];
		cout << "기계(" << machines.machineNum << ") 의 정렬전  스케쥴 :";
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
		}
		sortSchedules_LPT(machines.schedules, machines.schedSize);
		cout << endl <<"기계(" << machines.machineNum << ") 의 정렬후 스케쥴 :";
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
			if (j >= 1) {
				sum += machines.schedules[j-1].processTime * (machines.schedSize - (j));
			}
		}
		cout<< endl  << "----------------------------------------------------" << endl;
	}
	cout << sum << endl;
	return sum / numOfJobs ;

}

float averageTurnaroundTime(int jobs[], int numOfJobs, int numOfMachines) {
	cout << endl << "----------------------------------------------------" << endl;
	HeapType* machine_heap = creatingMachines_LPT(numOfMachines);
	float sum = 0.0;
	for (int i = 0; i < numOfJobs; i++) {
		element shortMachine = delete_m_heap(machine_heap);
		shortMachine.schedules[shortMachine.schedSize++].processTime = jobs[i];
		shortMachine.key += jobs[i];
		insert_min_heap(machine_heap, shortMachine);  //작업 기계 삽입
	}
	for (int i = 1; i <= machine_heap->heap_size; i++) {
		element machines = machine_heap->heap[i];
		cout << "기계(" << machines.machineNum << ") 의 정렬전  스케쥴 :" << endl;
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
		}
		sortSchedules_LPT(machines.schedules, machines.schedSize);
		cout << endl << "기계(" << machines.machineNum << ") 의 스케쥴" << endl;
		int temp_sum = 0.0;
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
			temp_sum +=  machines.schedules[j].processTime;
			sum += temp_sum;
		}
		cout << endl << "----------------------------------------------------" << endl;
	}
	cout << sum << endl;
	return (sum / numOfJobs);


}

int completionTime(int jobs[], int numOfJobs, int numOfMachines) {
	cout << endl << "----------------------------------------------------" << endl;
	HeapType* machine_heap = creatingMachines_LPT(numOfMachines);
	int whoIsMax = 0;
	int maxMachineNumber = 0;
	for (int i = 0; i < numOfJobs; i++) {
		element shortMachine = delete_m_heap(machine_heap);
		shortMachine.schedules[shortMachine.schedSize++].processTime = jobs[i];
		shortMachine.key += jobs[i];
		insert_min_heap(machine_heap, shortMachine);  //작업 기계 삽입
	}
	for (int i = 1; i <= machine_heap->heap_size; i++) { //numOfMachines 와 같음
		
		element machines = machine_heap->heap[i];
		cout << "기계(" << machines.machineNum << ") 의 정렬전  스케쥴 :" << endl;
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
		}
		
		sortSchedules_LPT(machines.schedules, machines.schedSize);
		cout <<endl << "기계(" << machines.machineNum << ") 의 정렬후 스케쥴: " << endl;
		int temp_sum = 0;
		for (int j = 0; j < machines.schedSize; j++) {
			cout << machines.schedules[j].processTime << " ";
			temp_sum += machines.schedules[j].processTime;
		}
		if (whoIsMax < temp_sum) {
			whoIsMax = temp_sum;
			maxMachineNumber = machines.machineNum;
		}
		cout <<endl << "----------------------------------------------------" << endl;
	}
	cout << "MAX COMPLETION TIME : MACHINE (" << maxMachineNumber << ") " << endl;
	return whoIsMax;


}
void testingLPT(int jobs[], int numOfJobs, int numOfMachines) {
	cout << "------------------ LPT(LONGEST PROCESSING TIME) 기법 TEST ----------------------" << endl;
	cout << "AVERAGE  WAITING TIME : " << averageWatingTimeLPT(jobs, numOfJobs, numOfMachines) << endl;
	cout << "AVERAGE TURN TIME :  " << averageTurnaroundTime(jobs, numOfJobs, numOfMachines) << endl;
	cout << "COMPLETE TIME : " << completionTime(jobs, numOfJobs, numOfMachines) << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}

void sortSchedules(schedule schedules[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (schedules[i].processTime > schedules[j].processTime) {
                schedule temp = schedules[i];
                schedules[i] = schedules[j];
                schedules[j] = temp;
            }
        }
    }
}

float averageWatingTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {
	HeapType* machine_heap = creatingMachines(numOfMachines);
	int totalTime = 0;
	float result = 0;
	cout << "-----------------------------------------------------" << endl;

	for (int i = 1; i <= machine_heap->heap_size; i++) {
		element temp_machine = machine_heap->heap[i];
		cout << "기계 번호 : (" << temp_machine.machineNum << ") ";

	}
	cout << endl;
	for (int i = 0; i < numOfJobs; i++) {
		if (i < numOfMachines) {
			element shortMachine = delete_m_heap(machine_heap);
			shortMachine.schedules[0].processTime = jobs[i];
			shortMachine.totalProcessingTime = 0;
			shortMachine.processingTime = 0;
			shortMachine.schedules[0].reachTime = i;
			shortMachine.schedSize = 1; 
			shortMachine.key = jobs[i];

			for (int j = 0; j < numOfMachines; j++) {
				if (machine_heap->heap[j + 1].key != 0) {
					machine_heap->heap[j + 1].processingTime++;
					machine_heap->heap[j + 1].totalProcessingTime++;
					machine_heap->heap[j + 1].key--;
				}
			}
			insert_min_heap(machine_heap, shortMachine);
		}
		else {
			for (int j = 0; j < numOfMachines; j++) {
				if (machine_heap->heap[j + 1].processingTime == machine_heap->heap[j + 1].schedules[0].processTime) {
					machine_heap->heap[j + 1].recentEndProcess = machine_heap->heap[j + 1].schedules[0].processTime;
					int temp_size = --machine_heap->heap[j + 1].schedSize;
					for (int k = 0; k < temp_size; k++) {
						machine_heap->heap[j + 1].schedules[k] = machine_heap->heap[j + 1].schedules[k + 1];
					}

					sortSchedules(machine_heap->heap[j + 1].schedules, temp_size);

					machine_heap->heap[j + 1].processingTime = 0;
					element machineSort = delete_m_heap(machine_heap);
					insert_min_heap(machine_heap, machineSort);
				}
			}

			element shortMachine = delete_m_heap(machine_heap);
			shortMachine.schedules[shortMachine.schedSize].processTime = jobs[i];
			shortMachine.schedules[shortMachine.schedSize].reachTime = i;
			shortMachine.key += jobs[i];
			shortMachine.schedSize++;
			insert_min_heap(machine_heap, shortMachine);

			for (int k = 0; k < numOfMachines; k++) {
				machine_heap->heap[k + 1].processingTime++;
				machine_heap->heap[k + 1].key--;
				machine_heap->heap[k + 1].totalProcessingTime++;
			}
		}
		totalTime++;
	}

	for (int i = 0; i < numOfMachines; i++) {
		if (machine_heap->heap[i + 1].schedSize != 0) {
			element temp_element = machine_heap->heap[i + 1];
			int size = temp_element.schedSize;
			if (machine_heap->heap[i + 1].processingTime == machine_heap->heap[i + 1].schedules[0].processTime) {
				if (machine_heap->heap[i + 1].recentEndProcess > 0) {
					result += machine_heap->heap[i + 1].totalProcessingTime - machine_heap->heap[i + 1].schedules[0].reachTime;
				}
				machine_heap->heap[i + 1].recentEndProcess = machine_heap->heap[i + 1].schedules[0].processTime;
				int temp_size = --machine_heap->heap[i + 1].schedSize;
				for (int k = 0; k < temp_size; k++) {
					machine_heap->heap[i + 1].schedules[k] = machine_heap->heap[i + 1].schedules[k + 1];
				}
				machine_heap->heap[i + 1].processingTime = 0;
				sortSchedules(temp_element.schedules, temp_size);// 스케쥴 정렬
			}
			temp_element = machine_heap->heap[i + 1];

			size = temp_element.schedSize;
			cout << "기계 (" << temp_element.machineNum << ")의 스케쥴: ";

			if (size == 1 && (temp_element.recentEndProcess >0)) {
				result += temp_element.recentEndProcess - temp_element.schedules[0].reachTime;
			}

			
			for (int j = 0; j < size; j++) {
				if (j >= 1) {
					if (temp_element.recentEndProcess > 0) {
						result += temp_element.recentEndProcess + (temp_element.schedules[size - (j + 1)].processTime) * (size - j) - temp_element.schedules[size - (j + 1)].reachTime;
					}
					else {
						result += (temp_element.schedules[size - (j + 1)].processTime) * (size - j) - temp_element.schedules[size - (j + 1)].reachTime;
					}
				}
				cout << temp_element.schedules[j].processTime << " ";
			}
			cout << endl << "전체 흐른 시간: " << temp_element.totalProcessingTime << endl;
			cout << "현재 작업의 진행시간: " << temp_element.processingTime << " / " << temp_element.schedules[0].processTime << " REACHTIME: " << temp_element.schedules[0].reachTime << endl;
			if (temp_element.recentEndProcess > 0) {
				cout << "RECENTLY ENDED: " << temp_element.recentEndProcess << endl;
			}
			else {
				cout << "RECENTLY ENDED: NONE" << endl;
			}
		}
		cout << "-----------------------------------------------------" << endl;
	}
	cout << "TOTAL TIME : " << result << endl;
	return result / numOfJobs;
}

float averageTurnaroundTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {
	HeapType* machine_heap = creatingMachines(numOfMachines);
	int totalTime = 0;
	int currentMachineNum = 0;
	float result = 0;
	cout << "-----------------------------------------------------" << endl;

	for (int i = 0; i < numOfJobs; i++) {
		if (i < numOfMachines) {
			element shortMachine = delete_m_heap(machine_heap);
			shortMachine.schedules[0].processTime = jobs[i];
			shortMachine.totalProcessingTime = 0;
			shortMachine.processingTime = 0;
			shortMachine.schedules[0].reachTime = i;
			shortMachine.schedSize = 1; 
			shortMachine.key = jobs[i];
			for (int j = 0; j < numOfMachines; j++) {
				if (machine_heap->heap[j + 1].key != 0) {
					machine_heap->heap[j + 1].processingTime++;
					machine_heap->heap[j + 1].totalProcessingTime++;
					machine_heap->heap[j + 1].key--;
				}
			}
			insert_min_heap(machine_heap, shortMachine);
		}
		else {
			for (int j = 0; j < numOfMachines; j++) {
				if (machine_heap->heap[j + 1].processingTime == machine_heap->heap[j + 1].schedules[0].processTime) {
					if (machine_heap->heap[j + 1].recentEndProcess > 0) {
						result += machine_heap->heap[j + 1].totalProcessingTime - machine_heap->heap[j + 1].schedules[0].reachTime;
					}
					machine_heap->heap[j + 1].recentEndProcess = machine_heap->heap[j + 1].schedules[0].processTime;
					int temp_size = --machine_heap->heap[j + 1].schedSize;
					for (int k = 0; k < temp_size; k++) {
						machine_heap->heap[j + 1].schedules[k] = machine_heap->heap[j + 1].schedules[k + 1];
					}
					sortSchedules(machine_heap->heap[j + 1].schedules, temp_size);
					machine_heap->heap[j + 1].processingTime = 0;
					element machineSort = delete_m_heap(machine_heap);
					insert_min_heap(machine_heap, machineSort);
				}
			}

			element shortMachine = delete_m_heap(machine_heap);
			shortMachine.schedules[shortMachine.schedSize].processTime = jobs[i];
			shortMachine.schedules[shortMachine.schedSize].reachTime = i;
			shortMachine.key += jobs[i];
			shortMachine.compelteTime += jobs[i];
			shortMachine.schedSize++;
			insert_min_heap(machine_heap, shortMachine);

			for (int k = 0; k < numOfMachines; k++) {
				machine_heap->heap[k + 1].processingTime++;
				machine_heap->heap[k + 1].key--;
				machine_heap->heap[k + 1].totalProcessingTime++;
			}
		}
		totalTime++;
	}

	for (int i = 0; i < numOfMachines; i++) {
		if (machine_heap->heap[i + 1].schedSize != 0) {
			element temp_element = machine_heap->heap[i + 1];
			currentMachineNum = temp_element.machineNum;
			int size = temp_element.schedSize;
			if (machine_heap->heap[i + 1].processingTime == machine_heap->heap[i + 1].schedules[0].processTime) {
				if (machine_heap->heap[i + 1].recentEndProcess > 0) {
					result += machine_heap->heap[i + 1].totalProcessingTime - machine_heap->heap[i + 1].schedules[0].reachTime;
				}
				machine_heap->heap[i + 1].recentEndProcess = machine_heap->heap[i + 1].schedules[0].processTime;
				int temp_size = --machine_heap->heap[i + 1].schedSize;
				for (int k = 0; k < temp_size; k++) {
					machine_heap->heap[i + 1].schedules[k] = machine_heap->heap[i + 1].schedules[k + 1];
				}
				machine_heap->heap[i + 1].processingTime = 0;
				sortSchedules(temp_element.schedules, temp_size);// 스케쥴 정렬
				element machineSort = delete_m_heap(machine_heap);
				insert_min_heap(machine_heap, machineSort);
			}
			temp_element = machine_heap->heap[i + 1];
			if (temp_element.machineNum != currentMachineNum) {
				while (temp_element.machineNum != currentMachineNum) {
					for (int h = 1; h <= machine_heap->heap_size; h++) {
						temp_element = machine_heap->heap[h];
					}
				}
			}

			size = temp_element.schedSize;
			cout << "기계 (" << temp_element.machineNum << ")의 스케쥴: ";
			
			for (int j = 0; j < size; j++) {


				if (temp_element.recentEndProcess > 0) {
						result += machine_heap->heap[i + 1].totalProcessingTime-1 - machine_heap->heap[i + 1].processingTime + machine_heap->heap[i + 1].schedules[j].processTime * (size - (j)) - machine_heap->heap[i + 1].schedules[j].reachTime;
				} // 실제 소요 시간 = totalProcessingTime -1 

				else {
					if (j == 0) {
						result += (temp_element.schedules[j].processTime) * (size - j);
					}
					else {
						result += (temp_element.schedules[j].processTime) * (size - j) - temp_element.schedules[j].reachTime;
					}
				}
				cout << temp_element.schedules[j].processTime << " ";
			}
			cout << endl << "전체 흐른 시간: " << temp_element.totalProcessingTime << endl;
			cout << "현재 작업의 진행시간: " << temp_element.processingTime << " / " << temp_element.schedules[0].processTime << " REACHTIME: " << temp_element.schedules[0].reachTime << endl;
			if (temp_element.recentEndProcess > 0) {
				cout << "RECENTLY ENDED: " << temp_element.recentEndProcess << endl;
			}
			else {
				cout << "RECENTLY ENDED: NONE" << endl;
			}
		}
		cout << "-----------------------------------------------------" << endl;
	}
	cout << "TOTAL TURNAROUND TIME : " << result << endl << endl;
	return result / numOfJobs;
}

float completionTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {

		HeapType* machine_heap = creatingMachines(numOfMachines);
		int totalTime = 0;
		float result = 0;
		int whoIsMax = 0;
		cout << "-----------------------------------------------------" << endl;

		for (int i = 0; i < numOfJobs; i++) {
			if (i < numOfMachines) {
				element shortMachine = delete_m_heap(machine_heap);
				shortMachine.schedules[0].processTime = jobs[i];
				shortMachine.totalProcessingTime = 0;
				shortMachine.processingTime = 0;
				shortMachine.compelteTime = 0;
				shortMachine.schedules[0].reachTime = i;
				shortMachine.schedSize = 1;
				shortMachine.key = jobs[i];
				shortMachine.compelteTime += jobs[i];

				for (int j = 0; j < numOfMachines; j++) {
					if (machine_heap->heap[j + 1].key != 0) {
						machine_heap->heap[j + 1].processingTime++;
						machine_heap->heap[j + 1].totalProcessingTime++;
						machine_heap->heap[j + 1].key--;

					}
				}
				insert_min_heap(machine_heap, shortMachine);
			}
			else {
				for (int j = 0; j < numOfMachines; j++) {
					if (machine_heap->heap[j + 1].processingTime == machine_heap->heap[j + 1].schedules[0].processTime) {
						machine_heap->heap[j + 1].recentEndProcess = machine_heap->heap[j + 1].schedules[0].processTime;
						int temp_size = --machine_heap->heap[j + 1].schedSize;
						for (int k = 0; k < temp_size; k++) {
							machine_heap->heap[j + 1].schedules[k] = machine_heap->heap[j + 1].schedules[k + 1];
						}

						sortSchedules(machine_heap->heap[j + 1].schedules, temp_size);

						machine_heap->heap[j + 1].processingTime = 0;
						element machineSort = delete_m_heap(machine_heap);
						insert_min_heap(machine_heap, machineSort);
					}
				}

				element shortMachine = delete_m_heap(machine_heap);
				shortMachine.schedules[shortMachine.schedSize].processTime = jobs[i];
				shortMachine.schedules[shortMachine.schedSize].reachTime = i;
				shortMachine.key += jobs[i];
				shortMachine.compelteTime += jobs[i];
				shortMachine.schedSize++;
				insert_min_heap(machine_heap, shortMachine);

				for (int k = 0; k < numOfMachines; k++) {
					machine_heap->heap[k + 1].processingTime++;
					machine_heap->heap[k + 1].key--;
					machine_heap->heap[k + 1].totalProcessingTime++;
				}
			}
			totalTime++;
		}

		for (int i = 0; i < numOfMachines; i++) {

				element temp_element = machine_heap->heap[i + 1];
				int size = temp_element.schedSize;
	
			cout << "기계 (" << temp_element.machineNum << ")의 COMPLETE TIME : ";
			cout << temp_element.compelteTime;
			cout << endl;
			if (whoIsMax < temp_element.compelteTime) {
				whoIsMax = temp_element.compelteTime;
			}
		}
		cout << endl;
		return whoIsMax;
}

void testingSJF(int jobs[], int numOfJobs, int numOfMachines) {
	cout << "------------------ SJF(SHORTEST JOB FIRST) 기법 TEST ----------------------" << endl;
	cout << "AVERAGE  WAITING TIME : " << averageWatingTimeSJF(jobs,  numOfJobs,numOfMachines) << endl;
	cout << "AVERAGE TURN TIME :  " << averageTurnaroundTimeSJF(jobs, numOfJobs, numOfMachines) << endl;
	cout << "COMPLETE TIME : " << completionTimeSJF(jobs, numOfJobs, numOfMachines) << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}


int main(void) {
	element arr[] = { 5, 9, 2, 7, 1, 6 };
	element arr1[] = { 5, 9, 2, 7, 1, 6 , 4 ,5 , 10 , 51 , 100};
	element arr2[] = { 12,14,26,38,29,40,55,57,8,66 };
	int arr4[] = { 5, 9, 2, 7, 1, 6 };
	int arr5[] = { 8, 7, 6, 5, 3, 2, 1, 20, 21, 24 };
	int arr6[] = { 8, 15 ,7, 55, 6, 5, 10, 3, 2, 1, 20, 21, 24 };
	int arr7[] = { 4, 9, 11, 12, 13, 14, 8, 15,7, 55, 6, 5, 10, 3, 2, 1, 20, 21, 24, 16, 17, 18 };
	int testArr[] = { 8, 7, 6, 5, 3, 2, 1 };
	int testArr2[] = {3,3,3,1};
	char ex_str[] = "Outmanned and outgunned:";
	char ex_str1[] = "Red Zepplin , Guns and Roses , Queen :)";
	char ex_str2[] = "sykim gsyang jgann mhkim sgkim";
	char ch[] = { 's', 'i', 'n', 't', 'e' };
	int k = 3;    // k번째로 큰 요소

	/*  heap에 arr 원소들을 하나씩 삽입 한 후
		 큰 순서로 k 개를 꺼내되, k 번째 요소를 반환  */
	//int kthLargest = findKthLargest(arr, 6, 3);
	//int kthLargest1 = findKthLargest(arr1, sizeof(arr1) / sizeof(element), 3);
	//int kthLargest2 = findKthLargest(arr2, sizeof(arr2) / sizeof(element), 3);
	//printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest);
	//printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest1);
	//printf("배열에서 %d번째로 큰 요소: %d\n", k, kthLargest2);


	//printTopKFrequentElements(ex_str, 3);
	//printTopKFrequentElements(ex_str1, 3);
	//printTopKFrequentElements(ex_str2, 3);
	//testingLPT(arr5, 10, 3);
	///testingSJF(arr5, 10, 3);
	//testingLPT(arr6, 13, 4);
	//testingSJF(arr6, 13, 4);
	testingLPT(arr7, 22, 5);
	testingSJF(arr7, 22, 5);
	// cout << averageWatingTimeSJF(arr4, 6, 3) << endl;
	//testingLPT(arr4, 6, 3);
	//testingSJF(arr4, 6, 3);
	//testingLPT(testArr, 7, 3);
	
}