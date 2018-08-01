/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:28:54 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/11 15:27:41 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t s)
{
	size_t i;
	size_t s1;
	size_t l;

	i = 0;
	l = 0;
	if (s == 0)
		return (0 + ft_strlen(src));
	while (dest[i] != '\0' && i < s)
		i++;
	while (src[l])
		l++;
	s1 = i;
	while (src[i - s1] != '\0' && i < s - 1)
	{
		dest[i] = src[i - s1];
		i++;
	}
	if (s1 < s)
		dest[i] = '\0';
	return (s1 + l);
}
