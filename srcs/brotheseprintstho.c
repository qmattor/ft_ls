/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brotheseprintstho.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:09:07 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/04 20:51:42 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	printgroup(t_item *ele, char size)
{
	size -= ft_strlen(ele->gid);
	write(1, ele->gid, ft_strlen(ele->gid));
	while (size-- >= 0)
		write(1, " ", 1);
}

void	printuser(t_item *ele, char size)
{
	size -= ft_strlen(ele->uid);
	write(1, ele->uid, ft_strlen(ele->uid));
	while (size-- >= 0)
		write(1, " ", 1);
}