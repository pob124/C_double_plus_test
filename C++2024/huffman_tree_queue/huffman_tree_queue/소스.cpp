#include <iostream>
#include <stdlib.h>
#define MAXQUEUESIZE 50
#define MAXSTACKSIZE 50
using namespace std;

typedef struct _Node {
    char character;
    int frequency;
    struct _Node* left;
    struct _Node* right;
} Node;

typedef struct {
    Node stacks[MAXSTACKSIZE];
    int top;
} PriorityQueue_S;

typedef struct {
    Node* nodes[MAXQUEUESIZE];
    int size;
} PriorityQueue;

int empty(PriorityQueue_S* stackQueue) {
    return (stackQueue->top == -1);
}

int is_full(PriorityQueue_S* stackQueue) {
    return (stackQueue->top == MAXSTACKSIZE - 1);
}

void stackSort(PriorityQueue_S* stackQueue) {
    if (empty(stackQueue) || stackQueue->top <= 0) {
        return;
    }
    for (int i = stackQueue->top; i > 0; i--) {
        if (stackQueue->stacks[i].frequency > stackQueue->stacks[i - 1].frequency) {
            Node temp = stackQueue->stacks[i];
            stackQueue->stacks[i] = stackQueue->stacks[i - 1];
            stackQueue->stacks[i - 1] = temp;
        }
    }
}

void push(PriorityQueue_S* stackQueue, Node* item) {
    if (is_full(stackQueue)) {
        return;
    }
    else {
        stackQueue->top++;
        stackQueue->stacks[stackQueue->top] = *item; // ����� �ּҰ� �ƴ� ��� ��ü�� ���ÿ� �߰�
        if ((stackQueue->top >= 1) && stackQueue->stacks[stackQueue->top - 1].frequency < item->frequency) {
            stackSort(stackQueue);
        }
    }
}


Node* createNode(char character, int frequency, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

Node* pop(PriorityQueue_S* stackQueue) {


    if (empty(stackQueue)) {
        return NULL; // �� ��� ��ȯ
    }
    
    Node poppedNode = stackQueue->stacks[stackQueue->top];
    Node* popped = createNode(poppedNode.character, poppedNode.frequency, poppedNode.left, poppedNode.right);
    stackQueue->top--;
    return popped;
}



// �� �켱���� ť�� �����Ͽ� ��ȯ
PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->size = 0;
    return queue;
}
PriorityQueue_S* createPriorityQueue_S() {
    PriorityQueue_S* stack = (PriorityQueue_S*)malloc(sizeof(PriorityQueue_S));
    stack->top = -1;
    return stack;
}

void enqueue(PriorityQueue* queue, Node* node) {
    if (queue->size >= MAXQUEUESIZE) {
        printf("Queue is full.\n");
        return;
    }
    int i = queue->size;
    while (i > 0 && node->frequency > queue->nodes[i - 1]->frequency) {
        queue->nodes[i] = queue->nodes[i - 1];
        i--;
    }
    queue->nodes[i] = node;
    queue->size++;
}

// �� �������� �迭���� ������ ��带 ������ ��ȯ
Node* dequeue(PriorityQueue* queue) {
    if (queue->size <= 0) {
        printf("Queue is empty.\n");
        return NULL;
    }
    queue->size--;
    return queue->nodes[queue->size];
}

Node* buildHuffmanTree(PriorityQueue* queue) {
    while (queue->size >= 2) {
        Node* node1 = dequeue(queue);
        Node* node2 = dequeue(queue);

        // ���� �� ����� �󵵸� ���� �� ��带 �켱���� ť�� ����
        Node* mergedNode = createNode('$', node1->frequency + node2->frequency, node1, node2);
        enqueue(queue, mergedNode);
        printf("%d+%d->%d \n", node1->frequency, node2->frequency, mergedNode->frequency);
    }
    return dequeue(queue); // �켱���� ť�� ������ ��
}

