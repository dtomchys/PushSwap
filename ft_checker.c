/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:03:53 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:03:57 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static	int		ft_check(char *line, t_lst **a, t_lst **b)
{
	if (!(TRY(line, "ra")))
		ft_rotates(a, '\0');
	else if (!(TRY(line, "rb")))
		ft_rotates(b, '\0');
	else if (!(TRY(line, "sa")))
		ft_swap(a, '\0');
	else if (!(TRY(line, "sb")))
		ft_swap(b, '\0');
	else if (!(TRY(line, "ss")))
		ft_sswap(a, b, '\0');
	else if (!(TRY(line, "rr")))
		ft_rrotates(a, b, '\0');
	else if (!(TRY(line, "pa")))
		ft_pushes(b, a, '\0');
	else if (!(TRY(line, "pb")))
		ft_pushes(a, b, '\0');
	else if (!(TRY(line, "rra")))
		ft_revr(a, '\0');
	else if (!(TRY(line, "rrb")))
		ft_revr(b, '\0');
	else if (!(TRY(line, "rrr")))
		ft_rrevr(a, b, '\0');
	else
		return (0);
	return (1);
}

static	void	ft_reader(t_lst **a, t_lst **b)
{
	char			*line;

	line = NULL;
	while ((get_next_line(0, &line)) > 0)
	{
		if (!ft_check(line, a, b))
			ft_error();
		free(line);
	}
	if (ft_sorted_stack(*a) && !*b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	char	**temp;
	int		i;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			temp = ft_strsplit(argv[1], ' ');
			while (temp[i])
				i++;
			a = ft_validator(i, temp);
		}
		else
			a = ft_validator(argc - 1, &(argv[1]));
		ft_reader(&a, &b);
	}
	ft_free(&a, &b);
	return (0);
}
