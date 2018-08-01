/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:05:22 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:07:03 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	s = (char*)src;
	d = (char*)dst;
	i = 0;
	if (s < d)
	{
		while (len--)
			d[len] = s[len];
	}
	else
	{
		if (len == 0 || d == s)
			return (d);
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
