/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:50:37 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/27 16:18:45 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returns the block size of a file depeding on mode (c)
*/

int		block(t_item *ele, char c)
{
	if (ele->name[0] == '.' && !c)
		return (0);
	return (ele->stat->st_blocks);
}

/*
**	returns the number of blocks in the item stack based on mode (c)
*/

int		totalstack(t_item *stack, char c)
{
	int	total;

	total = 0;
	while (stack)
	{
		total += block(stack, c);
		stack = stack->next;
	}
	return (total);
}

/*
**	gets the longest name in the item stack
**	seriously iteratively would have been a lot better :(
*/

int		longestname(t_item *lst)
{
	int		x;
	int		y;

	if (!lst)
		return (0);
	else
	{
		x = ft_strlen(lst->name);
		y = longestname(lst->next);
		if (x > y)
			return (x);
		return (y);
	}
}