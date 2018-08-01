/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:58:27 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:02:42 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int num)
{
	size_t		i;
	int			is_neg;

	i = 0;
	is_neg = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		is_neg = 1;
		num *= -1;
	}
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (is_neg ? i + 1 : i);
}

static void		ft_create_num(char *s, size_t len, long long num)
{
	size_t		i;

	i = 0;
	if (num == 0)
	{
		s[0] = '0';
		return ;
	}
	if (num < 0)
		num *= -1;
	while (len--)
	{
		s[len] = num % 10 + '0';
		num = num / 10;
	}
}

char			*ft_itoa(int n)
{
	long long	num;
	char		*str;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(ft_count(n))))
		return (NULL);
	ft_create_num(str, ft_count(n), num);
	if (n < 0)
		str[0] = '-';
	return (str);
}
