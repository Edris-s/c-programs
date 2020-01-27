#include<stdio.h>
int main()
{int n,a[100],m,b[100],i,j,temp,ch,choice=1;
while(choice )
{
printf("1. sorted array  \n");
printf("2. unsorted array  \n");
printf("3. exit  \n");
scanf("%d",&ch);
switch(ch)
{
case 1:

printf("enter the size of first array : \n");
scanf("%d",&n);
printf("enter the elements of first array : \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("enter the size of second array : \n");
scanf("%d",&m);
printf("enter the elements of second array : \n");
for(i=0;i<m;i++)
scanf("%d",&b[i]);

for(i=0;i<m;i++)
{a[n+i]=b[i];}

printf("the elements of merged array is  : \n");
for(i=0;i<n+m;i++)
printf("%d \n ",a[i]);


for(i=0;i<n+m-1;i++)
{for(j=0;j<n+m-1;j++)
 	{if(a[j]<a[j+1])
		{temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp; }}
}
printf("the descending merged array : \n ");

for(i=0;i<n+m;i++)
printf("%d \n ",a[i]);

break;

case 2:

printf("enter the size of first array : \n");
scanf("%d",&n);
printf("enter the elements of first array : \n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("enter the size of second array : \n");
scanf("%d",&m);
printf("enter the elements of second array : \n");
for(i=0;i<m;i++)
scanf("%d",&b[i]);

for(i=0;i<m;i++)
{a[n+i]=b[i];}

printf("the elements of merged array is  : \n");
for(i=0;i<n+m;i++)
printf("%d \n ",a[i]);


for(i=0;i<n+m-1;i++)
{for(j=0;j<n+m-1;j++)
 	{if(a[j]>a[j+1])
		{temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp; }}
}
printf("the ascending merged array : \n ");

for(i=0;i<n+m;i++)
printf("%d \n ",a[i]);

break;



case 3: 
       choice=0;
break;
default: printf("wrong choise ");

}
}
return 0;
}
