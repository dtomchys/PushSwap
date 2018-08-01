/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:38:16 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/03 18:06:50 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *str;
	unsigned char *str1;

	str = (unsigned char*)s1;
	str1 = (unsigned char*)s2;
	while (*str || *str1)
	{
		if (*str != *str1)
			return (*str - *str1);
		str++;
		str1++;
	}
	return (0);
}
