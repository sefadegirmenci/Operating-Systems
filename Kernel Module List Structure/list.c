#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
#include<linux/slab.h>

//Struct definition
struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;	
};

//initialize list head
struct list_head birthday_list;

static LIST_HEAD(birthday list);

struct birthday * bdayCreate(int day,int month,int year)
{
    struct birthday *bday=kmalloc(sizeof(struct birthday), GFP_KERNEL);
	person->day = day;
	person->month = month;
	person->year = year;
	return bday;
}

int init(void)
{
	printk(KERN_INFO "Loading Module\n");
	

	//Create 5 birthdays 
	//Add them to tail of the list
    struct birthday *person = bdayCreate(20,10,2000);
	list_add_tail(&person->list, &birthday_list);

	person = bdayCreate(05,03,2000);
	list_add_tail(&person->list, &birthday_list);

	person = bdayCreate(30,02,1950);
	list_add_tail(&person->list, &birthday_list);

	person = bdayCreate(02,02,2002);
	list_add_tail(&person->list, &birthday_list);

	person = bdayCreate(10,20,1980);
	list_add_tail(&person->list, &birthday_list);

	//list iteration
	struct birthday *ptr;

	list_for_each_entry(ptr, &birthday_list, list) {
		printk(KERN_INFO "%d.%d.%d\n", ptr->day, ptr->month, ptr->year);
	}

       return 0;
}

void terminate(void) {
	printk(KERN_INFO "Removing Module\n");

	struct birthday *tmp;
	struct list_head *ptr, *next;

	//check empty list
	if (list_empty(&birthday_list)) {
		printk(KERN_INFO "List is empty");
		return;
	}
	//removing elements
	list_for_each_safe(ptr, next, &birthday_list){
		tmp = list_entry(ptr, struct birthday, list);
		printk(KERN_INFO "Removing %d.%d.%d\n", tmp->day, tmp->month, tmp->year);
		list_del(ptr);
		kfree(tmp);
	}


	printk(KERN_INFO "Module removed\n");
}

/* Macros for registering module entry and exit points. */
module_init( init);
module_exit( terminate);

MODULE_LICENSE( "GPL");
MODULE_DESCRIPTION( "Exercise");
MODULE_AUTHOR("Hasan Sefa Değirmenci");

