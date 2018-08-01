/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 14:05:21 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/25 14:05:24 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void		ft_init_mask_a(t_lst *a, int *i)
{
	int m;
	int j;

	j = 0;
	if (a->bl == 3)
	{
		m = ft_order_three(a);
		if (m == 1 || m == 2 || m == 4)
			i[j++] = 1;
		if (m == 1 || m == 4 || m == 3 || m == 5)
			i[j++] = 2;
		if (m == 1 || m == 4 || m == 3 || m == 5)
			i[j++] = 1;
		if (m == 1 || m == 4 || m == 3 || m == 5)
			i[j++] = 3;
		if (m == 3 || m == 4)
			i[j++] = 1;
	}
	if ((a->bl == 2 || ft_lstlen(a) == 2) && a->num > a->next->num)
		i[j] = 1;
}

static void		ft_init_mask_b(t_lst *a, int *i)
{
	int m;
	int j;

	j = 0;
	if (a->bl == 3)
	{
		m = ft_order_three(a);
		if (m == 3 || m == 5 || m == 6)
			i[j++] = 1;
		if (m == 5 || m == 6 || m == 1 || m == 2)
			i[j++] = 2;
		if (m == 1 || m == 2 || m == 5 || m == 6)
			i[j++] = 1;
		if (m == 1 || m == 2 || m == 5 || m == 6)
			i[j++] = 3;
		if (m == 2 || m == 6)
			i[j++] = 1;
	}
	if (a->bl == 2 && a->num < a->next->num)
		i[j] = 1;
}

static void		ft_construct(t_lst **a, t_lst **b, int *i, int *j)
{
	ft_bzero(i, 24);
	ft_bzero(j, 24);
	ft_init_mask_a(*a, i);
	ft_init_mask_b(*b, j);
}

static void		ft_end_sort(t_lst **b, int *j, int i)
{
	while (i < 5)
	{
		if (j[i] == 1 && ++i)
			ft_swap(b, (*b)->c);
		else if (j[i] == 2 && ++i)
			ft_rotates(b, (*b)->c);
		else if (j[i] == 3 && ++i)
			ft_revr(b, (*b)->c);
		else
			i++;
	}
}

void			ft_sort_tree(t_lst **a, t_lst **b)
{
	int		i[6];
	int		j[6];

	ft_construct(a, b, &(i[0]), &(j[0]));
	while (i[5] < 5 && j[5] < 5)
	{
		if ((i[i[5]] == 1 && j[j[5]] == 1) && ++i[5] && ++j[5])
			ft_sswap(a, b, 'a');
		else if ((i[i[5]] == 2 && j[j[5]] == 2) && ++i[5] && ++j[5])
			ft_rrotates(a, b, 'a');
		else if ((i[i[5]] == 3 && j[j[5]] == 3) && ++i[5] && ++j[5])
			ft_rrevr(a, b, 'a');
		else if (i[i[5]] == 1 && ++i[5])
			ft_swap(a, (*a)->c);
		else if (i[i[5]] == 2 && ++i[5])
			ft_rotates(a, (*a)->c);
		else if (i[i[5]] == 3 && ++i[5])
			ft_revr(a, (*a)->c);
		else
			i[5]++;
	}
	ft_end_sort(b, &(j[0]), j[5]);
	(*a)->bl = -1;
}
