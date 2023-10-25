#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
int id=fork();
if(id>0)
{
printf("Parent Process waiting\n");
wait(NULL);
printf("\n\t Parent Process\n");
printf("ID of parent process is %d\n",getpid());
}
else if(id==0)
{
printf("\n\t Child Process\n");
printf("ID of parent process is %d\n",getppid());
printf("ID of child process is %d\n",getpid());
}
else
{
printf("Error!!!\n No Process\n");
}
printf(" \nExit is working\n");
exit(0);
printf(" \nExit is not working\n");
return 0;
}
