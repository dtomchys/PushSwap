/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:50:05 by dtomchys          #+#    #+#             */
/*   Updated: 2017/10/29 19:11:56 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const	void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
