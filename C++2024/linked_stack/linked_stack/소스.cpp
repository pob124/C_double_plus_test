#include <iostream>
 

typedef int element;

typedef struct _StackNode {
		
	element data;

	struct _StackNode* link;

}StackNode;

typedef struct {

	StackNode* top;

}LinkedStackType;

void init(LinkedStackType* s)
{
	s->top = NULL;
}

int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}
// 포화 검출
int is_full(LinkedStackType* s) {
	return 0;
}
// 삽입
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
// 출력
void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	std::cout << std::endl;
}

element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		std::cerr << "스택이 비어있음 " << std::endl;
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

int eval(const char expr[]) {

	int rng = strlen(expr);
	int op1, op2, value;
	char ch;
	LinkedStackType* stack=(LinkedStackType*)malloc(sizeof(LinkedStackType));
	init(stack);

	for (int i = 0; i < rng; i++) {
		ch = expr[i];

		if (ch != '/' && ch != '*' && ch != '+' && ch != '-') {
			value = ch - '0';
			push(stack, value);
		}
		else {

			op1 = pop(stack); op2 = pop(stack);

			switch (ch) {
				
			case '/':
				push(stack, op2 / op1);
				break;
			case '*':
				push(stack, op2 * op1);
				break;
			case '+':
				push(stack, op2 + op1);
				break;
			case '-':
				push(stack, op2 - op1);
				break;
			}
		}
	}
	return pop(stack);
}


int main(void) {

		int result;
		std::cout << "후위표기식은 82 / 3 - 32 * +" << std::endl;
		result = eval("82/3-32*+");
		std::cout << "결과값은 : " << result << std::endl;
		return 0;

}