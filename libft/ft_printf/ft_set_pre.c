/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:53:28 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:53:39 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_set_pre(char *s, t_info *arg, va_list *ap)
{
	t_flag	pre;
	int		i;
	int		j;

	i = 0;
	if (arg->light[3] && arg->zero)
		arg->formater[3].a[0] = ' ';
	pre.a[0] = '0';
	pre.size = ft_atoi(s);
	j = pre.size;
	while (j != 0)
	{
		i++;
		j /= 10;
	}
	if (*s == '0')
		i++;
	if (arg->light[2] && pre.size)
		pre.size--;
	arg->formater[0] = pre;
	arg->light[0] = 1;
	return (ft_recursion(s + i, arg, ap));
}
