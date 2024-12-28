#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

// Node of the stack is implemeted using a struct
typedef struct
{
	int	items[MAX];
	int	top;
} Stack;

// Initializing a stack
void	stk_init(Stack *s)
{
	s->top = -1;
}

// Check is the stack is full
bool	stk_isFull(Stack *s)
{
	return (s->top == MAX - 1);
}

// Check if the stack is empty
bool	stk_isEmpty(Stack *s)
{
	return (s->top == -1);
}

// Push an element in to stack
bool	stk_push(Stack *s, int value)
{
	if(stk_isFull(s))
	{
		printf("Stack overflow!\n");
		return (false);
	}
	s->items[++(s->top)] = value;
	return (true);
}

// Pop an element form the stack
int	stk_pop(Stack *s)
{
	if(stk_isEmpty(s))
	{
		printf("Stack underflow!\n");
		return (s->top);
	}
	return (s->items[(s->top)--]);
}

// Peek in to Stack
int	stk_peek(Stack *s)
{
	if(stk_isEmpty(s))
	{
		printf("Stack is empty!\n");
		return (s->top);
	}
	return (s->items[s->top]);
}

void	stk_check(Stack *s)
{
	printf("Value from stk_isFull : %d\n", stk_isFull(s));
	printf("Value from stk_isEmpty : %d\n", stk_isEmpty(s));
	printf("Value from stk_peek : %d\n", stk_peek(s));
	printf("Value from stk_pop : %d\n", stk_pop(s));
}

int main(void)
{
	Stack stack;

	stk_init(&stack);
	printf("The stack initialized successfully....\n");
	stk_check(&stack);
	printf("......................................\n");
	printf("After add 10 to the stack....\n");
	stk_push(&stack,10);
	stk_check(&stack);
	printf("......................................\n");
	printf("After add 10,20,30,40,50 and trying to add 60 to the stack....\n");
	stk_push(&stack,10);
	stk_push(&stack,20);
	stk_push(&stack,30);
	stk_push(&stack,40);
	stk_push(&stack,50);
	stk_push(&stack,60);
	stk_check(&stack);
	printf("......................................\n");
	return (0);
}
