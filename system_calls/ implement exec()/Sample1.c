#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
char *args[]={"./Sample2",NULL};
execvp(args[0],args);
printf("Ending\n");
return 0;
}
