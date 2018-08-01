/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:51:31 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:51:37 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_set_mod(char *s, t_info *arg, va_list *ap)
{
	if (*s == 'z' && arg->modi < M_Z)
		arg->modi = M_Z;
	if (*s == 'j' && arg->modi < M_J)
		arg->modi = M_J;
	if (*s == 'l' && *(s + 1) == 'l' && arg->modi < M_LL)
	{
		arg->modi = M_LL;
		s++;
	}
	else if (*s == 'l' && arg->modi < M_L)
		arg->modi = M_L;
	if (*s == 'h' && *(s + 1) == 'h' && arg->modi < M_HH)
	{
		arg->modi = M_HH;
		s++;
	}
	else if (*s == 'h' && arg->modi < M_H)
		arg->modi = M_H;
	s++;
	return (ft_recursion(s, arg, ap));
}
