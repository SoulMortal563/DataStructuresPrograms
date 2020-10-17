#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *front=NULL, *rear=NULL;
void enqueue()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(front==NULL && rear==NULL)
	{
		front = rear = temp;
	}
	else
	{
		rear->link=temp;
		rear = temp;
	}
}
void display()
{
	struct node *temp;
	if(front==NULL && rear==NULL)
	{
		printf("QUEUE IS EMPTY (UNDERFLOW)");
	}
	else
	{
		temp = front;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
	}
}
void dequeue()
{
	if(front==NULL && rear==NULL)
	{
		printf("QUEUE IS EMPTY (UNDERFLOW)");
	}
	else
	{
		struct node *temp = front;
		front = front->link;
		free(temp);
	}
}
void peak()
{
	if(front==NULL && rear==NULL)
	{
		printf("QUEUE IS EMPTY (UNDERFLOW)");
	}
	else
	{
		printf("ELEMENT at top is %d", front->data);
	}
}
int main()
{
	int choice, ele;
	while(1)
	{
	printf("\n___________________________________________________________________\n");
	printf("\n<<<<QUEUE IMPLIMENTATION USING LINKED LIST>>>>\n");
	printf("Enter\n1 for ENQUEUE\n2 for DEQUEUE\n3 for DISPLAY\n4 for PEAK ELEMENT\n5 for EXIT\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			peak();
			break;
		case 5:
			exit(1);
			break;
		default:
			printf("INVALID CHOICE");
	}
	}
	return 0;
}
