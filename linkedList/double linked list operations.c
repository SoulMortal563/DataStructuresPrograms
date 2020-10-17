#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;
	}
}
void AddAtBegin()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d", &temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}
void AddAtSpecified()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	int loc, i=1;
	printf("\nEnter the location: ");
	scanf("%d", &loc);
	if(loc>length())
	{
		printf("\nINSERTION IS NOT POSSIBLE");
	}
	else
	{
		printf("\nEnter data to add: ");
		scanf("%d", &temp->data);
		temp->left=NULL;
		temp->right=NULL;
		struct node *p=root;
		while(i<loc)
		{
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
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
		temp=temp->right;
	}
	return count;
}
void display()
{
	struct node *temp;
	temp=root;
	if(temp==NULL)
	{
		printf("NO NODES TO DISPLAY...");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d<-->", temp->data);
			temp=temp->right;
		}
		printf("NULL");
	}
}
void Delete()
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
		root=temp->right;
		root->left=NULL;
		free(temp);
	}
	else if(loc==length())
	{
		temp=root;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		temp->left->right=NULL;
		temp->left=NULL;
		free(temp);
	}
	else
	{
		struct node *p=root;
		int i=1;
		while(i<loc-1)
		{
			p=p->right;
			i++;
		}
		temp=p->right;
		p->right=temp->right;
		temp->right->left=p;
		free(temp);
	}
}
int main()
{
	int choice;
	while(1)
	{
		printf("\n---------------------------------------------------------\n");
		printf("DOUBLE LINKED LIST OPERATIONS\n");
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
