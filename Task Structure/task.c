#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched/signal.h>

int myPid=0;
module_param(myPid,int,0000);

int fileinfo304_init(void)
{

	printk(KERN_INFO "Loading Module\n");


	if(myPid==0)
	{
		printk(KERN_INFO "No pid entered\n");
		return 1;
	}
	else
	{
		struct task_struct *task;
		struct task_struct *parent_task; //to get sibling list

		int process_found=0; //works as a boolean

		//iteration over all processes
		for_each_process(task) 
		{
			/* Prints information about input pid */
			if(task->pid == myPid)
			{
				printk(KERN_INFO "Pid: %d \n", task->pid);
				printk(KERN_INFO "Parent pid: %d \n", task->parent->pid);
				printk(KERN_INFO "Executable name: %s \n", task->comm);

				parent_task=task->parent; //initialize task struct of parent

				int sibling_count=0; 
				for_each_process(parent_task)
				{
					/*First condition : Input pid shouldn't be in the sibling list
					  Second condition: Finds processes that has the same parent with the input pid | siblings
					*/
					if(parent_task->pid != myPid && parent_task->parent->pid==task->parent->pid)
					{
						printk(KERN_INFO "Sibling #%d Pid: %d Ppid:%d \nSibling #%d Executable name: %s \n\n",sibling_count+1, parent_task->pid,parent_task->parent->pid,sibling_count+1,parent_task->comm);
						
						sibling_count++;
					}
				} 
				if(sibling_count==0)
				{
					printk(KERN_INFO "There is no sibling proccess \n");

				}
		

				process_found=1;
			}
		}
		if(process_found==0)
		{
			printk(KERN_INFO "There is no such process with pid %d\n",myPid);
		}

	}

	return 0;
}

void fileinfo304_exit(void)
{
	printk(KERN_INFO "Removing module\n");
}


module_init(fileinfo304_init);
module_exit(fileinfo304_exit);


MODULE_LICENSE( "GPL");
MODULE_DESCRIPTION( "Exercise for COMP304");
MODULE_AUTHOR("Hasan Sefa Degirmenci");
