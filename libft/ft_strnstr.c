/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:41:02 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/03 18:00:16 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t needle_len;
	size_t i;

	if (*needle == '\0')
		return ((char*)haystack);
	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	while (*haystack && n >= needle_len)
	{
		i = 0;
		while (needle[i] == haystack[i])
		{
			if (i == needle_len - 1)
				return ((char*)haystack);
			i++;
		}
		haystack++;
		n--;
	}
	return (NULL);
}
