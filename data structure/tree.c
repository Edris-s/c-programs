#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *right, *left;

} node;

node *head = NULL;

void add()
{
    int a;
    node *p =head;
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    printf(" enter your data : ");
    scanf("%d", &a);
    temp->right = NULL;
    temp->left = NULL;
    temp->data=a;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        node*cur=head;
        while(cur)
        {   
            p=cur;
            if(a > cur->data)
            {
                cur=cur->right;
            }
            else
            {
                cur=cur->left ;
                
            }
            
        }
        if(a > p->data)
        {
            p->right=temp;
        }
        else
        {
            p->left=temp; 
            
        }
        
    }
}


void del_leaf_node()
{
    node*p=NULL;
    node*cur=head;
    while(cur)
    {
        p=cur;
        if(cur->right->data > cur->data)
        {
            cur=cur->right;
        }
        else
        {
            cur=cur->left;
        }
        if(cur->left->data < cur->data)
        {
            cur=cur->left;

        }
        else 
        {
            cur=cur->right;
        }
        
    }
    if(cur==p->right )
    {
        p->right=NULL;
    }
    else
    {
        p->left=NULL;
    }
    free(cur);
    
}

void del_leaf_single_child()
{
   node*p=NULL;
   node*cur=head;




   if(cur->right !=NULL)
   {
       if(cur==p->right)
       {
           p->right=cur->right;
       }
       cur->right=NULL;
       free(cur);
   }
   if(cur->left!=NULL)
   {
       if(cur==p->right)
       {
           p->right=cur->left;
       }
       cur->left=NULL;
       free(cur);

   } 
   if(cur->right !=NULL)
   {
       if(cur==p->left)
       {
           p->left=cur->right;
       }
       cur->right=NULL;
       free(cur);
   }
   if(cur->left != NULL)
   {
       if(cur==p->left )
       {
           p->left=cur->left;
       }
       cur->left=NULL;
       free(cur);
   }
}



void del_node_two_child()
{
    node*p=NULL  , *cur=head ;
     


    if(cur->right !=NULL && cur->left !=NULL ) // if the node to be deleted having two leaf nodes 
    {
        node*t1=NULL,*t2=NULL ;
        t1=cur->right;
        if(t1->right==NULL  && t1->left==NULL)
        {
            cur->data==t1->data;
            cur->right=NULL;
            free(t1);
        }
        if(t1->left==NULL  && t1->right!=NULL) // if the node to be deleted having one leaf node and one leaf with one child
        {
            cur->data=t1->data;
            cur->right=t1->right;
            t1->right=NULL;
            free(t1);
        }
    }

}

void display_inorder(node*t)
{
    
    if(t->left)
    display_inorder(t->left);
    printf("(%d)-->",t->data);
    if(t->right)
    display_inorder(t->right);
        

}



int main()
{
    int ch;
    
    while(1)
    {
        printf("\n1. add element to the tree   \n2. delete a leaf node   \n3. delete a leaf node having a child    \n4.delete a node having two childs   \n5 inorder display   \n enter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: add();
            break;

        case 2: del_leaf_node();
            break;
        case 3: del_leaf_single_child();

            break;
        case 4:del_node_two_child();
            break;

        case 5:display_inorder(head);

            break;

        
        default: printf("wrong choice !");
            break;
        }
    }
    return 0;
}