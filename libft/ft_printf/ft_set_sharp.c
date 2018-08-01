/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sharp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:53:52 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:53:55 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_set_sharp(char *s, t_info *arg, va_list *ap)
{
	t_flag	sharp;

	sharp.a[0] = '0';
	sharp.size = 1;
	arg->formater[2] = sharp;
	arg->light[2] = 1;
	return (ft_recursion(s + 1, arg, ap));
}
