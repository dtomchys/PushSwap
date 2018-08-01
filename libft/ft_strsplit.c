/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:26:36 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/09 16:46:39 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int i;
	int word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			word++;
		i++;
	}
	if (s[0] != c)
		word++;
	return (word);
}

static char		*ft_put_word(char const *s, char c, int *i)
{
	char	*word;
	int		d;

	d = 0;
	while (s[*i] == c)
		(*i)++;
	if (!(word = (char*)malloc(sizeof(char) * ft_strlen(s))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		word[d] = s[*i];
		d++;
		(*i)++;
	}
	word[d] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**arr;
	int		i;
	int		last_pos;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_count(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	if (s[0] == '\0')
	{
		arr[0] = NULL;
		return (arr);
	}
	last_pos = 0;
	while (i < count)
	{
		arr[i] = ft_put_word(s, c, &last_pos);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
