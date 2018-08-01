/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:11:10 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:19:56 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char*)s1;
	str1 = (unsigned char*)s2;
	while (i < n)
	{
		if (*str != *str1)
			return (*str - *str1);
		if (*str == '\0' && *str1 == '\0')
			return (0);
		str++;
		str1++;
		i++;
	}
	return (0);
}
