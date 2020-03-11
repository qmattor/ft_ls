/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 07:27:21 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/21 02:57:55 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_item	*splitlst(t_item *start)
{
	int		size;
	t_item	*half;

	half = start;
	size = lstlen(start);
	if (size == 2)
	{
		half = half->next;
		start->next = NULL;
		return (half);
	}
	size /= 2;
	while(--size)
		half = half->next;
	start = half;
	half = half->next;
	start->next = NULL;
	return (half);
}

int		lstlen(t_item *stack)
{
	int		x;

	x = 0;
	if (!stack)
		return (x);
	while(stack != NULL)
	{
		stack = stack->next;
		x++;
	}
	return (x);
}

t_item	*merge(t_item *lst1, t_item *lst2, int(*compare)(t_item *, t_item *))
{
	t_item	*temp;

	if (!lst1)
		return (lst2);
	if (!lst2)
		return (lst1);
	if (compare(lst1, lst2) > 0)
	{
		temp = lst2;
		temp->next = merge(lst1, lst2->next, compare);
		return (temp);
	}
	else
	{
		temp = lst1;
		temp->next = merge(lst1->next, lst2, compare);
		return (temp);
	}
}
t_item	*sort(t_item *stack, int(*compare)(t_item *, t_item *))
{
	t_item	*lst1;
	t_item	*lst2;

	if (stack == NULL)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	lst1 = stack;
	lst2 = splitlst(lst1);
	lst1 = sort(lst1, compare);
	lst2 = sort(lst2, compare);
	lst1 = merge(lst1, lst2, compare);
	return (lst1);
}