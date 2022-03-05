#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday{
  int day;
  int month;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

int simple_init(void)
{
  printk(KERN_INFO "Loading Module\n");
  
  for(int i=0; i<5; i++)
  {
  
    struct birthday *person;
    person = kmalloc(sizeof(person),GFP_KERNEL);
    person->day = 14+i;
    person->month = 3;
    person->year = 2001;
    
    INIT_LIST_HEAD(&person->list);
    
    list_add_tail(&person->list,&birthday_list);
  }
  
  struct birthday *ptr;
  
  printk(KERN_INFO "year/day/month\n");

  list_for_each_entry(ptr,&birthday_list,list)
  {
  	 printk(KERN_INFO "%d/%d/%d\n", ptr->year, ptr->day, ptr->month);
  }

  return 0;
}

void simple_exit(void)
{

  printk(KERN_INFO "Emoving Module\n");

  struct birthday *ptr;

  list_for_each_entry(ptr,&birthday_list,list)
  {
	 kfree(ptr);
  }

  printk(KERN_INFO "All space become free now!\n");
  
}

module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("simple module");
MODULE_AUTHOR("SGG");
