/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:15:06 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/15 17:41:03 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_procwidth(t_struct *p, char *space)
{
	p->width--;
	if (p->width < 1)
		return ("");
	if (!(space = ft_fillspace(p->width, p->padding)))
		return (NULL);
	return (space);
}

int			ft_print_char(t_struct *p, char c)
{
	char		*res;
	int			flag;
	t_space		*space;

	flag = DISABLED;
	if (p->precision > 0)
		return (ERROR);
	space = ft_prepspace();
	if ((res = ft_procwidth(p, space->width)) == NULL)
	{
		ft_freespace(space);
		return (ERROR);
	}
	if (p->minus == ENABLED)
		p->nbyte += ft_putchar(c) + ft_putstr(res);
	else
		p->nbyte += ft_putstr(res) + ft_putchar(c);
	free(space);
	return (0);
}
