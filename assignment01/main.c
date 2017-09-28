#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("emmmhla");
MODULE_DESCRIPTION("A simple hello world program.");
MODULE_VERSION("17.08.21");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return (0);
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
