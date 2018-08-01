/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:04:47 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/02 22:07:36 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
		{
			if (needle[i + 1] == '\0')
				return ((char*)haystack);
			i++;
		}
		haystack++;
	}
	return (0);
}
