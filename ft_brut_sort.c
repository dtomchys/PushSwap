/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brut_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 13:23:40 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/25 13:23:44 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void			ft_free(t_lst **a, t_lst **b)
{
	while (*a)
		ft_ldel(a);
	while (*b)
		ft_ldel(b);
}

int				ft_order_three(t_lst *a)
{
	if (a->next->next->num > a->next->num && a->next->next->num < a->num)
		return (1);
	if (a->num > a->next->num && a->next->next->num > a->num)
		return (2);
	if (a->num < a->next->num && a->next->next->num < a->num)
		return (3);
	if (a->num > a->next->num && a->next->num > a->next->next->num)
		return (4);
	if (a->next->next->num > a->num && a->next->next->num < a->next->num)
		return (5);
	if (a->num < a->next->num && a->next->num < a->next->next->num)
		return (6);
	return (0);
}

int				ft_brut_sort(t_lst **a, int i)
{
	if (i == 2)
	{
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, (*a)->c);
	}
	else if (i == 3)
	{
		if (((*a)->num > (*a)->next->next->num && (*a)->next->num < (*a)->num))
			ft_rotates(a, (*a)->c);
		if ((*a)->next->num > (*a)->next->next->num &&\
			(*a)->next->num > (*a)->num)
			ft_revr(a, (*a)->c);
		if ((*a)->num > (*a)->next->num)
			ft_swap(a, (*a)->c);
		if ((*a)->next->num > (*a)->next->next->num &&\
			(*a)->next->num > (*a)->num)
			ft_revr(a, (*a)->c);
	}
	return (1);
}
