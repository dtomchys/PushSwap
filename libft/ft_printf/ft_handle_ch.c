/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:52:04 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:52:08 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		ft_dispatch(t_info *arg)
{
	int length;
	int i;

	i = -1;
	if (arg->buf)
	{
		length = ft_strlen(arg->buf);
		if (arg->light[0] && arg->formater[0].size < length)
			length = arg->formater[0].size;
		if (arg->light[3] && !arg->minus)
			ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length);
		while (++i < length)
			ft_put_buf(arg->buf[i], 1);
		if (arg->light[3] && arg->minus)
			ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length);
	}
	else if (!arg->light[3])
	{
		arg->buf = ft_strdup("(null)");
		while (++i < 6)
			ft_put_buf(arg->buf[i], 1);
	}
	else
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size);
}

static char		*ft_get_str(char *s, va_list *ap, t_info *arg)
{
	wchar_t	*temp_w;
	char	*temp;
	wchar_t	tw[2];
	char	tc[2];

	if (*s == 'S' || (*s == 's' && arg->modi == M_L))
	{
		temp_w = va_arg(*ap, wchar_t*);
		temp = ft_dec_wstr(temp_w);
	}
	else if (*s == 's')
		temp = ft_strdup(va_arg(*ap, char*));
	else if (*s == 'C' || (*s == 'c' && arg->modi == M_L))
	{
		tw[0] = va_arg(*ap, wchar_t);
		tw[1] = '\0';
		temp = ft_dec_wstr(tw);
	}
	else
	{
		tc[0] = va_arg(*ap, int);
		tc[1] = '\0';
		temp = ft_strdup(tc);
	}
	return (temp);
}

char			*ft_handle_ch(char *s, t_info *arg, va_list *ap)
{
	arg->buf = ft_get_str(s, ap, arg);
	if (arg->zero && arg->light[3] && !arg->minus)
		arg->formater[3].a[0] = '0';
	if ((*s == 'c' || *s == 'C') && arg->buf[0] == '\0')
	{
		if (arg->light[3] && !arg->minus)
			ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - 1);
		ft_put_buf('\0', 1);
		if (arg->light[3] && arg->minus)
			ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - 1);
	}
	else
		ft_dispatch(arg);
	free(arg->buf);
	return (s + 1);
}
