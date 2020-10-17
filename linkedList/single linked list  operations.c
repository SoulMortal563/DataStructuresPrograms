#include <Stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *root=NULL;

void display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		printf("\nNo Nodes to Display....");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->link;
		}
		printf("NULL");
	}
}

void append()
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter data to add: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
}

void add_at_beginning()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data to add: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}

void add_at_specific_position()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	int loc, i=1;
	printf("\nEnter the location: ");
	scanf("%d", &loc);
	printf("\nEnter data to add: ");
	scanf("%d", &temp->data);
	temp->link=NULL;
	int len=length();
	if(loc>len)
	{
		printf("\nINSERTION IS NOT POSSIBLE");
	}
	else
	{
		struct node *p;
		p=root;
		while(i<loc)
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
	int count=0;
	struct node *temp;
	temp=root;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}

void delete()
{
	struct node *temp;
	int loc;
	printf("\nEnter the location: ");
	scanf("%d", &loc);
	if(loc>length())
	{
		printf("\nDELETION NOT POSSIBLE");
	}
	else if(loc==1)
	{
		temp=root;
		root=temp->link;
		temp->link=NULL;	
		free(temp);
	}
	else
	{
		int i=1;
		struct node *p, *temp;
		p=root;
		while(i<loc-1)
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
		printf("\n_________________________________________________________________\n");
		printf("\n\n\n\t\t\t\t***LINKED LIST OPERATIONS***\n\n");
		printf("1.DISPLAY THE ELEMENTS\n");
		printf("2.APPEND (ADD AT LAST)\n");
		printf("3.ADD AT BEGINNING\n");
		printf("4.ADD AT SPECIFIC POSITION\n");
		printf("5.LENGTH OF THE LINKED LIST\n");
		printf("6.DELETE THE ELEMENTS\n");
		printf("7.EXIT\n");
		printf("Choose one option: ");
		scanf("%d", &choice);
		printf("\n_________________________________________________________________\n");
		switch(choice)
		{
			case 1:
				display();
				break;
			case 2:
				append();
				break;
			case 3:
				add_at_beginning();
				break;
			case 4:
				add_at_specific_position();
				break;
			case 5:
				printf("%d is the length", length());
				break;
			case 6:
				delete();
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("\nINVALID SELECTION");
		}
	}
	return 0;
}
