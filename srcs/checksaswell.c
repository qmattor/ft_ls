/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksaswell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 18:08:19 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/08 16:53:51 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		g_read(t_item *ele)
{
	return (ele->stat->st_mode & S_IRGRP);
}

int		g_write(t_item *ele)
{
	return (ele->stat->st_mode & S_IWGRP);
}

int		g_excu(t_item *ele)
{
	return (ele->stat->st_mode & S_IXGRP);
}

int		u_excu(t_item *ele)
{
	return (ele->stat->st_mode & S_IXUSR);
}
