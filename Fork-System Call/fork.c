#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
	int level=0;
	int pid=0;
	for(int i=0;i<4;i++)
	{
		pid=fork();
		//increase the level for every child
		if(pid==0)
		{
			level++;
		}
	}
	
	printf("Process ID: %d, Parent ID: %d, level: %d\n",getpid(),getppid(),level);
	//parents wait for their children to finish execution
	while(wait(NULL)!=-1){
		continue;	
	}
	return 0;

}
