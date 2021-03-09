#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
int main()
{
	time_t current_time;
	int fd[4][2];
	for(int i=0;i<4;i++)
	{
		if(pipe(fd[i])==-1)
		{
			printf("Unable to pipe");
		}
	}

	int id= fork();

	if(id < 0)
	{
		printf("Unable to fork");
	}
	//parent process
	else if(id >0)
	{
		close(fd[0][0]);
		close(fd[3][1]);
		close(fd[2][0]);
		close(fd[2][1]);
		close(fd[1][0]);
		close(fd[1][1]);

		//Write | From A to B
		time(&current_time);
		char *time_string=ctime(&current_time);
		if(write(fd[0][1],time_string,strlen(time_string)+1)==-1)
		{
			printf("Unable to write\n");
		}
		close(fd[0][1]);

		//Read | From B to A 
		char time_from_child[100];
		if(read(fd[3][0],time_from_child,sizeof(char[100]))==-1)
		{
			printf("Unable to read\n");
		}
		close(fd[3][0]);
		printf("From B to A: %s\n",time_from_child);

		//Kill | Process B
		if(kill(id,SIGTERM)==-1)
		{
			printf("Could not kill process B. \n" ); 
		} 
		
		//Kill | Process B
		if(kill(getpid(),SIGTERM)==-1)
		{
			printf("Could not kill process A. \n" ); 
		}
	}
	//Process B
	else
	{
		close(fd[0][1]);
		close(fd[3][0]);

		//Read | From A to B
		char time_from_parent[100];
		if(read(fd[0][0],time_from_parent,sizeof(char[100]))==-1)
		{
			printf("Unable to read\n");
		}
		close(fd[0][0]);
		printf("From A to B: %s\n",time_from_parent);

		//Sleep | 3 Seconds
		sleep(3);

		//Fork | Process C
		int id_2=fork();
		if(id_2<0) printf("Unable to fork");
		//Process B sends time
		else if(id_2>0)
		{
			close(fd[2][1]);
			close(fd[1][0]);

			//Send | From B to C
			time(&current_time);
			char *time_string_2=ctime(&current_time);
			if(write(fd[1][1],time_string_2,strlen(time_string_2)+1)==-1)printf("unable to write");	
			close(fd[1][1]);

			//Read | From C to B
			char time_from_child[100];
			if(read(fd[2][0],time_from_child,sizeof(char[100]))==-1) printf("Unable to read");
			close(fd[2][0]);
			printf("From C to B: %s\n",time_from_child);

			//Sleep | 3 seconds
			sleep(3);

			//Send | From B to A
			time(&current_time);
			time_string_2=ctime(&current_time);
			if(write(fd[3][1],time_string_2,strlen(time_string_2)+1)==-1)printf("unable to write");	
			close(fd[3][1]);

			//Kill | Process C
			if(kill(id_2,SIGTERM)==-1) printf("Could not kill process C. \n" );
		}
		//Process C
		else
		{
			close(fd[0][0]);
			close(fd[0][1]);
			close(fd[1][1]);
			close(fd[2][0]);
			close(fd[3][0]);
			close(fd[3][1]);

			//Read | From B to C
			if(read(fd[1][0],time_from_parent,sizeof(char[100]))==-1)
			{
				printf("Unable to read");
			}
			close(fd[1][0]);
			printf("From B to C: %s\n",time_from_parent);

			//Sleep | 3 seconds
			sleep(3);

			//Send | From C to B
			time(&current_time);
			char*time_string_3=ctime(&current_time);
			if(write(fd[2][1],time_string_3,strlen(time_string_3)+1)==-1)
			{
				printf("Unable to write");
			} 
			close(fd[2][1]);

		}
	}
	return 0;
}