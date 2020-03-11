/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:17:25 by qmattor           #+#    #+#             */
/*   Updated: 2020/03/10 21:12:59 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	handles the -R if required
**	creates next path and adds to the str then calls read_from_dir on it
*/

void	dir_stuff(t_item **dirstack, char *path, char *args)
{
	char	*str1;

	while (*dirstack != NULL)
	{
		if ((*dirstack)->name[0] == '.')
		{
			if (args[A])
			{
				str1 = create_path(path, (*dirstack)->name);
				write(1, "\n", 1);
				read_from_dir(str1, args);
				free(str1);
			}
			pop(dirstack);
		}
		else
		{
			str1 = create_path(path, (*dirstack)->name);
			write(1, "\n", 1);
			read_from_dir(str1, args);
			pop(dirstack);
			free(str1);
		}
	}
}

/*
**	just handles the different options for sorting
*/

t_item	*sorts(char *a, t_item **stack)
{
	if (a[T])
	{
		if (a[REV])
			*stack = !a[S] ? sort(*stack, &rev_time) : sort1(*stack, &rev_time);
		else
			*stack = !a[S] ? sort(*stack, &by_time) : sort1(*stack, &by_time);
	}
	else
	{
		if (a[REV])
			*stack = !a[S] ? sort(*stack, &rev_name) : sort1(*stack, &rev_name);
		else
			*stack = !a[S] ? sort(*stack, &by_name) : sort1(*stack, &by_name);
	}
	return (*stack);
}

/*
**	handles different options for printing
*/

void	prints(int bytes, char *args, t_item **stack, char *path)
{
	if (ft_strcmp(path, "."))
		args[REC] ? printpath(path) : 0;
	if (args[L] && args[A])
		printlst(bytes, *stack, ALLONG, path);
	else if (args[L])
		printlst(bytes, *stack, LONG, path);
	else if (args[A])
	{
		if (args[F])
			printlst(bytes, *stack, ALL, path);
		else
			listformat(*stack, LONG);
	}
	else
	{
		if (args[F])
			printlst(bytes, *stack, NORMAL, path);
		else
			listformat(*stack, NORMAL);
	}
}

/*
**	sudo main
**	opens diretory and reads items in it
**	tehn calls sort and print on the stack
*/

int		read_from_dir(char *path, char *args)
{
	DIR				*dir;
	struct dirent	*sd;
	t_item			**stack;
	t_item			**dirstack;
	char			*str1;

	stack = (t_item **)ft_strnew(sizeof(t_item *));
	dirstack = (t_item **)ft_strnew(sizeof(t_item *));
	if ((dir = opendir(path)) == NULL)
		return (0);
	while ((sd = readdir(dir)) != NULL)
	{
		str1 = create_path(path, sd->d_name);
		*stack = push(*stack, createlem(sd, str1));
		if (is_directory(*stack) && ft_strcmp((*stack)->name, ".")
		&& ft_strcmp((*stack)->name, "..") && (*stack)->stat != NULL)
			*dirstack = push(*dirstack, createlem(sd, str1));
		if ((*stack)->stat == NULL)
			write(1, "./ft_ls: Permison Denied ", 25);
		free(str1);
	}
	*stack = sorts(args, stack);
	*dirstack = sorts(args, dirstack);
	prints(totalstack(*stack, args[2] ? 1 : 0), args, stack, path);
	delst(*stack);
	free(stack);
	args[1] ? dir_stuff(dirstack, path, args) : 0;
	delst(*dirstack);
	free(dirstack);
	closedir(dir);
	return (1);
}

/*
**	main, what more do I need to say
*/

int		main(int argc, char **argv)
{
	int		x;
	int		y;
	char	*args;
	char	*otherstuff;

	y = 0;
	x = 0;
	args = ft_strnew(NUM_ARGS);
	while (argc > ++x)
	{
		if (argv[x][0] != '-' || !ft_strcmp(argv[x], "--"))
			break ;
		argv[x][0] == '-' ? otherstuff = argsparse(argv[x]) : 0;
		argv[x][0] == '-' ? args = combineargs(args, otherstuff) : 0;
		argv[x][0] == '-' ? free(otherstuff) : 0;
	}
	while (argc > x)
	{
		!ft_strcmp(argv[x], "/") ? 0 : fixpath(argv[x], args);
		y = read_item(argv[x], args);
		args[SLASH] = 0;
		x++;
	}
	y == 0 ? read_from_dir(".", args) : 0;
	free(args);
	// system("leaks ft_ls");
}
