#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
	int pid=fork();

	/*Problem in forking*/
	if(pid <0)
	{
		printf("Unable to fork");
		exit(1);
	}
	/* Parent Process sleeps */ 
	else if(pid!=0)
	{
		sleep(5);
	}
	/* Child exits */
	else
	{
		exit(0);
	}
	


}
