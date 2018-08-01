/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_bytelen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:04:22 by dtomchys          #+#    #+#             */
/*   Updated: 2018/01/20 17:05:17 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstr_bytelen(wchar_t *wstr)
{
	int res;
	int len;

	res = 0;
	len = ft_wstrlen(wstr);
	while (len > 0)
	{
		res += ft_wchar_len(*wstr);
		wstr++;
		len--;
	}
	return (res);
}
