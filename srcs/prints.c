/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:56:04 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/10 19:54:53 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	prints out the permisions for an item
**
**	note needs to be updated for ~stuff~
*/

void	printstuffnthings(t_item *ele)
{
	if (is_link(ele))
		write(1, "l", 1);
	else if (is_directory(ele))
		write(1, "d", 1);
	else if (S_ISSOCK(ele->stat->st_mode))
		write(1, "s", 1);
	else if (S_ISFIFO(ele->stat->st_mode))
		write(1, "p", 1);
	else if (S_ISCHR(ele->stat->st_mode))
		write(1, "c", 1);
	else if (S_ISBLK(ele->stat->st_mode))
		write(1, "b", 1);
	else
		write(1, "-", 1);
	write(1, (u_read(ele)) ? "r" : "-", 1);
	write(1, (u_write(ele)) ? "w" : "-", 1);
	write(1, (u_excu(ele)) ? "x" : "-", 1);
	write(1, (g_read(ele)) ? "r" : "-", 1);
	write(1, (g_write(ele)) ? "w" : "-", 1);
	write(1, (g_excu(ele)) ? "x" : "-", 1);
	write(1, (o_read(ele)) ? "r" : "-", 1);
	write(1, (o_write(ele)) ? "w" : "-", 1);
	write(1, (o_excu(ele)) ? "x" : "-", 1);
}

/*
**	print an item in the long format
*/

void	printlong(t_item *ele, char *path, int uspac, int gspace)
{
	char	*str;

	printstuffnthings(ele);
	printf("test1\n");
	write(1, " ", 1);
	printf("test6\n");
	write(1, "\n", 1);
	printnum(num_links(ele), 4);
	write(1, "\n", 1);
	printf("test2\n");
	write(1, " ", 1);
	printuser(ele, uspac);
	printgroup(ele, gspace);
	printf("test3\n");
	printnum(item_size(ele), 8);
	S_ISCHR(ele->stat->st_mode) ? printminmaj(ele) : 0;
	write(1, " ", 1);
	print_date(ele);
	printf("test4\n");
	write(1, " ", 1);
	write(1, ele->name, ft_strlen(ele->name));
	printf("test5\n");
	if (S_ISLNK(ele->stat->st_mode))
	{
		str = create_path(path, ele->name);
		write(1, " -> ", 4);
		print_link(str);
		free(str);
	}
}

/*
**	prints a single element in the specified format (c)
**	-- pretty sure I can get rid of this and just use the mode functions
*/

char	printele(char mode, t_item *ele, char *path)
{
	if (mode == NORMAL)
		if (ele->name[0] != '.')
			return (write(1, ele->name, ft_strlen(ele->name)));
	if (mode == LONG)
		if (ele->name[0] != '.')
		{
			printlong(ele, path, fspace(ele, &userlen), fspace(ele, &grouplen));
			return (1);
		}
	if (mode == ALL)
		return (write(1, ele->name, ft_strlen(ele->name)));
	if (mode == ALLONG)
	{
		printlong(ele, path, fspace(ele, &grouplen), fspace(ele, &userlen));
		return (1);
	}
	return (0);
}

/*
**	prints out an entire stack in the specified format (c)
*/

void	printlst(int bytes, t_item *lst, char mode, char *path)
{
	char	*str;
	int		group = fspace(lst, &grouplen);
	int		user = fspace(lst, &userlen);

	if (lstlen(lst) == 2 && (mode != ALL && mode != ALLONG))
		return ;
	if (mode == LONG || mode == ALLONG)
	{
		str = ft_itoa(bytes);
		write(1, "total ", 6);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
		free(str);
	}
	if (mode == NORMAL)
		mode0(lst, path);
	if (mode == LONG)
		mode1(lst, path, group, user);
	if (mode == ALL)
		mode2(lst, path);
	if (mode == ALLONG)
		mode3(lst, path, group, user);
}

/*
**	prints the path to where a link is going to
*/

void	print_link(char *path)
{
	char	*buf;
	int		x;

	buf = malloc(LINK_BUF_SIZE);
	x = readlink(path, buf, LINK_BUF_SIZE);
	buf[x >= 0 ? x : 0] = 0;
	write(1, buf, ft_strlen(buf));
	free(buf);
}
