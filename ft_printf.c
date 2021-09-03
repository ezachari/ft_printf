/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:32:40 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/18 17:33:04 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_condition(char *format, va_list ap, t_struct *p)
{
	if (*format == 'c')
		return (ft_prechar(ap, p));
	else if (*format == 's')
		return (ft_prestr(ap, p));
	else if (*format == 'd' || *format == 'i')
		return (ft_preint(ap, p));
	else if (*format == 'x')
		return (ft_prehexa(ap, p, HEX_LOW));
	else if (*format == 'X')
		return (ft_prehexa(ap, p, HEX_UP));
	else if (*format == 'u')
		return (ft_preunsigned(ap, p));
	else if (*format == 'p')
		return (ft_print_pointer(ap, p));
	else if (*format == '%')
		return (ft_print_spec(p));
	else
		return (ERROR);
}

static void	ft_prep(t_struct *p)
{
	p->width = DISABLED;
	p->precision = DISABLED;
	p->zero = DISABLED;
	p->minus = DISABLED;
	p->mod = DISABLED;
	p->padding = ' ';
	p->sign = '\0';
}

static int	ft_format(char *format, va_list ap)
{
	t_struct p;

	p.nbyte = 0;
	if (format == 0)
		return (ERROR);
	while (*format != '\0')
	{
		while (*format != '%' && *format)
		{
			p.nbyte += ft_putchar(*format);
			format++;
		}
		if (*format == '%')
		{
			format++;
			ft_prep(&p);
			if (ft_parse(&format, ap, &p) == ERROR)
				return (ERROR);
			if (ft_condition(format, ap, &p) == ERROR)
				return (ERROR);
			format++;
		}
	}
	return (p.nbyte);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		nbyte;

	va_start(ap, format);
	if ((nbyte = ft_format((char *)format, ap)) == ERROR)
		return (ERROR);
	va_end(ap);
	return (nbyte);
}
