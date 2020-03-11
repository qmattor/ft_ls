/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couplemoreprints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:40:26 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/10 20:10:59 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	prints a number right adjusted so that the
**	last digits will all align based on size
*/

void	printnum(int num, int size)
{
	int		x;
	char	*str;

	str = ft_itoa(num);
	x = size - 1 - ft_strlen(str);
	while (x < 0)
		x += size;
	while (x--)
		write(1, " ", 1);
	write(1, str, ft_strlen(str));
	free(str);
}

/*
**	prints the stack in the -1 format
*/

void	listformat(t_item *lst, char mode)
{
	if (!lst)
		return ;
	if (lst->name[0] != '.')
	{
		write(1, lst->name, ft_strlen(lst->name));
		write(1, "\n", 1);
	}
	else if (mode)
	{
		write(1, lst->name, ft_strlen(lst->name));
		write(1, "\n", 1);
	}
	listformat(lst->next, mode);
}

/*
**	prints the path to the current dir
*/

void	printpath(char *path)
{
	write(1, path, ft_strlen(path));
	write(1, "\n", 1);
}

/*
**	this was made badly, it logically should be 2 seperate functions
*/

void	printgrus(t_item *lst, int size, char mode)
{
	if (mode == GROUP)
	{
		size -= ft_strlen(lst->gid);
		size += 2;
		write(1, lst->gid, ft_strlen(lst->gid));
		while (size--)
			write(1, " ", 1);
	}
	if (mode == USER)
	{
		size -= ft_strlen(lst->uid);
		size += 2;
		write(1, lst->uid, ft_strlen(lst->uid));
		while (size--)
			write(1, " ", 1);
	}
}

void	printminmaj(t_item *ele)
{
	write(1, " ", 1);
	printnum(major(ele->stat->st_dev), 4);
	write(1, ", ", 2);
	printnum(minor(ele->stat->st_dev), 4);
}