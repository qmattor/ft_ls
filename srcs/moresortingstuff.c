/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moresortingstuff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:16:24 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/08 22:39:57 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returns a comparison based on the name of the 2 strings
*/

int		by_name(t_item *i1, t_item *i2)
{
	return (ft_strcmp(i1->name, i2->name));
}

/*
**	returns a comparison based on last modification time
*/

int		by_time(t_item *i1, t_item *i2)
{
	if (i1->stat->st_mtime < i2->stat->st_mtime)
		return (1);
	else
		return (-1);
}

/*
**	returns a reversed comparison based on the name of the 2 strings
*/

int		rev_name(t_item *i1, t_item *i2)
{
	return (-ft_strcmp(i1->name, i2->name));
}

/*
**	returns a reversed comparison based on last modification time
*/

int		rev_time(t_item *i1, t_item *i2)
{
	if (i1->stat->st_mtime < i2->stat->st_mtime)
		return (-1);
	else
		return (1);
}

/*
**	creates a new path by taking the old path
**	and adding a / and then the name of the subdir
*/

char	*create_path(char *path, char *name)
{
	char	*temp;
	char	*temp2;
	int		slash;

	if (!ft_strcmp(path, "/"))
		return (ft_strjoin(path, name));
	if (path[ft_strlen(path)] == '/')
		slash = 1;
	else
		slash = 0;
	temp = ft_strjoin(path, "/");
	temp2 = temp;
	temp = ft_strjoin(temp, name);
	free(temp2);
	if (slash)
	{
		temp2 = temp;
		temp = ft_strjoin(temp, "/");
		free(temp2);
	}
	return (temp);
}