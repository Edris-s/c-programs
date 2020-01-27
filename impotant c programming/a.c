#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
 struct node *link;};

struct node * creat(int n);
void display(struct node * root);


int main()
{int n; 
struct node* root=NULL;
printf("\n enter your linklist size ");
scanf("%d",&n);

root=creat(n);
display(root);

return 0;
}




struct node* creat(int n)
{int i=0;
struct node* root=NULL;
struct node* temp=NULL;
struct node* p=NULL;

for (i=0;i<n;i++)
	{temp=(struct node *)malloc(sizeof(struct node));
	 printf("\n enter the element of node no. %d : ",i+1);
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{root=temp;}
else 
	{ p=root;
 	while (p->link!=NULL)
		p=p->link;
		p->link=temp;
	} 
	}
return root;
}


void display(struct node* root)
{struct node*p=NULL;
if (root==NULL)
	{printf("\n empty link list ");}
else
{p=root;
 while(p!=NULL)
	{printf("%d->",p->data);
		p=p->link; }
}
}











