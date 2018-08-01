/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:00:53 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:00:56 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#define SW(X) (ft_printf("s%c\n", X))

void	ft_swap(t_lst **head, char c)
{
	t_lst *temp;
	t_lst *new_h;

	if (!head || !((*head)->next))
		return ;
	temp = *head;
	new_h = temp->next;
	*head = new_h;
	temp->next = new_h->next;
	new_h->next = temp;
	if (c == 'a' || c == 'b')
		SW(c);
}

void	ft_sswap(t_lst **a, t_lst **b, char c)
{
	ft_swap(a, 'c');
	ft_swap(b, 'c');
	c == 'a' || c == 'b' ? SW('s') : 0;
}
