/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:49:50 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:49:58 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_reset_arg(t_info *arg)
{
	int i;

	i = -1;
	while (++i < 4)
		arg->light[i] = 0;
	arg->buf = NULL;
	i = -1;
	while (++i < 4)
	{
		arg->formater[i].a[0] = '\0';
		arg->formater[i].a[1] = '\0';
		arg->formater[i].size = 0;
	}
	arg->minus = 0;
	arg->zero = 0;
	arg->modi = EMPTY;
	arg->neg = '\0';
	arg->err = 0;
}
