/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:08:55 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:14:08 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (s[i])
		i++;
	temp = (char*)malloc(i + 1);
	if (temp != NULL)
	{
		i = 0;
		while (s[i])
		{
			temp[i] = s[i];
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	else
		return (NULL);
}
