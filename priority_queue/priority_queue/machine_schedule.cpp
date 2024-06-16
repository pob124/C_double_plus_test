#include <iostream>
#define MAX_ELEMENT 200
using namespace std;


typedef struct {
	int id;
	int avail;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


HeapType* create() {

	return (HeapType*)malloc(sizeof(HeapType));

}// ���� �޸� �Ҵ� ���

void init(HeapType* h) {

	h->heap_size = 0;

}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.avail > h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}

void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;     // ���ο� ��带 ����
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].avail < h->heap[child + 1].avail))
			child++; 		// �ڽ� �� �� ū �ڽ�
		if (temp.avail >= h->heap[child].avail)
			break;
		h->heap[parent] = h->heap[child];
		parent = child; child *= 2; // �Ѵܰ� �Ʒ��� �̵�
	}
	h->heap[parent] = temp;
	return item;
}



element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].avail > h->heap[child + 1].avail))
			child++; 
		//else if ((child < h->heap_size) &&
		//	(h->heap[child].avail == h->heap[child + 1].avail) && (h->heap[child].avail == 0) && (h->heap[child].id > h->heap[child+1].id) && (h->heap[child].id ))
		//	child++;
		// �ڽ� �� �� ū �ڽ�
		if (temp.avail < h->heap[child].avail)
			break;
		h->heap[parent] = h->heap[child];
		parent = child; child *= 2; // �Ѵܰ� �Ʒ��� �̵�
	}
	h->heap[parent] = temp;
	return item;
}

void machine_sort(element a[], int n)
{
	int i;
	HeapType* h;
	element temp;
	h = create();
	init(h);

	for (int i = 1; i <= n; i++) {
		insert_min_heap(h, a[i]);
	}



	for (int i = n; i >= 1 ; i--) {
		for (int j = 0; j < i; j++) {
			if ((h->heap[j].id > h->heap[j + 1].id)&& (h->heap[j].avail == h->heap[j+1].avail) && (h->heap[j].avail == 0)) {
				temp = h->heap[j];
				h->heap[j] = h->heap[j + 1];
				h->heap[j + 1] = temp;
			}
		}
	}
	free(h);
}


