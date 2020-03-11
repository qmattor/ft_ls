/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evenmorechecks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:15:13 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/27 16:58:16 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	just more checks
*/

int		o_read(t_item *ele)
{
	return (ele->stat->st_mode & S_IROTH);
}

int		o_write(t_item *ele)
{
	return (ele->stat->st_mode & S_IWOTH);
}

int		o_excu(t_item *ele)
{
	return (ele->stat->st_mode & S_IXOTH);
}

int		num_links(t_item *ele)
{
	return (ele->stat->st_nlink);
}