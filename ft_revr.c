/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:46:37 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:46:43 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#define RRW(X) (ft_printf("rr%c\n", X))

void	ft_revr(t_lst **head, char c)
{
	t_lst *temp;
	t_lst *new_h;
	t_lst *old_h;

	if (!head || !*head || !(*head)->next)
		return ;
	old_h = *head;
	new_h = *head;
	while (new_h->next->next)
		new_h = new_h->next;
	temp = new_h->next;
	new_h->next = NULL;
	temp->next = old_h;
	*head = temp;
	if (c == 'a' || c == 'b')
		RRW(c);
}

void	ft_rrevr(t_lst **a, t_lst **b, char c)
{
	ft_revr(a, 'c');
	ft_revr(b, 'c');
	c == 'a' || c == 'b' ? RRW('r') : 0;
}
