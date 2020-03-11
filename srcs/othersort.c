/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   othersort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:42:07 by qmattor           #+#    #+#             */
/*   Updated: 2020/02/27 18:21:13 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	this is a stack insertion sort
**
**	it will hold each element in a function call and insert them where they need to be
*/

/*
**	this is the insertion algorithm
*/

t_item	*place(t_item *lst, t_item *p, int(*compare)(t_item *, t_item *), char c)
{
	if (c == 0 && compare(p, lst) > 0)
	{
		p->next = lst;
		return (p);
	}
	c = 1;
	if (lst->next == NULL)
	{
		lst->next = p;
		p->next = NULL;
		return (lst);
	}
	if (compare(lst->next, p) > 0)
	{
		p->next = lst->next;
		lst->next = p;
		return (lst);
	}
	lst->next = place(lst->next, p, compare, c);
	return (lst);
}

/*
**	scrapes ach element into a function call until placed
*/

	t_item	*sort1(t_item *lst, int(*compare)(t_item *, t_item *))
{
	t_item	*temp;
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	temp = lst;
	lst = sort1(lst->next, compare);
	temp->next = NULL;
	lst = place(lst, temp, compare, 0);
	return (lst);
}
