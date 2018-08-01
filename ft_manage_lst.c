/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:03:11 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/19 14:03:14 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

t_lst	*ft_lnew(int num)
{
	t_lst	*temp;

	if (!(temp = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	temp->num = num;
	temp->bl = 0;
	temp->next = NULL;
	return (temp);
}

void	ft_ladd(t_lst **head, t_lst *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}

void	ft_ldel(t_lst **head)
{
	t_lst *temp;

	temp = (*head)->next;
	(*head)->num = 0;
	(*head)->bl = 0;
	(*head)->next = NULL;
	free(*head);
	*head = temp;
}
