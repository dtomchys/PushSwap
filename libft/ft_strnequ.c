/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:07:17 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/08 18:20:18 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *str;
	char *str1;

	str = (char*)s1;
	str1 = (char*)s2;
	if (!str || !str1)
		return (0);
	if (ft_strncmp(str, str1, n))
		return (0);
	return (1);
}
