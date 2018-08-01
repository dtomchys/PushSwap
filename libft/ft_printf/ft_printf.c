/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:42:42 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/17 19:43:01 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void			ft_undefined(char *s, t_info *arg)
{
	arg->formater[3].a[0] = arg->zero && !arg->minus ? '0' : ' ';
	if (arg->light[3] && !arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - 1);
	ft_put_buf(*s, 1);
	if (arg->light[3] && arg->minus)
		ft_put_buf(arg->formater[3].a[0], arg->formater[3].size - 1);
}

char				*ft_recursion(char *s, t_info *arg, va_list *ap)
{
	if (*s == '\0')
		return (s);
	if (*s == 'h' || *s == 'l' || *s == 'z' || *s == 'j')
		return (ft_set_mod(s, arg, ap));
	if (*s == '.')
		return (ft_set_pre(s + 1, arg, ap));
	if (*s == '0')
		return (ft_recursion(s + (arg->zero = 1), arg, ap));
	if (ft_isdigit(*s))
		return (ft_set_wid(s, arg, ap));
	if (*s == ' ' || *s == '+')
		return (ft_set_sign(s, arg, ap));
	else if (*s == '#')
		return (ft_set_sharp(s, arg, ap));
	if (*s == '-')
		return (ft_recursion(s + ++arg->minus, arg, ap));
	if (*s == 's' || *s == 'S' || *s == 'c' || *s == 'C')
		return (ft_handle_ch(s, arg, ap));
	else if (*s == 'd' || *s == 'i' || *s == 'D' || *s == 'u' || *s == 'U')
		return (ft_handle_num(s, arg, ap));
	else if (*s == 'x' || *s == 'X' || *s == 'o' || *s == 'O' || *s == 'p')
		return (ft_handle_num_base(s, arg, ap));
	ft_undefined(s, arg);
	return (s + 1);
}

static int			ft_display(char *str, va_list *ap)
{
	t_info arg;

	ft_reset_arg(&arg);
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_recursion(str + 1, &arg, ap);
			ft_reset_arg(&arg);
		}
		else
		{
			ft_put_buf(*str, 1);
			str++;
		}
	}
	ft_display_buf();
	return (g_i);
}

int					ft_printf(const char *format, ...)
{
	va_list ap;
	int		res;
	char	*temp;

	temp = (char*)format;
	va_start(ap, format);
	g_i = 0;
	res = ft_display(temp, &ap);
	va_end(ap);
	return (res);
}
