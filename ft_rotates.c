/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:07:12 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:07:16 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"
#define RW(X) (ft_printf("r%c\n", X))

void	ft_rotates(t_lst **head, char c)
{
	t_lst *temp;
	t_lst *new_h;
	t_lst *old_h;

	if (!head || !*head || !(*head)->next)
		return ;
	temp = *head;
	old_h = *head;
	new_h = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = old_h;
	old_h->next = NULL;
	*head = new_h;
	if (c == 'a' || c == 'b')
		RW(c);
}

void	ft_rrotates(t_lst **a, t_lst **b, char c)
{
	ft_rotates(a, 'c');
	ft_rotates(b, 'c');
	c == 'a' || c == 'b' ? RW('r') : 0;
}
