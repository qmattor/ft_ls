THIS IS A LIST OF EVERY FUNCTION AND WHICH PROGRAM ITS IN ASWELL AS A DESCRIPTION

args.c:

    char	*argsparse(char *str):

    uses strchr to check if the str has the argument


    void	fixpath(char *path, char *args):

    if a slash is found at the end of an input it get regestered as an argument


    char	*combineargs(char *args1, char *args2):

    adds the argument lists together to get a resultant list of arguments
    NOTE: USES ARGS1 DATA SPACE


    void	printargs(void):

    usage case





blocks.c:

    int		block(t_item *ele, char c):

    returns the block size of a file depeding on mode (c)


    int		totalstack(t_item *stack, char c):

    returns the number of blocks in the item stack based on mode (c)


    int		longestname(t_item *lst):

	gets the longest name in the item stack
	seriously iteratively would have been a lot better :(





checks.c:

    just checks dude -pretty self explanitory

    int		is_directory(t_item *ele)

    int		is_link(t_item *ele)

    int		is_file(t_item *ele)

    int		u_read(t_item *ele)

    int		u_write(t_item *ele)





checksaswell.c:

    wish I could just put all of the checks in one file :(

    int		g_read(t_item *ele)

    int		g_write(t_item *ele)

    int		g_excu(t_item *ele)

    int		u_excu(t_item *ele)





evenmorechecks.c:

    just more checks

    int		o_read(t_item *ele)

    int		o_write(t_item *ele)

    int		o_excu(t_item *ele)

    int		num_links(t_item *ele)





couplemoreprints.c:

    void	printnum(int num, int size):

	prints a number right adjusted so that the
	last digits will all align based on size


    void	listformat(t_item *lst, char mode):

	prints the stack in the -1 format


    void	printpath(char *path):

	prints the path to the current dir


    void	printgrus(t_item *lst, int size, char mode):

    this was made badly, it logically should be 2 seperate functions





errors.c:

    void	errcls(int status, char *reason):

	hit unavoidable error -gracful exit, prints code and reason for exiting


    void	pdenied(char *path):

    permsision denied for file access


    void	fnfound(char *path):

    file not found






**  ft_ls.c ** <- main() is in here:

    void	dir_stuff(t_item **dirstack, char *path, char *args)

	handles the -R if required
	creates next path and adds to the str then calls read_from_dir on it


    t_item	*sorts(char *a, t_item **stack)

	just handles the different options for sorting


    void	prints(int bytes, char *args, t_item **stack, char *path)

   	handles different options for printing


    int		read_from_dir(char *path, char *args)

	sudo main
	opens diretory and reads items in it
	tehn calls sort and print on the stack


    int		main(int argc, char **argv)

	main, what more do I need to say





moreprints.c:

	0 is normal
	1 is long
	2 is all
	3 is all and long

    void	mode0(t_item *lst, char *path)
    void	mode1(t_item *lst, char *path)
    void	mode2(t_item *lst, char *path)
    void	mode3(t_item *lst, char *path)

    void	print_date(t_item *ele):

    displays the date using a ctime call





moresortingstuff.c:

    int		by_name(t_item *i1, t_item *i2):

   	returns a comparison based on the name of the 2 strings


    int		by_time(t_item *i1, t_item *i2):

   	returns a comparison based on last modification time


    int		rev_name(t_item *i1, t_item *i2):

    returns a reversed comparison based on the name of the 2 strings


    int		rev_time(t_item *i1, t_item *i2):

    returns a reversed comparison based on last modification time


    char	*create_path(char *path, char *name):

    creates a new path by taking the old path
    and adding a / and then the name of the subdir





othersort.c <- this is an extra sort method that is slower that the merge sort but I already made it:

**	this is a stack insertion sort
**	it will hold each element in a function call and insert them where they need to be

    t_item	*place(t_item *lst, t_item *p, int(*compare)(t_item *, t_item *), char c):

	this is the insertion algorithm


    t_item	*sort1(t_item *lst, int(*compare)(t_item *, t_item *)):

	scrapes ach element into a function call until placed





paddings.c:

    int		grouplen(t_item *lst):

   	returns the strlen of the group


    int		userlen(t_item *lst):

    returns the strlen of the user


    int		linklens(t_item *lst):

	returns the number of digits of the link num


    int		sizelen(t_item *lst):

	returns the number of digits for the item size


    int		fspace(t_item *lst, int (*f)(t_item *)):

	this is some retarded ass shit - fix it
	whatchu doin bro





pathandler.c - work in progress:

    int		read_item(char *path, char *args):

    decides what the item is, then what to do with it


    t_item	*pathele(char *path):

    creates an element from a path

    supposed to be the first determination of what to do

    leaving this blank for now because it doesnt really work at all





prints.c:

    void	printstuffnthings(t_item *ele):

    prints out the permisions for an item
    note needs to be updated for ~stuff~


    void	printlong(t_item *ele, char *path, int uspac, int gspace):

	print an item in the long format


    char	printele(char mode, t_item *ele, char *path):

    prints a single element in the specified format (c)
    -- pretty sure I can get rid of this and just use the mode functions


    void	printlst(int bytes, t_item *lst, char mode, char *path):

	prints out an entire stack in the specified format (c)


    void	print_link(char *path):

	prints the path to where a link is going to





sort.c <- main/defualt merge sort:

    THIS WORKS DON'T TOUCH





statreads.c:

	more checks n stuff, but this time returning values

    char	*get_user(t_item *ele)

    char	*get_group(t_item *ele)

    int		item_size(t_item *ele)

    int		last_mod(t_item *ele)





structstuff.c:

	basic stack funcs, pretty self explanitory

    t_item	*createlem(struct dirent *ditem, char *path)

    t_item	*push(t_item *stack, t_item *ele)

    int	pop(t_item **stack)

    t_item	*delst(t_item *lst)
