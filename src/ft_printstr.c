/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odruke-s <odruke-s@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:30:31 by odruke-s          #+#    #+#             */
/*   Updated: 2024/10/24 12:55:01 by odruke-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int	padding(t_flags *flags)
{
	int	len;

	len = 0;
	while(0 < --flags->width)
		len += ft_printchar(' ');
	return (len);
}
*/

static void	ft_process_align(char *str, int *len, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->align)
	{
		while (flags->precision > i && str[i])
			*len += ft_printchar(str[i++]);
		*len += padding(flags, *len);
	}
	else
	{
		*len += flags->precision;
		*len += padding(flags, *len);
		while (flags->precision > i && str[i])
			ft_printchar(str[i++]);
	}
}

int	ft_printstr(char *str, t_flags flags)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (flags.precision < 0)
	{
		flags.precision = ft_strlen(str);
		ft_process_align(str, &len, &flags);
	}
	else
		ft_process_align(str, &len, &flags);
	return (len);
}
