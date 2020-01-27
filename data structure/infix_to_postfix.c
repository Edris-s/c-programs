#include<stdio.h>
#include<stdlib.h>
#define c 50
char stack[c];
int top=-1;


void push(char item)
{
    if(top>=c-1)
    {
        printf("stack is overflow , push is not possible \n");

    }
    else 
    {
        top++;
        stack[top]=item;

    }
}

char pop()
{
    
  char item;
  item=stack[top];
  top--;
  return(item);
}

int is_operator(char symbol)
{
    if (symbol=='^'|| symbol=='/' || symbol=='*' || symbol=='+' || symbol=='-')
    return 1;
    else 
    return 0;

}

int precedence(char symbol)
{
    if(symbol=='^')
    return 3;
    else if(symbol=='/' || symbol=='*')
    return 2;
   else if (symbol=='+' || symbol=='-')
    return 1;
    else 
    return 0;
}






int main()
{
    char infix[c],postfix[c],item,temp;
    int i=0,j=0;
    printf(" enter your infix expresion : ");
    scanf("%s",infix);
    while(infix[i]!='\0')
    {
        item=infix[i];
        if(item=='(')
        {
            push(item);
        }
        else if(item>='A' && item<='Z' || item>='a' && item<='z')
        {
            postfix[j]=item;
            j++;
        }
        else if(is_operator(item)==1)
        {
            temp=pop();
            while(is_operator(temp)==1 && precedence(temp)>=precedence(item))
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
            push(temp);
            push(item);

        }
        else if(item==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }
        else 
        {
            printf(" invalid expression ");
           // getch();
            exit(0);
        }
        i++;
    }
    while(top>-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("the postfix expresion is : ");
    puts(postfix);
    //getch();
    return 0;

}
