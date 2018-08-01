/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:02:08 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:02:12 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	ft_pushes(t_lst **src, t_lst **dst, char c)
{
	t_lst		*temp;
	static int	i;

	if (!src || !(*src))
		return ;
	temp = *src;
	if ((*dst == NULL || c == 'a') && i == 0)
	{
		*dst = ft_lnew((temp->num));
		(*dst)->c = 'b';
		ft_ldel(src);
		i++;
	}
	else
	{
		temp = ft_lnew((temp->num));
		ft_ladd(dst, temp);
		if (c == 'a')
			(*dst)->c = 'b';
		else
			(*dst)->c = 'a';
		(*dst)->bl = (*src)->bl;
		ft_ldel(src);
	}
	c == 'a' || c == 'b' ? ft_printf("p%c\n", (*dst)->c) : 0;
}
