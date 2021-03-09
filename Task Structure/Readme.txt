
We have task_struct which basically stores the information about everything : pid, pointer to parent, and also some cool stuffs that I don't have knowledge to understand. 

I take pid parameter using module_param definition. It allows me to use sudo insmod myfile.ko myPid= <any number>

If there is no input, give error message.
If there is an input pid,
	iterate through all processes using for_each_process definition. 
	if there is a process that has the same pid with our input pid, print its pid, parent's id and its executable name.
	
	Also since we know the parent of this process, we can iterate through processes starting from parent to find siblings. How? By checking parent id of processes' , if they are same with the parent id of our input; THEY ARE SIBLINGS.


/* Also I have some counter's working as booleans to determine whether it is invalid process, or it has a sibling. Print proper messages accordingly */ 