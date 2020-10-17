#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5
int stack[CAPACITY], top=-1;
int isfull()
{
	if(top==CAPACITY-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void push(int ele)
{
	if(isfull())
	{
		printf("Stack is already full... (OVERFLOW)");
	}
	else
	{
		top++;
		stack[top]=ele;
	}
}
int pop()
{
	if(isempty())
	{
		return 0;
	}
	else
	{
		return stack[top--];
	}
}
int peak()
{
	if(isempty())
	{
		printf("Stack is empty...");
	}
	else
	{
		printf("Element at top is: %d", stack[top]);
	}
}
void display()
{
	if(isempty())
	{
		printf("Stack is empty....");
	}
	else
	{
		int i;
		for(i=top;i>=0;i--)
		{
			printf("stack[%d] = %d\n", i, stack[i]);
		}
	}
}
int main()
{
	int ele, choice, del;
	while(1)
	{
		printf("\n____________________________________________________________________\n");
		printf("\tSTACK OPERATIONS USING LINKED LISTS\n\n");
		printf("1.Push\n2.Pop\n3.Peak\n4.Display\n5.QUIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to add into the stack: ");
				scanf("%d", &ele);
				push(ele);
				break;
			case 2:
				del = pop();
				if(del==0)
				{
					printf("Stack is empty...(UNDERFLOW)");
				}
				else
				{
					printf("Element deleted...\n");
				}
				break;
			case 3:
				peak();
				break;
			case 4:
				display();
				break;
			case 5:
				exit(1);
				break;
			default:
				printf("___INVALID SELECTION___");
		}
	}
	return 0;
}