Node* buildHuffmanTree_S(PriorityQueue_S* stack) {
    while (stack->top >= 1) {
        Node* node1 = pop(stack);
        Node* node2 = pop(stack);

        // ���� �� ����� �󵵸� ���� �� ��带 �켱���� ť�� ����
        Node* mergedNode = createNode('$', node1->frequency + node2->frequency, node1, node2);
        push(stack, mergedNode);
        printf("%d+%d->%d \n", node1->frequency, node2->frequency, mergedNode->frequency);
    }
    return pop(stack); // �켱���� ť�� ������ ��
}
// ������ Ʈ���� ������� ������ �ڵ带 ����ϴ� ��ȯ�Լ�
// ���� root�� �������� ��ƿ� �ڵ带 ����. �ڵ���̵� ���� ����.

// ������ Ʈ���� ������� ������ �ڵ带 ����ϴ� ��ȯ�Լ�
// ���� root�� �������� ��ƿ� �ڵ带 ����. �ڵ���̵� ���� ����.
void generateHuffmanCodes(Node* root, int code, int length) {

    // �����̸� �������� ��ƿ� �ڵ带 ���
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);
        for (int i = length - 1; i >= 0; i--) {
            printf("%d", (code >> i) & 1);
        }
        printf("\n");
        return;
    }
    // ������ �ƴϸ� �� �ڽ��� code�� 0��, ���� �ڽ��� code�� 1�� ������
    generateHuffmanCodes(root->left, code << 1, length + 1);
    generateHuffmanCodes(root->right, (code << 1) | 1, length + 1);
}

void testingHFM(char ch[], int freq[], int size) {
    cout << "------------------ HFM(HuFfMan) �ڵ� TEST ----------------------" << endl;
    PriorityQueue* queue = createPriorityQueue();
    for (int i = 0; i < size; i++) {
        Node* node = createNode(ch[i], freq[i], NULL, NULL);
        enqueue(queue, node); // �� ������� ����
    }
    Node* root = buildHuffmanTree(queue);
    // ������ �ڵ� ���
    generateHuffmanCodes(root, 0, 0);

    cout << "-----------------------------------------------------" << endl;
}
void testingHFM_S(char ch[], int freq[], int size) {
    cout << "------------------ HFM(HuFfMan) �ڵ� TEST ----------------------" << endl;
    PriorityQueue_S* stack = createPriorityQueue_S();
    for (int i = 0; i < size; i++) {
        Node* node = createNode(ch[i], freq[i], NULL, NULL);
        push(stack, node); // �� ������� ����
    }
    for (int i = stack->top; i >= 0; i--) {
        cout << stack->stacks[i].character;
        cout << stack->stacks[i].frequency;
        cout << endl;
    }
    Node* root = buildHuffmanTree_S(stack);
    cout << root->character;
    cout << root->frequency;
    // ������ �ڵ� ���
    generateHuffmanCodes(root, 0, 0);

    cout << "-----------------------------------------------------" << endl;
}


// ������ Ʈ���� �����ϰ� ������ �ڵ带 ���
int main(void) {
    char ch[] = { 's', 'i', 'n', 't', 'e' };
    int freq[] = { 4, 6, 8, 12, 15 };
    char ch1[] = { 'a', 'b', 'c', 'd', 'e' , 'f', 'g', 'h' };
    int freq1[] = { 24, 4, 5, 15, 7, 30, 2, 6 };
    char ch2[] = { 'a', 'b', 'c', 'd', 'e' , 'f', 'g', 'h', 'i', 'j' };
    int freq2[] = { 25, 3, 5, 10, 8, 30, 2, 7, 20, 13 };

    //testingHFM(ch, freq, sizeof(ch) / sizeof(char));
    //testingHFM(ch1, freq1, sizeof(ch1) / sizeof(char));
    //testingHFM(ch2, freq2, sizeof(ch2) / sizeof(char));
    testingHFM_S(ch, freq, sizeof(ch) / sizeof(char));
    testingHFM_S(ch1, freq1, sizeof(ch1) / sizeof(char));
    testingHFM_S(ch2, freq2, sizeof(ch2) / sizeof(char));

}