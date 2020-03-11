/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:54:40 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/10 21:14:10 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	decides what the item is, then what to do with it
*/

int			read_item(char *path, char *args)
{
	t_item		*ele;

	ele = pathele(path);
	if (S_ISDIR(ele->stat->st_mode))
		read_from_dir(path, args);
	else if (S_ISLNK(ele->stat->st_mode))
		read_from_link(path, args, ele);
	else
		if (args[L])
		{
			printele(LONG, ele, path);
			write(1, "\n", 1);
		}
		else
		{
			printele(NORMAL, ele, path);
			write(1, "\n", 1);
		}
	free(ele->stat);
	free(ele);
	return (1);
}

/*
**	creates an element from a path
*/

t_item		*pathele(char *path)
{
	t_item	*ele;
	struct stat	*sta;

	sta = (t_stat *)ft_strnew(sizeof(t_stat));
	ele = malloc(sizeof(t_item));
	if (lstat(path, sta))
		errno == 14 ? pdenied(path) : fnfound(path);
	ele->stat = sta;
	ele->gid = get_group(ele);
	ele->uid = get_user(ele);
	ele->next = NULL;
	ele->name = ft_strrchr(path, '/') != NULL ? ft_strrchr(path, '/') + 1 : path;
	return (ele);
}

/*
**	manages links
**	-> for dirs
**		-> print link only when -l
**		-> print link only when no slash
**	-> for items
**		-> print link when -l
**		-> when theres a slash use stat not lstat
*/

void		read_from_link(char *path, char *args, t_item *ele)
{
	char	*buf;
	char	*newpath;
	int		x;
	t_item	*newele;

	buf = malloc(LINK_BUF_SIZE);
	x = readlink(path, buf, LINK_BUF_SIZE);
	buf[x] = 0;
	if (ft_strrchr(path, '/') == path)		//is a root directory
	{
		newpath = ft_strjoin("/", buf);
		newele = pathele(newpath);
	}
	else
	{
		newele = pathele(buf);
		newpath = ft_strdup(buf);
	}
	if (is_directory(newele))
	{
		if (args[L] && !args[SLASH])
		{
			printlonglink(ele, newpath, fspace(ele, &userlen), fspace(ele, &grouplen));
		}
		else
			read_from_dir(newpath, args);
	}
	else
	{
		if (args[L])
		{
			if (args[SLASH])
			{
				printf("%p\n", ele->stat);
				free(ele->stat);
				ele->stat = getstat(path);
				printf("%p\n", ele->stat);
				printlong(ele, path, fspace(ele, &userlen), fspace(ele, &grouplen));
				write(1, "\n", 1);
			}
			else
				printlonglink(ele, newpath, fspace(ele, &userlen), fspace(ele, &grouplen));
		}
		else
		{
			printele(NORMAL, ele, path);
			write(1, "\n", 1);
		}
	}
	free(newpath);
	free(buf);
	free(newele->stat);
	free(newele);
	return ;
}

/*
**	prints a link in the long format
*/

void		printlonglink(t_item *ele, char *path, int uspac, int gspace)
{
	printstuffnthings(ele);
	write(1, " ", 1);
	printnum(num_links(ele), 4);
	write(1, " ", 1);
	printuser(ele, uspac);
	printgroup(ele, gspace);
	printnum(item_size(ele), 8);
	S_ISCHR(ele->stat->st_mode) ? printminmaj(ele) : 0;
	write(1, " ", 1); 
	print_date(ele);
	write(1, " ", 1);
	write(1, ele->name, ft_strlen(ele->name));
	write(1, " -> ", 4);
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
}

struct stat	*getstat(char *path)
{
	struct stat	*sta;

	sta = malloc(sizeof(struct stat *));
	printf("%p", sta);
	if (stat(path, sta) != 0)
	{
		free(sta);
		pdenied(path);
		exit(1);
	}
	return (sta);
}