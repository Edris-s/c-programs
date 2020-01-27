#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} node;

node *head = NULL;

void creat()
{
    node *temp = NULL;
    node *p = NULL;
    temp = (node *)malloc(sizeof(node));
    printf("enter your element :");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left= p;
        temp->right = NULL;
    }
}

void display()
{
    node *p = NULL;
    if (head == NULL)
    {
        printf(" empty list \n ");
    }
    else
    {
        p = head;
        while (p != NULL)
        {
            printf("%d<=>", p->data);
                p = p->right;
        }
    }
}



void adds()
{
    node*p=head;
    node*temp=NULL;
    emp = (node *)malloc(sizeof(node));
    printf("enter your element :");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    temp->right=p;
    head=temp;
    p->left=temp;
}









int length() //its not working properly
{int i=0;
    node*p=head;
    while(p!=NULL)
    {
        i++;
        p=p->right;
    }
    return i;
}

void addp()
{
    int position,i;
    node*p=head;
    node*temp=NULL;
    printf("enter your position : ");
    scanf("%d",&position);
    for(i=1;i<position-1;i++)
    {
        p=p->right;
    }
    temp=(node*)malloc(sizeof(node));
    printf("enter your element : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    temp->left=NULL;
    temp->right=p->right;
    p->right->left=temp;
    temp->left=p;
    p->right=temp;

}

void delstart()
{
    node*p=head;
    head=p->right;
    p->right=NULL;
    head->left=NULL;
    free(p);
}

void delend()  //its not working properly
{
    node*p=head;
    while(p->right->left!=NULL)
    {
        p=p->right;
    }
	p->right->left=NULL;
	p->right=NULL;
     
    // p=NULL;
    free(p);
}


void delp()
{
    node*p=head;
    node*q=NULL;
    node*g=NULL;
     printf("enter your position : ");
    scanf("%d",&position);
    for(i=1;i<position-1;i++)
    {
        p=p->right;
    }
    g=p->right;
    q=p->right->right;
    q->left=p;
    p->right=q;
    g->right=NULL;
    g->lift=NULL;
    free(g);
    free(q);


}


int main()
{

    int ch;
    while(1)
    {
        printf("\n1. add element: \n2. dispaly: \n3.see the lenght: \n4.add element in a given position: \n5.delet from start: \n6.delet from end:  \n7.exit:   \n8. add to the start  \n9. delete from a given position:  \n enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: creat();
            break;

            case 2: display();
            break;

            case 3: length();
            break;

            case 4: addp();
            break; 

            case 5: delstart();
            break;

            case 6: delend();
            break;

            case 7: exit(0);
            break;

            case 8: adds();
            break;

            case 9: delp();
            break;

            default : printf(" \n wrong choice \n");
            break;
        }
        
    }
    return 0;
}

