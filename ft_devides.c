/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_devides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:42:03 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/25 19:42:06 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		ft_sorted_stack(t_lst *a)
{
	while (a)
	{
		if ((a->next && a->num < a->next->num) || !a->next)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int		ft_lstlen(t_lst *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		ft_dev_a(t_lst **a, t_lst **b, int mid, int temp)
{
	int rr;

	rr = 0;
	while (ft_find_num(*a, mid) && (*a)->bl != -1)
	{
		if ((*a)->num >= mid && ++rr)
			ft_rotates(a, (*a)->c);
		else
		{
			ft_pushes(a, b, (*a)->c);
			temp--;
		}
	}
	if (!(*a)->bl && temp > 3)
		ft_marker(a, 0);
	else
	{
		if (ft_lstlen(*a) > 3)
			while (rr--)
				ft_revr(a, (*a)->c);
		ft_marker(a, temp);
	}
	return (temp);
}

int		ft_dev_b(t_lst **a, t_lst **b, int mid, int temp)
{
	int rr;

	rr = 0;
	while (ft_find_num(*a, mid) && (*a)->bl != -1)
	{
		if ((*a)->num <= mid && ++rr)
			ft_rotates(a, (*a)->c);
		else
		{
			ft_pushes(a, b, (*a)->c);
			temp--;
		}
	}
	if (ft_find_bl(*a, (*a)->bl) != 0)
		while (rr--)
			ft_revr(a, (*a)->c);
	ft_marker(a, temp);
	return (temp);
}
