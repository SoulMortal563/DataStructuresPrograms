#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *root=NULL;
void append()
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=root;
	}
}
void AddAtBegin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=root;
		root=temp;
	}
}
void AddAtSpecified()
{
	int location, i=1;
	printf("Enter Location: ");
	scanf("%d", &location);
	if(location>length())
	{
		printf("INVALID LOCATION...");
	}
	else
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		struct node *p;
		p=root;
		printf("\nEnter data: ");
		scanf("%d", &temp->data);
		temp->link=NULL;
		while(i<location)
		{
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
}
int length()
{
	int count = 0;
	struct node *temp;
	temp=root;
	while(temp->link!=root)
	{
		count++;
		temp=temp->link;
	}
	count++;
	return count;
}
void display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		printf("NO NODES TO DISPLAY...\n");
	}
	while(temp->link!=root)
	{
		printf("%d-->", temp->data);
		temp=temp->link;
	}
	printf("%d-->Again linked to first node", temp->data);
}
void Delete()
{
	int location, i=1;
	struct node *temp, *p;
	printf("Enter location: ");
	scanf("%d", &location);
	if(location>length())
	{
		printf("INVALID LOCATION..\n");
	}
	else if(location==1)
	{
		p=root;
		temp=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		root=temp->link;
		temp->link=NULL;
		p->link=root;
	}
	else
	{
		p=root;
		while(i<location-1)
		{
			p=p->link;
			i++;
		}
		temp=p->link;
		p->link=temp->link;
		temp->link=NULL;
		free(temp);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n---------------------------------------------------------\n");
		printf("CIRCULAR LINKED LIST OPERATIONS\n");
		printf("\n1.APPEND\n2.ADD AT BEGINNING\n3.ADD AT SPECIFIED LOCATION\n4.LENGTH OF THE LINKED LIST\n5.DISPLAY THE ELEMENTS\n6.DELETE THE ELEMENTS\n7.EXIT\n");
		printf("\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				AddAtBegin();
				break;
			case 3:
				AddAtSpecified();
				break;
			case 4:
				printf("\nLength of the linked list is %d..\n", length());
				break;
			case 5:
				display();
				break;
			case 6:
				Delete();
				break;
			case 7:
				exit(1);
			default:
				printf("\nINVALID CHOICE...\n");
		}
	}
	return 0;
}
