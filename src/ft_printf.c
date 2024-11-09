/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:56 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/09 10:14:37 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int	(*t_format_func)(va_list);

/*

int	format_(va_list args)
{
	int	count;

	count = 0;
	return (count);
}

*/

int	format_c(va_list args)
{
	int	count;

	count = 0;
	ft_putchar_fd(va_arg(args, int), STD_OUT);
	count++;
	return (count);
}

int	format_s(va_list args)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(args, char *);
	ft_putstr_fd(str, STD_OUT);
	count += (int)ft_strlen(str);
	return (count);
}

size_t	get_memlen(void *ptr)
{
	size_t			len;
	unsigned long	tmp;

	len = 0;
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 16;
		len++;
	}
	return (len);
}

size_t	put_memaddr(void *ptr, char * hex)
{
	const size_t	addr_len = get_memlen(ptr);
	char			buffer[17];
	size_t			i;
	unsigned long	tmp;

	i = addr_len;
	buffer[i] = '\0';
	tmp = (unsigned long)ptr;
	if (tmp == 0)
		buffer[--i] = '0';
	while (i--)
	{
		buffer[i] = hex[tmp % 16];
		tmp /= 16;
	}
	ft_putstr_fd("0x",1);
	ft_putstr_fd(buffer,1);
	return (addr_len + 2);
}

//バッファを用意→アドレスを代入→出力する→バッファの文字数を返す
int	format_p(va_list args)
{
	int					count;

	count = put_memaddr(va_arg(args, void *), HEX_SMALL);
	return (count);
}

int	get_int_len(long n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return ((int)count);
}

int	format_d(va_list args)
{
	const int	i = va_arg(args, int);
	const int	count = get_int_len(i);
	
	ft_putnbr_fd((long)i, STD_OUT);
	return (count);
}

int	format_i(va_list args)
{
	return (format_d(args));
}

int	format_percent(va_list args)
{
	const int	count = 1;
	
	(void)args;
	ft_putchar_fd('%',STD_OUT);
	return (count);
}

int	handle_format(char format, va_list args)
{
	int					count;
	size_t				i;
	const char			*format_list = "cspdi%";
	// const char	*format_list = "cspdiuxX%";
	const t_format_func	format_func[] = {format_c, format_s, format_p, format_d, format_i, format_percent};

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
