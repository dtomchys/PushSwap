/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_toools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 16:33:19 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/23 16:33:21 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		ft_count_mid(t_lst **a, int *count)
{
	int		m;
	int		n;
	t_lst	*out;
	t_lst	*inside;
	int		flg;

	out = *a;
	flg = out->bl;
	while (out && (out->bl == flg || !out->bl))
	{
		m = 0;
		n = 0;
		inside = *a;
		while (inside && (inside->bl == flg || !inside->bl))
		{
			out->num < inside->num ? n++ : m++;
			inside = inside->next;
		}
		if (!*count)
			*count = m + n;
		if (n == m - 1 || n == m)
			return (out->num);
		out = out->next;
	}
	return (0);
}

int		ft_sorted(t_lst *a)
{
	int ord;

	ord = a->bl;
	while (a && ((a->c == 'a' && a->bl != -1) || (a->c == 'b' && --ord)))
	{
		if (a->c == 'a' && a->next && a->num > a->next->num)
			return (1);
		if (a->c == 'b' && a->next && a->num < a->next->num)
			return (1);
		a = a->next;
	}
	return (0);
}

int		ft_find_num(t_lst *a, int mid)
{
	int flg;

	flg = a->bl;
	while (a && (a->bl == flg || !a->bl))
	{
		if (a->c == 'a' && a->num < mid)
			return (1);
		if (a->c == 'b' && a->num > mid)
			return (1);
		a = a->next;
	}
	return (0);
}

int		ft_find_bl(t_lst *a, int ord)
{
	int i;

	i = 0;
	while (a && i++ < ord)
		a = a->next;
	if (a && a->bl == -1)
		return (-1);
	else if (a && a->bl > 0)
		return (a->bl);
	else
		return (0);
}

void	ft_marker(t_lst **b, int m)
{
	t_lst	*temp;
	int		flg;

	temp = *b;
	flg = m;
	while (temp && m--)
	{
		temp->bl = flg;
		temp = temp->next;
	}
}
