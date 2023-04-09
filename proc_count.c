#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>

static struct proc_dir_entry *entry;

static int example(struct seq_file *m, void *v){
        seq_printf(m, "hello world\n");
        struct task_struct *p;
        int sqr_sum = 0;
        for_each_process(p) {
              seq_printf(m, "hello world\n");
        }
        return 0;
}


static int __init proc_count_init(void)
{
        entry = proc_create_single("count", 0, NULL, example);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
        proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Brian Yang");
MODULE_DESCRIPTION("Count the number of running processes");
MODULE_LICENSE("GPL");
