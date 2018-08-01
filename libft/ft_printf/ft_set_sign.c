/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:55:01 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:55:04 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_set_sign(char *s, t_info *arg, va_list *ap)
{
	t_flag sign;

	if (arg->formater[1].a[0] != '+')
	{
		sign.a[0] = *s;
		sign.size = 1;
		arg->formater[1] = sign;
		arg->light[1] = 1;
	}
	return (ft_recursion(s + arg->formater[1].size, arg, ap));
}
