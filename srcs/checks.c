/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:34:06 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/27 16:21:58 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	just checks dude
*/

int		is_directory(t_item *ele)
{
	return (S_ISDIR(ele->stat->st_mode));
}

int		is_link(t_item *ele)
{
	return (S_ISLNK(ele->stat->st_mode));
}

int		is_file(t_item *ele)
{
	return (S_ISREG(ele->stat->st_mode));
}

int		u_read(t_item *ele)
{
	return (ele->stat->st_mode & S_IRUSR);
}

int		u_write(t_item *ele)
{
	return (ele->stat->st_mode & S_IWUSR);
}
