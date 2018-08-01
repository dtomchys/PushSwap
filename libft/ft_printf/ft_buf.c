/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:40:21 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:40:59 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_display_buf(void)
{
	int i;

	i = -1;
	while (++i < g_i)
		write(1, &(g_buf[i]), 1);
}

void	ft_put_buf(unsigned int ch, int amount)
{
	amount += g_i;
	while (g_i < amount)
		g_buf[g_i++] = ch;
	g_buf[g_i + 1] = '\0';
}
