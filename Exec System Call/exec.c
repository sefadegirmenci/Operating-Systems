#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
	int pid=fork();

	if(pid <0)
	{
		printf("Unable to fork");
		exit(1);
	}
	else if(pid==0)
	{
		/* NOTES TO MYSELF:
		   execl: Comma seperated arguments
		   execv: Vector(i.e. an array of strings) -> execp(args[0],args)
		   execp: Path include
		   exec'in ilk satırı her zaman path'in, çalıştırmak istediğin olur.
		   ikincisi ise biz komutu çalıştırınca argv ne olması gerek ise onu yazarız
		   aşağıdaki kodda ilk pathi ekledim ikincisi ./ps çünkü o da argüman olarak alınıyor, ikincisi ise asıl parametremiz
		*/
		char *args[]={"/usr/bin/ps","f",NULL};  //arguments
		execlp(args[0],"./ps","f",NULL);        //execute
	}
	else
	{
		wait(NULL);	//parent waits
		printf("Child finished execution.");
	}


}
