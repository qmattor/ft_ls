/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:54:02 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/09 18:33:45 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returns the strlen of the group
*/

int		grouplen(t_item *lst)
{
	return (ft_strlen(lst->gid));
}

/*
**	returns the strlen of the user
*/

int		userlen(t_item *lst)
{
	return (ft_strlen(lst->uid));
}

/*
**	returns the number of digits of the link num
*/

int		linklens(t_item *lst)
{
	char	*str;
	int		x;

	str = ft_itoa(num_links(lst));
	x = ft_strlen(str);
	free(str);
	return (x);
}

/*
**	returns the number of digits for the item size
*/

int		sizelen(t_item *lst)
{
	char	*str;
	int		x;

	str = ft_itoa(item_size(lst));
	x = ft_strlen(str);
	free(str);
	return (x);
}

/*
**	this is some retarded ass shit - fix it
**	whatchu doin bro
*/

int		fspace(t_item *lst, int (*f)(t_item *))
{
	int		largest;

	largest = 0;
	while (lst)
	{
		if (f(lst) > largest)
			largest = f(lst);
		lst = lst->next;
	}
	return (largest);
}
