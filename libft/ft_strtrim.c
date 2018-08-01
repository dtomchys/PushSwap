/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:45:47 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:22:33 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_white_sp(char const *s, int f1)
{
	int f;

	f = f1;
	while (s[f])
		f++;
	f--;
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f--;
	if (f > f1)
		return (f - f1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*re;
	int		k;
	int		j;
	int		i;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k++;
	j = ft_white_sp(s, k);
	if (!(re = (char *)malloc(sizeof(char) * (j + 2))))
		return (0);
	while (i <= j)
	{
		re[i] = s[k];
		k++;
		i++;
	}
	re[i] = '\0';
	return (re);
}
