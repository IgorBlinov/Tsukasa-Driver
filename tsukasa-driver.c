
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE_NAME "Tsukasa Virtual Video Adapter"

MODULE_DESCRIPTION("Tsukasa Virtual Video Driver");
MODULE_AUTHOR("Hunchback,,, (hunchback@IGOREK)");
MODULE_LICENSE("$LICENSE$");

static int device_number;
struct file_operations file_ops;

static int tsukasa_init_module(void)
{
	device_number = register_chrdev(0, DEVICE_NAME, &file_ops);
	if(device_number < 0)
	{
		printk("Failed to register device\n");
		return device_number;
	}
	printk( KERN_DEBUG "Tsukasa module initialized\n" );
	return 0;
}

static void tsukasa_exit_module(void)
{
	unregister_chrdev(device_number, DEVICE_NAME);
	printk("Device unregistered successfully\n");
	printk( KERN_DEBUG "Tsukasa module exited\n" );
}

module_init(tsukasa_init_module);
module_exit(tsukasa_exit_module);
