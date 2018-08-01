/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:00:37 by dtomchys          #+#    #+#             */
/*   Updated: 2018/01/20 17:02:35 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_wchar(wchar_t wc, int *i, char *res)
{
	int j;

	j = ft_wchar_len(wc);
	if (j == 1)
		res[(*i)++] = wc;
	else if (j == 2)
	{
		res[(*i)++] = (wc >> 6) + 192;
		res[(*i)++] = (wc & 63) + 128;
	}
	else if (j == 3)
	{
		res[(*i)++] = (wc >> 12) + 224;
		res[(*i)++] = ((wc >> 6) & 63) + 128;
		res[(*i)++] = (wc & 63) + 128;
	}
	else
	{
		res[(*i)++] = (wc >> 18) + 240;
		res[(*i)++] = ((wc >> 12) & 63) + 128;
		res[(*i)++] = ((wc >> 6) & 63) + 128;
		res[(*i)++] = (wc & 63) + 128;
	}
}

char		*ft_dec_wstr(wchar_t *ws)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	if (!ws)
		return (NULL);
	len = ft_wstr_bytelen(ws);
	res = (char*)malloc(sizeof(char) * len);
	res[len] = '\0';
	len = 0;
	while (ws[len])
		ft_put_wchar(ws[len++], &i, res);
	return (res);
}
