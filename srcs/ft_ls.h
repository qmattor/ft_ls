/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:07:17 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/09 21:35:44 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LS_H
# define _FT_LS_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <grp.h>
# include <stdio.h>
# include <pwd.h>
# include <time.h>
# include <sys/ioctl.h>
# include <errno.h>
# define NUM_ARGS 8
# define LINK_BUF_SIZE 255
# define NORMAL 0
# define LONG 1
# define ALL 2
# define ALLONG 3
# define L 0
# define REC 1
# define A 2
# define REV 3
# define T 4
# define S 5
# define F 6
# define SLASH 7
# define USER 0
# define GROUP 1
# define ARGUMENTS "lRartsf"

/*
**	0 is normal
**	1 is long
**	2 is all
**	3 is both
**	args: lRartsf (/, interperted as an argument, but not inputed as such)
*/

/*
**	total number of 512-byte blocks used by the files - thats the total thinggy
**	args: lRartsf
*/

typedef struct			s_item
{
	ino_t				d_fileno;
	char				*name;
	struct stat			*stat;
	struct s_item		*next;
	char				*gid;
	char				*uid;
}						t_item;

typedef struct stat		t_stat;

extern int				errno;

t_item					*createlem(struct dirent *ditem, char *path);
t_item					*push(t_item *stack, t_item *ele);
int						pop(t_item **stack);
char					printele(char mode, t_item *ele, char *path);
int						read_from_dir(char *path, char *args);
t_item					*sort(t_item *stack, int(*compare)(t_item *, t_item *));
int						by_name(t_item *i1, t_item *i2);
t_item					*merge(t_item *lst1, t_item *lst2,
						int(*compare)(t_item *, t_item *));
void					printlst(int bytes, t_item *lst, char mode, char *path);
t_item					*splitlst(t_item *start);
int						is_directory(t_item *ele);
int						lstlen(t_item *stack);
char					*create_path(char *path, char *name);
void					errcls(int status, char *reason);
int						is_link(t_item *ele);
int						o_excu(t_item *ele);
int						o_write(t_item *ele);
int						o_read(t_item *ele);
int						u_excu(t_item *ele);
int						g_excu(t_item *ele);
int						g_write(t_item *ele);
int						g_read(t_item *ele);
int						u_write(t_item *ele);
int						u_read(t_item *ele);
char					*argsparse(char *str);
int						by_time(t_item *i1, t_item *i2);
char					*combineargs(char *args1, char *args2);
void					printargs(void);
int						rev_name(t_item *i1, t_item *i2);
int						rev_time(t_item *i1, t_item *i2);
void					dir_stuff(t_item **dirstack, char *path, char *args);
t_item					*sorts(char *args, t_item **stack);
void					prints(int bytes, char *args,
						t_item **stack, char *path);
void					mode0(t_item *lst, char *path);
void					mode1(t_item *lst, char *path, int group, int user);
void					mode2(t_item *lst, char *path);
void					mode3(t_item *lst, char *path, int group, int user);
int						num_links(t_item *ele);
int						item_size(t_item *ele);
char					*get_group(t_item *ele);
char					*get_user(t_item *ele);
void					print_date(t_item *ele);
void					print_link(char *path);
void					printstuffnthings(t_item *ele);
t_item					*delst(t_item *lst);
void					printnum(int num, int size);
void					printpath(char *path);
/*
**void					stat_ele(t_item *ele);
**void					stat_lst(t_item *lst);
*/
t_item					*place(t_item *lst, t_item *p,
						int(*compare)(t_item *, t_item *), char c);
t_item					*sort1(t_item *lst, int(*compare)(t_item *, t_item *));
int						block(t_item *ele, char c);
int						totalstack(t_item *stack, char c);
void					listformat(t_item *lst, char mode);
int						longestname(t_item *lst);
void					pdenied(char *path);
void					fnfound(char *path);
int						fspace(t_item *lst, int (*f)(t_item *));
int						grouplen(t_item *lst);
int						userlen(t_item *lst);
int						linklens(t_item *lst);
int						sizelen(t_item *lst);
void					fixpath(char *path, char *args);
int						slink(char *path);
int						read_item(char *path, char *args);
void					read_from_link(char *path, char *args, t_item *ele);
t_item					*pathele(char *path);
char					calnewlink(char *newpath);
void					printminmaj(t_item *ele);
void					printuser(t_item *ele, char size);
void					printgroup(t_item *ele, char size);
void					printlong(t_item *ele, char *path,
						int uspac, int gspace);
void					printlonglink(t_item *ele, char *path,
						int uspac, int gspace);
struct stat				*getstat(char *path);
void					usage(char c);
void					printlonglinkv2(t_item *ele, char *path,
						int uspac, int gspace);
#endif
