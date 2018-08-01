/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:55:36 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:55:40 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_make_low(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		s[i] = ft_tolower(s[i]);
	return (s);
}

static char	*ft_get_num_base(char s, t_info *arg, va_list *ap)
{
	uintmax_t res;

	if (arg->modi == M_H)
		res = (uintmax_t)((unsigned short)va_arg(*ap, unsigned int));
	else if (arg->modi == M_HH && s != 'O')
		res = (uintmax_t)((unsigned char)va_arg(*ap, unsigned int));
	else if (arg->modi == M_LL)
		res = (uintmax_t)(va_arg(*ap, unsigned long long));
	else if (arg->modi == M_L || s == 'O')
		res = (uintmax_t)(va_arg(*ap, unsigned long));
	else if (arg->modi == M_Z)
		res = (uintmax_t)(va_arg(*ap, size_t));
	else if (arg->modi == M_J)
		res = va_arg(*ap, uintmax_t);
	else if (s == 'p')
		res = (uintmax_t)(va_arg(*ap, unsigned int*));
	else
		res = (uintmax_t)(va_arg(*ap, unsigned int));
	arg->err = res == 0 ? 1 : 0;
	if (s == 'x' || s == 'p')
		return (ft_make_low(ft_itoa_base(res, 16)));
	else if (s == 'X')
		return (ft_itoa_base(res, 16));
	else
		return (ft_itoa_base(res, 8));
}

static void	ft_dispatch_num_base(t_info *arg)
{
	int length[2];
	int i;

	i = -1;
	length[0] = ft_strlen(arg->buf);
	length[1] = arg->light[0] && arg->formater[0].size > length[0] ?\
	arg->formater[0].size : length[0];
	if (arg->light[2] && !arg->err)
		length[1] += arg->formater[2].size;
	if (arg->light[3] && !arg->minus && (!arg->zero || arg->light[0]))
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
	if (arg->light[2] && (!arg->err || !arg->formater[2].a[1]))
	{
		ft_put_buf(arg->formater[2].a[0], 1);
		if (arg->formater[2].a[1] == 'x' || arg->formater[2].a[1] == 'X')
			ft_put_buf(arg->formater[2].a[1], 1);
	}
	if (arg->zero && !arg->light[0] && !arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
	else if (arg->light[0] && arg->formater[0].size > length[0])
		ft_put_buf(arg->formater[0].a[0], arg->formater[0].size - length[0]);
	while (++i < length[0])
		ft_put_buf(arg->buf[i], 1);
	if (arg->light[3] && arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
}

char		*ft_handle_num_base(char *s, t_info *arg, va_list *ap)
{
	if ((*s == 'x' || *s == 'X') && arg->light[2])
	{
		arg->formater[2].a[arg->formater[2].size++] = *s == 'x' ? 'x' : 'X';
		if (arg->light[0] && arg->formater[0].size)
			arg->formater[0].size++;
	}
	if (*s == 'p')
	{
		arg->formater[2].size = 2;
		arg->formater[2].a[0] = '0';
		arg->formater[2].a[1] = 'x';
		arg->light[2] = 1;
	}
	arg->buf = ft_get_num_base(*s, arg, ap);
	if (arg->err && arg->light[0] && (!arg->formater[0].size || *s == 'p'))
	{
		arg->buf[0] = '\0';
		if (*s == 'O' || *s == 'o')
			arg->err = 0;
	}
	arg->err = *s == 'p' ? 0 : arg->err;
	ft_dispatch_num_base(arg);
	free(arg->buf);
	return (s + 1);
}
