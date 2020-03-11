/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:54:13 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/08 23:26:49 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	basic stack funcs, pretty self explanitory
*/

t_item	*createlem(struct dirent *ditem, char *path)
{
	t_item		*ele;
	struct stat	*sta;

	if (ditem == NULL)
		return (NULL);
	ele = malloc(sizeof(t_item));
	sta = malloc(sizeof(t_stat));
	ele->name = malloc(256);
	if (lstat(path, sta) != 0)
	{
		free(sta);
		pdenied(path);
		ele->stat = NULL;
	}
	else
	{
		ele->stat = sta;
		ele->gid = ft_strdup(get_group(ele));
		ele->uid = ft_strdup(get_user(ele));
	}
	ft_strcpy(ele->name, ditem->d_name);
	ele->d_ino = ditem->d_ino;
	ele->next = NULL;
	return (ele);
}

t_item	*push(t_item *stack, t_item *ele)
{
	ele->next = stack;
	return (ele);
}

int		pop(t_item **stack)
{
	t_item	*temp;

	temp = *stack;
	if ((*stack) != NULL)
	{
		free((*stack)->stat);
		free((*stack)->name);
		free((*stack)->gid);
		free((*stack)->uid);
		*stack = (*stack)->next;
	}
	else
		return (0);
	free(temp);
	return (1);
}

t_item	*delst(t_item *lst)
{
	t_item	*temp;

	temp = lst;
	while (lst)
	{
		lst = lst->next;
		free(temp->stat);
		free(temp->name);
		free(temp->gid);
		free(temp->uid);
		free(temp);
		temp = lst;
	}
	return (NULL);
}
