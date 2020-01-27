#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *link;
} node;

node *head = NULL;

void creat();
void display();

void insertStart()
{
	node *temp = (node *)malloc(sizeof(node));
	printf("enter the element");
	scanf("%d", &temp->data);
	temp->link = NULL;
	temp->link = head;
	head = temp;
}

void insertInbetween()
{
	int position;
	printf("enter the position");
	scanf("%d", &position);
	int i;
	node *p = head;

	for (i = 1; i < position - 1; i++)
	{
		p = p->link;
	}
	node *temp = (node *)malloc(sizeof(node));
	printf("enter the element");
	scanf("%d", &temp->data);
	temp->link = p->link;
	p->link = temp;
}

int main()
{
	while (1)
	{
		printf("\n\nPress\n1.Insert at end\n2.Insert at start\n3.Display\n4.Insert at position\n5.Exit ");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			creat();
			break;

		case 2:
			insertStart();
			break;

		case 3:
			display();
			break;

		case 4:
			insertInbetween();
			break;

		case 5:
			exit(0);
			break;

		default:
			printf("Wrong input enter again");
			break;
		}
	}
	return 0;
}

void creat()
{
	
	node *p = NULL;

	node *temp = (node *)malloc(sizeof(node));
	printf("enter the element");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		p = head;
		while (p->link != NULL)
			p = p->link;
		p->link = temp;
	}
}

void display()
{
	printf("\n\n");
	node *p = NULL;
	if (head == NULL)
		printf("\n empty list ");
	else
	{
		p = head;
		while (p != NULL)
		{
			printf("%d->", p->data);
			p = p->link;
		}
	}
	printf("\n\n");
}
