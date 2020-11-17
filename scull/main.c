#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>	
#include <linux/slab.h>		
#include <linux/fs.h>		
#include <linux/errno.h>	
#include <linux/types.h>	
#include <linux/proc_fs.h>
#include <linux/fcntl.h>	
#include <linux/seq_file.h>
#include <linux/cdev.h>

#include <linux/uaccess.h>	

#include "minesweeper.h"


// TODO: Add the possibility of setting row/col/bomb count on load time.

MODULE_AUTHOR("Rodrigo Amaral Franceschinelli");
MODULE_LICENSE("Dual BSD/GPL"); // TODO: Which license?

struct minesweeper_dev device;
int minesweeper_major;

int minesweeper_open(struct inode *inode, struct file *filp)
{
	struct minesweeper_dev *dev;

	dev = container_of(inode->i_cdev, struct minesweeper_dev, cdev);
	filp->private_data = dev; 

	return 0;
}

int minesweeper_release(struct inode *inode, struct file *filp)
{
	return 0;
}


void exec_play(struct minesweeper_dev *dev, int position) 
{
	// TODO: Verify if a bomb has exploded and interrupt the game loop.
	dev->board[position] = OPEN_CELL;
}

void create_board(struct minesweeper_dev *dev)
{
	int i;

	if (!dev->board) 
	{
		dev->board = kmalloc(sizeof(char) * BOARD_SZ, GFP_KERNEL);
		if (!dev->board)
		{
			printk(KERN_NOTICE "There is no memory enough to create a new board.");
			return;
		}
	}

	for (i = 0; i < BOARD_SZ; i++)
		dev->board[i] = NOT_OPEN_CELL;
}

void generate_bomb_positions(struct minesweeper_dev *dev) 
{
	int i;

	if (!dev->bomb_positions) 
	{
		dev->bomb_positions = kmalloc(sizeof(int) * BOMB_COUNT, GFP_KERNEL);
		if (!dev->bomb_positions)
		{
			printk(KERN_NOTICE "There is no memory enough to create the list of bomb positions.");
			return;
		}
	}

	// TODO: Use a random function to generate the bombs.
	for (i = 1; i <= BOMB_COUNT; ++i)
	{
		dev->bomb_positions[i - 1] = i * 3;
	}
}

void restart_game(struct minesweeper_dev *dev) 
{
	generate_bomb_positions(dev);
	create_board(dev);
}

/**
 * Read the board sequentially.
*/
ssize_t minesweeper_read(struct file *filp, char __user *buf, size_t count,
                loff_t *f_pos)
{
	struct minesweeper_dev *dev = filp->private_data; 

	if (*f_pos >= BOARD_SZ)
		return 0;
	if (*f_pos + count > BOARD_SZ)
		count = BOARD_SZ - *f_pos;

	if (!dev->game_loop)
		restart_game(dev);

	//TODO: Add a \n at the end of each row.
	if (copy_to_user(buf, dev->board + *f_pos, count)) {
		return -EFAULT;
	}

	*f_pos += count;
	return count;
}

ssize_t minesweeper_write(struct file *filp, const char __user *buf, size_t count,
                loff_t *f_pos)
{
	struct minesweeper_dev *dev = filp->private_data;
	char *play_buf;
	long play;

	play_buf = kmalloc(sizeof(char) * count, GFP_KERNEL);
	if (!play_buf)
		return 0;

	if (copy_from_user(play_buf, buf, count)) 
		return -EFAULT;

	if (kstrtol(play_buf, 10, &play) != 0) // TODO:  
		return 0; // TODO: Search what would be the correct way of reporting this error.

	exec_play(dev, play);

	return count;
}

struct file_operations minesweeper_fops = {
	.owner =    THIS_MODULE,
	.read =     minesweeper_read,
	.write =    minesweeper_write,
	.open =     minesweeper_open,
	.release =  minesweeper_release,
};

/*
 * Set up the char_dev structure for this device.
 */
static void minesweeper_setup_cdev(void)
{
	int err, devno = MKDEV(minesweeper_major, 0);
    
	cdev_init(&device.cdev, &minesweeper_fops);
	device.cdev.owner = THIS_MODULE;
	
	err = cdev_add (&device.cdev, devno, 1);
	if (err)
		printk(KERN_NOTICE "Error %d adding minesweeper", err);
}

int minesweeper_init_module(void)
{
	int result;
	dev_t dev = 0;

	result = alloc_chrdev_region(&dev, 1, 1, "minesweeper");
	minesweeper_major = MAJOR(dev);
	if (result < 0) {
		printk(KERN_WARNING "minesweeper: can't get major %d\n", minesweeper_major);
		return result;
	}

	minesweeper_setup_cdev();

	return result;
}

module_init(minesweeper_init_module);
//module_exit(minesweeper_cleanup_module);
