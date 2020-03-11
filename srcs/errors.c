/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:47:23 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/10 20:30:02 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	hit unavoidable error -gracful exit, prints code and reason for exiting
*/

void	errcls(int status, char *reason)
{
	char	*str;

	str = ft_itoa(status);
	write(2, "\nerror: exited with status ", 28);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	write(2, reason, ft_strlen(reason));
	write(2, "\n", 1);
	free(str);
	exit(status);
}

/*
**	permsision denied for file access
*/

void	pdenied(char *path)
{
	char	*temp;

	temp = ft_strrchr(path, '/');
	write(2, "./ft_ls: ", 9);
	write(2, temp + 1, ft_strlen(temp) - 1);
	write(2, ": Permison Denied\n", 18);
}

/*
**	file not found
*/

void	fnfound(char *path)
{
	write(2, "./ft_ls: ", 10);
	write(2, path, ft_strlen(path));
	write(2, ": No such file or directory\n", 28);
	exit(errno);
}

void	usage(char c)
{
	write(1, "./ft_ls: illegal option -- ", 27);
	write(1, &c, 1);
	write(1, "\nusage: ./ft_ls [-", 18);
	write(1, ARGUMENTS, 7);
	write(1, "] [file ...]\n", 13);
	exit(1);
}

/*
**void	stat_ele(t_item *ele)
**{
**	static int	x = 0;
**	printf("\nele: %p    name: %s    next: %p   \nx: %i\n", ele, ele->name, ele->next, x);
**	x++;
**}
**
**void	stat_lst(t_item *lst)
**{
**	while (lst)
**	{
**		stat_ele(lst);
**		lst = lst->next;
**	}
**}
*/
