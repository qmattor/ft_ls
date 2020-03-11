/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statreads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:38:08 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/27 19:05:03 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	more checks n stuff, but this time returning values
*/

char	*get_user(t_item *ele)
{
	struct passwd *pws;

	pws = getpwuid(ele->stat->st_uid);
	if (!pws)
		errcls(3, "uid's not read");
	return (pws->pw_name);
}

char	*get_group(t_item *ele)
{
	struct group *pws;

	pws = getgrgid(ele->stat->st_gid);
	if (!pws)
		errcls(3, "gid's not read");
	return (pws->gr_name);
}

int		item_size(t_item *ele)
{
	return (ele->stat->st_size);
}

int		last_mod(t_item *ele)
{
	return (ele->stat->st_mtime);
}