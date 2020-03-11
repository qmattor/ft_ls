/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreprints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:04:01 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/09 19:01:38 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	0 is normal
**	1 is long
**	2 is all
**	3 is all and long
*/

void	mode0(t_item *lst, char *path)
{
	int				nl;
	int				x;
	int				cols;
	int				set;
	struct winsize	w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	set = longestname(lst) + 2;
	x = set;
	cols = (w.ws_col / x) - 1;
	nl = 0;
	while (lst != NULL)
	{
		if (lst->next != NULL)
		{
			printele(0, lst, path);
			if (lst->name[0] != '.')
			{
				nl++;
				x -= ft_strlen(lst->name);
				while (x-- >= 0)
					write(1, " ", 1);
				if (nl % cols == 0)
					write(1, "\n", 1);
			}
		}
		else
			printele(0, lst, path);
		x = set;
		lst = lst->next;
	}
	write(1, "\n", 1);
}

void	mode1(t_item *lst, char *path, int group, int user)
{
	while (lst != NULL)
	{
		if (lst->name[0] != '.')
		{
			if (lst->stat == NULL)
				pdenied(path);
			printlong(lst, path, user, group);
			write(1, "\n", 1);
		}
		lst = lst->next;
	}
}

void	mode2(t_item *lst, char *path)
{
	int				nl;
	int				x;
	int				cols;
	int				set;
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	nl = 0;
	set = longestname(lst) + 2;
	x = set;
	cols = (w.ws_col / x) - 1;
	while (lst != NULL)
	{
		if (lst->next != NULL)
		{
			printele(2, lst, path);
			nl++;
			x -= ft_strlen(lst->name);
			while (x-- >= 0)
				write(1, " ", 1);
			if (nl % cols == 0)
				write(1, "\n", 1);
		}
		x = set;
		lst = lst->next;
	}
	write(1, "\n", 1);
}

void	mode3(t_item *lst, char *path, int group, int user)
{
	while (lst != NULL)
	{
		printlong(lst, path, group, user);
		write(1, "\n", 1);
		lst = lst->next;
	}
}
/*
**	displays the date using a ctime call
*/
void	print_date(t_item *ele)
{
	char			*str;
	time_t			x;

	x = ele->stat->st_mtime;
	str = ctime(&x);
	write(1, str + 4, ft_strlen(str) - 13);
}
