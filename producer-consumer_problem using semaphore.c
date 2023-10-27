#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty,s,x=0;
int wait(int s)
{
while(s<=0);
return --s;
}
int signal(int s)
{
return ++s;
}
void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\n Producer produces the item %d.\n",x);
mutex=signal(mutex);
}
void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf(" Consumer consumes item %d.\n",x);
x--;

mutex=signal(mutex);
}
void main()
{
int i,choice,n,item;
printf("Enter the number of slots: ");
scanf("%d",&n);
empty=n;
printf("Options are:\n1)Producer\n2)Consumer\n3)Exit\n");
for(i=1;i>0;i++)
{
printf("\nEnter the option: ");
scanf("%d",&choice);
switch(choice)
{
case 1: if(mutex==1&&empty!=0)
{
printf("\tProducer Process");
producer();
}
else
{
printf("Buffer is full.\n");
}
break;
case 2: if(mutex==1&&full!=0)
{
printf("\tConsumer Process\n");
consumer();
}
else
{
printf("Buffer is empty.\n");
}
break;
case 3: printf("\nExited!!\n");
exit(0);
break;
default: printf("Invalid choice!");
break;
}
}
}
