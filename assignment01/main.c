#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("emmmhla");
MODULE_DESCRIPTION("A simple hello world program.");
MODULE_VERSION("17.08.21");

static int __init hello_init(void)
{
	/*
	struct timeval	tv;
	struct tm	tm_s;

	do_gettimeofday(&tv);
	time_to_tm(tv.tv_sec, 0, &tm_s);
	printk(KERN_INFO "[%d:%d:%d] Hello World! \n", tm_s.tm_hour,
		tm_s.tm_min, tm_s.tm_sec);
	*/
	printk(KERN_INFO "Hello World!\n");
	return (0);
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
