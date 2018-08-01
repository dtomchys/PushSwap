/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:02:28 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 20:02:37 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#define ABC(X) (X < 0 ? -X : X)

static char	*ft_get_num_u(char s, t_info *arg, va_list *ap)
{
	intmax_t	res;

	if (arg->modi == M_H && s == 'u')
		res = (uintmax_t)((unsigned short)va_arg(*ap, unsigned int));
	else if (arg->modi == M_HH && s == 'u')
		res = (uintmax_t)((unsigned char)va_arg(*ap, unsigned int));
	else if (arg->modi == M_LL)
		res = (uintmax_t)(va_arg(*ap, unsigned long long));
	else if (arg->modi == M_L && s == 'u')
		res = (uintmax_t)(va_arg(*ap, unsigned long));
	else if (arg->modi == M_Z)
		res = (uintmax_t)(va_arg(*ap, size_t));
	else if (arg->modi == M_J)
		res = va_arg(*ap, uintmax_t);
	else if (s == 'u')
		res = (uintmax_t)(va_arg(*ap, unsigned int));
	else
		res = (uintmax_t)(va_arg(*ap, unsigned long));
	arg->light[1] = 0;
	arg->err = res == 0 ? 1 : 0;
	return (ft_itoa_base(res, 10));
}

static char	*ft_get_num_d(char s, t_info *arg, va_list *ap)
{
	intmax_t	res;

	if (arg->modi == M_LL)
		res = (intmax_t)(va_arg(*ap, long long));
	else if (arg->modi == M_L || s == 'D')
		res = (intmax_t)(va_arg(*ap, long));
	else if (arg->modi == M_Z)
		res = (intmax_t)(va_arg(*ap, size_t));
	else if (arg->modi == M_J)
		res = va_arg(*ap, intmax_t);
	else if (arg->modi == M_H)
		res = (intmax_t)((short)va_arg(*ap, int));
	else if (arg->modi == M_HH)
		res = (intmax_t)((char)va_arg(*ap, int));
	else
		res = (intmax_t)(va_arg(*ap, int));
	if (res < 0)
		arg->neg = '-';
	arg->err = res == 0 ? 1 : 0;
	return (ft_itoa_base(ABC(res), 10));
}

static void	ft_dispatch_num(t_info *arg)
{
	int length[2];
	int i;

	i = -1;
	length[0] = ft_strlen(arg->buf);
	length[1] = arg->light[0] && arg->formater[0].size > length[0] ?\
	arg->formater[0].size : length[0];
	if (arg->light[1] || arg->neg != '\0')
		length[1]++;
	if (arg->light[3] && !arg->minus && (!arg->zero || arg->light[0]))
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
	if (arg->neg == '-')
		ft_put_buf(arg->neg, 1);
	else if (arg->light[1])
		ft_put_buf(arg->formater[1].a[0], arg->formater[1].size);
	if (arg->zero && !arg->light[0] && !arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
	if (arg->light[0] && arg->formater[0].size > length[0])
		ft_put_buf(arg->formater[0].a[0], arg->formater[0].size - length[0]);
	while (++i < length[0])
		ft_put_buf(arg->buf[i], 1);
	if (arg->light[3] && arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - length[1]);
}

char		*ft_handle_num(char *s, t_info *arg, va_list *ap)
{
	if (*s == 'U' || *s == 'u')
		arg->buf = ft_get_num_u(*s, arg, ap);
	else
		arg->buf = ft_get_num_d(*s, arg, ap);
	if (arg->err && arg->light[0] && !arg->formater[0].size)
		arg->buf[0] = '\0';
	ft_dispatch_num(arg);
	free(arg->buf);
	return (s + 1);
}
