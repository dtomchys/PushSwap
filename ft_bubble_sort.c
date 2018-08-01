/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:55:04 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/24 18:55:09 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		ft_show_stack(t_lst *a)
{
	while (a)
	{
		ft_printf("%d\n", a->num);
		a = a->next;
	}
}

static int	ft_find_min(t_lst *a)
{
	int i;

	i = a->num;
	while (a)
	{
		if (i > a->num)
			i = a->num;
		a = a->next;
	}
	return (i);
}

static void	ft_find_rot(t_lst **a, int min)
{
	int		i;
	int		pos;
	t_lst	*temp;

	temp = *a;
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->num == min)
			pos = i;
		i++;
		temp = temp->next;
	}
	i = i / 2 > pos ? -1 : 1;
	while ((*a)->num != min)
	{
		if (i == -1)
			ft_rotates(a, (*a)->c);
		else
			ft_revr(a, (*a)->c);
	}
}

void		ft_bubble_sort(t_lst **a, t_lst **b)
{
	int		min;

	while (*a)
	{
		min = ft_find_min(*a);
		if ((*a)->next && (*a)->next->num == min)
			ft_swap(a, (*a)->c);
		else
			ft_find_rot(a, min);
		if ((*a)->num == min)
			ft_pushes(a, b, (*a)->c);
	}
	while (*b)
		ft_pushes(b, a, (*b)->c);
}
