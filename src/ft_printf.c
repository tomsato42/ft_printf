/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:56 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 14:32:03 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char format, va_list args)
{
	int					count;
	size_t				i;
	const char			*format_list = "cspdiuxX%";
	const t_format_func	format_func[] = {format_c, format_s, format_p, format_d,
		format_i, format_u, format_smallx, format_bigx, format_percent};

	count = 0;
	i = 0;
	while (format_list[i])
	{
		if (format == format_list[i])
		{
			count += format_func[i](args);
			break ;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, STD_OUT);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
