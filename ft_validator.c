/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:00:02 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:00:06 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_size_validator(long num, char *s)
{
	int neg;

	neg = s[0] == '-' ? 1 : 0;
	if ((!neg && num < 0) || (neg && num > 0))
		ft_error();
	if (num < INT_MIN || num > INT_MAX)
		ft_error();
}

t_lst		*ft_set_stack(int num, long *arg)
{
	t_lst	*temp;

	temp = ft_lnew(arg[--num]);
	temp->c = 'a';
	while (--num >= 0 && temp)
	{
		ft_ladd(&temp, ft_lnew(arg[num]));
		temp->c = 'a';
		temp->bl = 0;
	}
	return (temp);
}

t_lst		*ft_validator(int num, char **a)
{
	int		i;
	int		j[2];
	long	dup[num];

	i = -1;
	while (++i < num)
	{
		j[1] = -1;
		j[0] = -1;
		while (a[i][++j[0]])
		{
			if (!j[0] && a[i][j[0]] == '-')
				continue ;
			if (!ft_isdigit(a[i][j[0]]))
				ft_error();
		}
		if (ft_strlen(a[i]) > 11 || !ft_strlen(a[i]))
			ft_error();
		dup[i] = ft_atoi(a[i]);
		while (++j[1] != i)
			if (dup[j[1]] == dup[i])
				ft_error();
		ft_size_validator(dup[i], a[i]);
	}
	return (ft_set_stack(num, dup));
}
