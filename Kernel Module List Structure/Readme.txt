I followed the instructions of the book chapter.

We have list definition in the kernel.
struct list_head ->creates list_head 
INIT_LIST_HEAD -> initializes the head of the list


We can add birthday instances to the end of the linked list using the list_add_tail() macro:


list for each entry() macro accepts three parameters:
• A pointer to the structure being iterated over
• A pointer to the head of the list being iterated over
• The name of the variable containing the list head structure


list for each entry safe() -> it is like for_each_entry but safer one. accepts also the next pointer. In this iteration we use list_del to delete the head of the list.