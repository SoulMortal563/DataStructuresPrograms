#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *top=NULL;
void push()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("Stack is empty....");
	}
	else
	{
		printf("Element deleting is : %d", temp->data);
		top=top->link;
		temp->link=NULL;
		free(temp);
	}
}
int length()
{
	struct node *temp;
	temp=top;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}
void peak()
{
	struct node *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("Stack is empty....");
	}
	else
	{
		printf("Element at top is: %d", temp->data);
	}
}
void display()
{
	struct node *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("Stack is empty....");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->link;
		}
	}
}
int main()
{
	int choice, len;
	while(1)
	{
		printf("\n____________________________________________________________________\n");
		printf("\tSTACK OPERATIONS USING LINKED LISTS\n\n");
		printf("1.Push\n2.Pop\n3.Peak\n4.Display\n5.Length\n6.QUIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peak();
				break;
			case 4:
				display();
				break;
			case 5:
				len=length();
				printf("Length of the stack is %d", len);
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("___INVALID SELECTION___");
		}
	}
	return 0;
}
