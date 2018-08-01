/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:07:31 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/10 21:02:57 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *nextlst;

	current = *alst;
	while (current)
	{
		nextlst = current->next;
		del(current->content, current->content_size);
		free(current);
		current = nextlst;
	}
	*alst = NULL;
}
