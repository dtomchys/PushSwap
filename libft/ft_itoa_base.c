/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:57:19 by dtomchys          #+#    #+#             */
/*   Updated: 2018/01/20 17:58:22 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(uintmax_t num, int base)
{
	int i;

	i = 0;
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(uintmax_t nbr, int base)
{
	static char based_sys[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
								'9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int			i;
	char		*res;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = ft_count(nbr, base);
	res = (char*)malloc(sizeof(char) * i + 1);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i] = based_sys[nbr % base];
		nbr /= base;
		i--;
	}
	return (res);
}
