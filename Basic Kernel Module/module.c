#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/types.h>
#include<linux/slab.h>


/*It is homework of part 1 of the chapter you assigned us to implement*/ 

int fileinfo304_init(void)
{
       printk(KERN_INFO "Loading Module\n");
                                                                                             

       return 0;
}

void fileinfo304_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init( fileinfo304_init);
module_exit( fileinfo304_exit);

MODULE_LICENSE( "GPL");
MODULE_DESCRIPTION( "Exercise");
MODULE_AUTHOR("Hasan Sefa Degirmenci");

