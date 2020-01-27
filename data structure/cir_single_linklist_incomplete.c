#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;

node *head = NULL;

void add()
{
    node *temp = NULL;
    node *save=NULL;
    temp = (node *)malloc(sizeof(node));
    printf("enter your data :  \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    node *p = head;
    if (head == NULL)
    {
        head = temp;
        temp->link=head;
    }
    else
    {
        while(p->link!=head)
            {
                p=p->link;
            }
                p->link=temp;
                temp->link=head;
            

    }
   
}

void display()
{
    node *p = head;
    if (head == NULL)
    {
        printf("* empty link list *  \n");
    }
    else
    {
        do
        {
            printf("%d->", p->data);
            p = p->link;
        }while (p != head);
        printf("----<");
    }
}

void addp()
{   int n,i;
    node* temp=NULL;
    node*p=head;
    printf("** enter your position**\n");
    scanf("%d",&n);
    for(i=1;i<n-1;i++)
    {
        p=p->link;
    }
     temp = (node *)malloc(sizeof(node));
    printf("enter your data :  \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    temp->link=p->link;
    p->link=temp;
    

}


void adds()
{ 

    node*p=head;
    node*temp=NULL;
    temp = (node *)malloc(sizeof(node));
    printf("enter your data :  \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
     if (head == NULL)
    {
        head = temp;
        temp->link=head;
    }
    else
    {
        while(p->link!=head)
            {
                p=p->link;
            }
                p->link=temp;
                temp->link=head;
                head=temp;

    }


}

void delend()
{
    node*p=head;
    node*q=NULL;
    while(p->link->link !=head)
    {
       p=p->link;
    }
     q=p->link;
     p->link=q->link;
     q->link=NULL;
}


void delp()
{
    int n,i;
    node*p=head;
    printf(" enter your position : ");
    scanf("%d",&n);
    for(i=1;i<n-1;i++)
    {
        p=p->link;
    }
    p=p->link;
    p->link=NULL;
}

void dels()
{
    node*p=head;
    node*q=head;
    while(p->link!=head)
    {
        p=p->link;
    }
    q=q->link;
    q=head;
    p->link->link=q;

}


int main()
{
    int ch;
    while (1)
    {
        printf("    \n1. to add element     \n2. display     \n3. add at the position      \n4. add at the start:     \n5.del end    \n6.del position     \n7.delet start    \n8.exit      \n **enter your choice**\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            display();
            break;

         case 3:
            addp();
            break;

            case 4: adds();
            break;

            case 5: delend();
            break;

            case 6: delp();
            break;

            case 7: dels();
            break;

            case 8: exit(0);
            break;

            default : printf(" wrong choice!");
        }
    }

    return 0;
}