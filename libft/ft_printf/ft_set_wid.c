/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_wid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:01:52 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 20:02:08 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_set_wid(char *s, t_info *arg, va_list *ap)
{
	t_flag	wid;
	int		i;
	int		j;

	i = 0;
	if (arg->zero && !arg->minus)
		wid.a[0] = '0';
	else
		wid.a[0] = ' ';
	wid.size = ft_atoi(s);
	j = wid.size;
	while (j != 0)
	{
		i++;
		j /= 10;
	}
	arg->formater[3] = wid;
	arg->light[3] = 1;
	return (ft_recursion(s + i, arg, ap));
}
