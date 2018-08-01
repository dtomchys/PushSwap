/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 18:27:29 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 18:27:37 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static	void	ft_secondary_sort(t_lst **a, t_lst **b)
{
	int ord;

	ord = (*b)->bl;
	if ((*b)->c == 'a' && (*b)->bl <= 3 && (*b)->bl != -1)
		if (ft_find_bl(*b, ord) == -1)
			ft_main_sort(b, a);
	if (!(*a) || !(*b))
		return ;
	if ((*b)->bl <= 3 && (*b)->bl != -1)
	{
		while (ord--)
		{
			ft_pushes(b, a, (*b)->c);
			if (*b)
				(*b)->bl = !ord ? (*b)->bl : (*a)->bl;
		}
		if ((*a)->bl <= 3 && (*b))
			ft_main_sort(a, b);
	}
}

void			ft_main_sort(t_lst **a, t_lst **b)
{
	if ((*a)->c == 'a')
		ft_sort_tree(a, b);
	if (!ft_sorted(*a) && !(*b))
		return ;
	ft_secondary_sort(a, b);
	if (!(*b) || !(*a))
		return ;
	ft_sort(b, a);
}

void			ft_sort(t_lst **a, t_lst **b)
{
	int mid;
	int count;
	int temp;

	count = 0;
	mid = ft_count_mid(a, &count);
	temp = count;
	if ((count <= 3) && !(*b) && ft_brut_sort(a, count))
		return ;
	if ((*a)->c == 'a' && (*a)->bl != -1)
		temp = ft_dev_a(a, b, mid, temp);
	if ((*a)->c == 'b')
		temp = ft_dev_b(a, b, mid, temp);
	ft_marker(b, count - temp);
	if ((*a)->c == 'a' && ft_find_bl(*a, (*a)->bl) > 0 &&\
		(*a)->bl <= 3 && (*a)->bl != -1)
		while (*a && (*a)->bl == temp)
			ft_pushes(a, b, (*a)->c);
	if ((*b) && (*b)->c == 'a' && (*b)->bl > 3)
		ft_sort(b, a);
	else if ((*a)->c == 'a' && ((*a)->bl > 3 || !(*a)->bl))
		ft_sort(a, b);
	else
		ft_main_sort(a, b);
}
