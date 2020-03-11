/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 00:11:21 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/09 16:27:18 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	uses strchr to check if the str has the argument
*/

char	*argsparse(char *str)
{
	char		*ret;

	ret = ft_strnew(NUM_ARGS);
	while (*(++str))
	{
		if (ft_strchr(ARGUMENTS, *str) == NULL)
			usage(*str);
		ret[ft_strlen(ARGUMENTS) - ft_strlen(ft_strchr(ARGUMENTS, *str))] = 1;
	}
	return (ret);
}

/*
**	if a slash is found at the end of an input it gets regestered as an argument
*/

void	fixpath(char *path, char *args)
{
	int		i;

	i = ft_strlen(path);
	while (path[--i] == '/')
		args[SLASH] = (path[i] = 0) + 1;
}

/*
**	adds the argument lists together to get a resultant list of arguments
**	NOTE: USES ARGS1 DATA SPACE
*/

char	*combineargs(char *args1, char *args2)
{
	int		x;

	x = 0;
	while (x < NUM_ARGS)
	{
		args1[x] += args2[x];
		x++;
	}
	return (args1);
}

/*
**	usage case
*/

void	printargs(void)
{
	write(1, "usage: -", 16);
	write(1, ARGUMENTS, ft_strlen(ARGUMENTS));
}
