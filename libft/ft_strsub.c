/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:18:40 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 20:37:02 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = ft_strncpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}
