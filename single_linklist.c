/*
    Written by:
    Sayed Edris Sadeed
    Free for personal use 

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

node *head = NULL;

void addend()
{

    node *temp = NULL;
    node *p = NULL;
    temp = (node *)malloc(sizeof(node));
    printf("enter your element :\n ");
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
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void display()
{
    node *p = head;
    if (head == NULL)
    {
        printf("empty linklist  ");
    }
    else
    {
        p = head;
        while (p != NULL)
        {
            printf("%d->", p->data);
            p = p->link;
        }
    }
}

void addfirst()
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    printf("enter your element :\n ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    temp->link = head;
    head = temp;
}

void addposition()
{
    node *p = head;
    node *temp = NULL;
    int position, i;
    printf("enter the position in which you want to add element \n");
    scanf("%d", &position);
    for (i = 1; i < position - 1; i++)
    {
        p = p->link;
    }

    temp = (node *)malloc(sizeof(node));
    printf("enter your element :\n ");
    scanf("%d", &temp->data);
    temp->link = p->link;
    p->link = temp;
}

void delend()
{
    node *p = head;
    while (p->link->link != NULL)
    {
        p=p->link;
    }
    p->link=NULL;
}

void delfirst()
{
    node*p=head;
    head=p->link;
    p->link=NULL;
}


void delposition()
{
    int position,i;
    node*p=head;
    node*temp=NULL;
    printf("enter the position in which you want to add element \n");
    scanf("%d", &position);
    for (i = 1; i < position - 1; i++)
    {
        p = p->link;
    }
    temp=p->link;
    p->link=temp->link;
    temp->link=NULL;
    free(temp);

}




int main()
{
    while (1)
    {
        int choice;
        printf("\n------------------welcome to link list -------------------\n");
        printf("\n1.creat linklist: \n2.display:  \n3.add element add the first: \n4.add element at the given position: \n5.delet en element from end: \n6.delet element from start: \n7.delet element from a given position: \n8.exit: \n enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addend();
            break;

        case 2:
            display();
            break;

        case 3:
            addfirst();
            break;

        case 4:
            addposition();
            break;

        case 5:delend();
            break;

        case 6:delfirst();
            break;

        case 7: delposition(); 
            break;

        case 8:exit(0);
            break;

            

        default:
            printf(" \n wrong choice ");
        }
    }
    return 0;
}
