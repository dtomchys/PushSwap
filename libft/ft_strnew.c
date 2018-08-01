/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:19:36 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:19:19 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(size + 1)))
		return (NULL);
	while (i <= size)
		new[i++] = '\0';
	return (new);
}
