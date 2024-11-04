/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomsato <tomsato@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:31:29 by tomsato           #+#    #+#             */
/*   Updated: 2024/11/04 17:31:14 by tomsato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# define STD_OUT 1
# define HEX_BIG "0123456789ABCDEF"
# define HEX_SMALL "0123456789abcdef"
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *, ...);

#endif