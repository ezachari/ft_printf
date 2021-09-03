/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:13:18 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/17 19:08:31 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_procprecision(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = 0;
	if (s == NULL && p->precision != 0)
		s = "0";
	slen = ft_strlen(s) + 2;
	if (!(space = malloc(slen + 1)))
		return (NULL);
	ft_strcpy(space, "0x");
	ft_strcpy(&space[2], s);
	return (space);
}

static char	*ft_procwidth(t_struct *p, char *space, char *s)
{
	int	slen;

	slen = ft_strlen(s);
	if (p->precision == 0 && s[2] == '0')
	{
		ft_strncpy(&s[2], "", 1);
		p->width++;
	}
	if (p->width <= slen)
		return (s);
	if (!(space = ft_fillspace(p->width, p->padding)))
		return (NULL);
	if (p->minus == ENABLED)
		ft_strncpy(space, s, slen);
	else
		ft_strncpy(&space[p->width - slen], s, slen);
	return (space);
}

int			ft_print_pointer(va_list ap, t_struct *p)
{
	t_space	*space;
	char	*res;

	res = ft_lltoa_base(va_arg(ap, long long), HEX_LOW);
	space = ft_prepspace();
	if ((res = ft_procprecision(p, space->precision, res)) == NULL
			|| (res = ft_procwidth(p, space->width, res)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	p->nbyte += ft_putstrn(res, ft_strlen(res));
	ft_freespace(space);
	return (0);
}
