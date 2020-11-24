/*
 * csaw.c
 * CSAW CTF Challenge Kernel Module
 * Jon Oberheide <jon@oberheide.org>
 *
 * This module implements the /proc/csaw interface which can be read
 * and written like a normal file. For example:
 *
 * $ cat /proc/csaw
 * Welcome to the CSAW CTF challenge. Best of luck!
 * $ echo "Hello World" > /proc/csaw
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/string.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>

#define MAX_LENGTH 64

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jon Oberheide");
MODULE_DESCRIPTION("CSAW CTF Challenge Kernel Module");

struct proc_dir_entry *csaw_proc;// = proc_mkdir("csaw", NULL);

ssize_t csaw_write(struct file *file, const char __user *ubuf, size_t size, loff_t *offset)
{
    char buf[MAX_LENGTH];

    printk(KERN_INFO "csaw: called csaw_write\n");

    /*
     * We should be safe to perform this copy from userspace since our
     * kernel is compiled with CC_STACKPROTECTOR, which includes a canary
     * on the kernel stack to protect against smashing the stack.
     *
     * While the user could easily DoS the kernel, I don't think they
     * should be able to escalate privileges without discovering the
     * secret stack canary value.
     */
    if (copy_from_user(&buf, ubuf, size)) {
        printk(KERN_INFO "csaw: error copying data from userspace\n");
        return -EFAULT;
    }

    return size;
}

ssize_t csaw_read(struct file *file, char __user *ubuf, size_t size, loff_t *offset)
{
    char buf[MAX_LENGTH];

    printk(KERN_INFO "csaw: called csaw_read\n");

    memset(buf, 0, sizeof(buf));
    strcpy(buf, "Welcome to the CSAW CTF challenge. Best of luck!\n");
    memcpy(ubuf, buf + *offset, MAX_LENGTH);
    //printk(ubuf);

    return 0;
}

static const struct file_operations my_csaw_fops = {
    .owner = THIS_MODULE,
    .read  = csaw_read,
    .write  = csaw_write,
};

static int __init
csaw_init(void)
{
    csaw_proc = proc_create("csaw", 0x0666, NULL, &my_csaw_fops);
    printk(KERN_INFO "csaw: loading module\n");

    printk(KERN_INFO "csaw: created /proc/csaw entry\n");

    return 0;
}

static void __exit
csaw_exit(void)
{
    if (csaw_proc) {
        remove_proc_entry("csaw", csaw_proc);
    }

    printk(KERN_INFO "csaw: unloading module\n");
}

module_init(csaw_init);
module_exit(csaw_exit);

