#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list *previous;
	struct s_list *next;
	int data;
} t_list;

typedef struct
{
	t_list *top;
} Stack;


// Initializing a new stack
void stk_init(Stack *stack)
{
	stack->top = NULL;
}

int stk_isEmpty(Stack *stack)
{
	return (stack->top == NULL);
}

void stk_push(Stack *stack, int value)
{
	t_list *node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return ;
	node->data = value;
	node->next = stack->top;
	node->previous = NULL;
	if(stack->top != NULL)
	{
		stack->top->previous = node;
	}
	stack->top = node;
}

int stk_pop(Stack *stack)
{
	if(stk_isEmpty(stack))
	{
		return (-1);
	}
	t_list *node = stack->top;
	int value = stack->top->data;
	stack->top = stack->top->next;
	if(stack->top != NULL)
	{
		stack->top->previous = NULL;
	}
	free(node);
	return (value);
}

int stk_peek(Stack *stack)
{
	if(stk_isEmpty(stack))
		return (-1);
	return (stack->top->data);
}

int main()
{
	Stack stack;
	stk_init(&stack);
	stk_push(&stack, 10);
	printf("top element after push : %d\n", stk_peek(&stack));
	stk_push(&stack, 20);
	stk_push(&stack, 30);
	printf("top element after push : %d\n", stk_peek(&stack));
	stk_pop(&stack);
	printf("top element after pop : %d\n", stk_peek(&stack));
	return (0);
}