void bubble_sort(int a[], int n)
{
	int temp;
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < i; j++) {
			temp = a[j];
			if (a[j] < a[j + 1]) {
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void bubble_sort_SJF(int a[], int n)
{
	int temp;
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < i; j++) {
			temp = a[j];
			if (a[j] > a[j + 1]) {
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
float averageWatingTime(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		//printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ�\n",
		//	i, m.avail, m.avail + jobs[i] - 1, m.id);
		if (m.avail != 0) {
			result += m.avail;
		}
		m.avail += jobs[i];

		insert_min_heap(h, m);
	}
	return result / numOfJobs;
}

float averageTurnAroundTime(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		//printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ�\n",
		//	i, m.avail, m.avail + jobs[i] - 1, m.id);
		
		m.avail += jobs[i];
		result += m.avail;
		insert_min_heap(h, m);
	}
	return result / numOfJobs;
}

float completeTime(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	for (int i = 1; i <= numOfMachines; i++) {
		if (h->heap[i].avail > result) {
			result = h->heap[i].avail;
		}
	}
	return result;
}
float averageWatingTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort_SJF(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		//printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ�\n",
		//	i, m.avail, m.avail + jobs[i] - 1, m.id);
		if (m.avail != 0) {
			result += m.avail;
		}
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return result / numOfJobs;
}
float averageTurnAroundTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort_SJF(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		//printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ�\n",
		//	i, m.avail, m.avail + jobs[i] - 1, m.id);

		m.avail += jobs[i];
		result += m.avail;
		insert_min_heap(h, m);
	}
	return result / numOfJobs;
}
float completeTimeSJF(int jobs[], int numOfJobs, int numOfMachines) {
	element m = { 0,0 };
	float result = 0.0;
	HeapType* h;
	h = create();
	init(h);
	bubble_sort_SJF(jobs, numOfJobs);
	for (int i = 0; i < numOfMachines; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < numOfJobs; i++) {
		m = delete_min_heap(h);
		machine_sort(h->heap, h->heap_size);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	for (int i = 1; i <= numOfMachines; i++) {
		if (h->heap[i].avail > result) {
			result = h->heap[i].avail;
		}
	}
	return result;
}





void guideLineLPT() {
	cout << "---------------------------------------(LPT:LONGEST JOB FIRST)-----------------------------------------" << endl;
	cout << "---------------------------------------(LPT TESTING GUIDELINE)-----------------------------------------" << endl;
	cout << "LPT�� ������, JOB���� ������������ ���� �˴ϴ�. (�������� ���� �� �ȵ�. **bubble ���� �̿���)" << endl;
	cout << "LPT�� ��� ��� �ð����� ������ ���� ����  jobs[i] �� � MACHINE�� avail�� �߰� �Ǳ� ���� �������ϴ�." << endl;
	cout << "LPT�� ��� ��ȯ �ð��� jobs[i] �� �߰� �� ���� avail ���� ���ϸ� �˴ϴ�." << endl;
	cout << "�Ϸ� �ð��� MACHINE �� ���� avail ���� ū ��踦 ���� �˴ϴ�." << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
}

void testingLPT(int number,int jobs[], int numOfJobs, int numOfMachines) {
	cout << "----------------------------" << endl;
	cout << "����" << number <<  " ��  ���� LPT ��� " << endl;
	cout << "��� ��� �ð� :"<< averageWatingTime(jobs, numOfJobs, numOfMachines) << endl;
	cout << "��� ��ȯ �ð� :" << averageTurnAroundTime(jobs, numOfJobs, numOfMachines) << endl;
	cout << "�Ϸ� �ð� :" << completeTime(jobs, numOfJobs, numOfMachines) << endl;
	cout << "----------------------------" << endl;
}

void testingSJF(int number, int jobs[], int numOfJobs, int numOfMachines) {
	cout << "----------------------------" << endl;
	cout << "����" << number << " ��  ���� SJF ��� " << endl;
	cout << "��� ��� �ð� :" << averageWatingTimeSJF(jobs, numOfJobs, numOfMachines) << endl;
	cout << "��� ��ȯ �ð� :" << averageTurnAroundTimeSJF(jobs, numOfJobs, numOfMachines) << endl;
	cout << "�Ϸ� �ð� :" << completeTimeSJF(jobs, numOfJobs, numOfMachines) << endl;
	cout << "----------------------------" << endl;
}


int main(void) {
	//int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 };
	int jobs[] = { 8, 7, 6, 5, 3, 2, 1, 20, 21, 24 };// �ҿ�ð��� ���� ���ĵǾ� �ִ� �۾���
	int jobs2[] = { 8, 15,7, 55, 6, 5, 10, 3, 2, 1, 20, 21, 24 };
	int jobs3[] = { 4, 9, 11, 12, 13, 14, 8, 15,7, 55, 6, 5, 10, 3, 2, 1, 20, 21, 24, 16, 17, 18 };
	//element m = { 0, 0 };
	//HeapType* h;
	//h = create();
	//init(h);
	//bubble_sort(jobs, 10);
	//for (int i = 0; i < MACHINES; i++) {
	//	m.id = i + 1;
	//	m.avail = 0;
	//	insert_min_heap(h, m);
	//}
	//for (int i = 0; i < JOBS; i++) {
	//	m = delete_min_heap(h);
	//	machine_sort(h->heap, h->heap_size);
	//	printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ�\n",
	//		i, m.avail, m.avail + jobs[i] - 1, m.id);
	//	m.avail += jobs[i];
	//	insert_min_heap(h, m);
	//}
	
	testingLPT(1,jobs, sizeof(jobs) / sizeof(int), 3);
	testingLPT(2,jobs2, sizeof(jobs2) / sizeof(int), 4);
	testingLPT(3,jobs3, sizeof(jobs3) / sizeof(int), 5);
	testingSJF(1, jobs, sizeof(jobs) / sizeof(int), 3);
	testingSJF(2, jobs2, sizeof(jobs2) / sizeof(int), 4);
	testingSJF(3, jobs3, sizeof(jobs3) / sizeof(int), 5);

	return 0;
}