#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("emmmhla");
MODULE_DESCRIPTION("A simple hello world program.");
MODULE_VERSION("17.08.21");

static const struct usb_device_id device_table[] = {
	{USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_KEYBOARD)},
	{},
};

MODULE_DEVICE_TABLE(usb, device_table);

static int probe_func(struct usb_interface *intf,
	const struct usb_device_id *id)
{
	printk(KERN_INFO "Probe function.\n");
	return 0;
}

static void disconnect_func(struct usb_interface *intf)
{
	printk(KERN_INFO "Disconnect function.\n");
}

static struct usb_driver device_driver = {
	.name = "emmmhla_device_driver",
	.id_table = device_table,
	.probe = probe_func,
	.disconnect = disconnect_func,
};

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return usb_register(&device_driver);
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	usb_deregister(&device_driver);
}

module_init(hello_init);
module_exit(hello_cleanup);
