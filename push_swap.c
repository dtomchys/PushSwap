/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:57:57 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 13:58:11 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void		ft_usage(void)
{
	write(2, "usage: [-d | -b | -n] num1 num2 ...\n", 36);
	write(2, "-d - sorting of descending order.\n", 34);
	write(2, "-b - forced sorting by bubble sort.\n", 36);
	write(2, "-n - show stack 'a' in numeric.\n", 32);
	exit(1);
}

static int		ft_check_flags(int *fl, char **argv, int argc)
{
	int i;

	i = 1;
	while (argc > i && (ft_strstr(argv[i], "-d") || ft_strstr(argv[i], "-b") ||\
		ft_strstr(argv[i], "-n")) && i <= 4)
	{
		if (argv[i][1] == 'd')
			fl[0] = 1;
		else if (argv[i][1] == 'b')
			fl[1] = 1;
		else
			fl[2] = 1;
		i++;
	}
	return (i);
}

static void		ft_dispatch(int *flags, int argc, char **argv, t_lst **a)
{
	int		i;
	char	**temp;
	int		j;

	j = -1;
	i = 0;
	flags[3] = ft_check_flags(flags, argv, argc);
	if (argc - flags[3] == 1)
	{
		temp = ft_strsplit(argv[flags[3]], ' ');
		while (temp[i])
			i++;
		*a = ft_validator(i, temp);
		while (++j < i)
			free(temp[j]);
		free(temp);
	}
	else if (flags[3] < argc)
	{
		if (!flags[0] && !flags[1] && !flags[2])
			*a = ft_validator(argc - flags[3], &(argv[1]));
		else
			*a = ft_validator(argc - flags[3], &(argv[flags[3]]));
	}
}

int				main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	int		flags[4];

	a = NULL;
	b = NULL;
	ft_bzero(&(flags[0]), 16);
	if (argc > 1)
	{
		ft_dispatch(flags, argc, argv, &a);
		if (a && !ft_sorted_stack(a) && flags[1])
			ft_bubble_sort(&a, &b);
		else if (a && !ft_sorted_stack(a))
			ft_sort(&a, &b);
		if (a && flags[0])
			ft_descending(&a, &b);
		if (a && flags[2])
			ft_show_stack(a);
	}
	else
		ft_usage();
	ft_free(&a, &b);
	return (0);
}
