/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezachari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:32:49 by ezachari          #+#    #+#             */
/*   Updated: 2020/11/18 17:32:19 by ezachari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft/libft.h"

# define FLAG "-0"
# define CONV "cspdiuxX%"
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define LEN "lh"
# define ERROR -1
# define DISABLED -1
# define ENABLED 1
# define SKIP 0

typedef struct	s_struct
{
	int		nbyte;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		spec;
	int		mod;
	char	padding;
	char	sign;
}				t_struct;
typedef struct	s_space
{
	char	*precision;
	char	*width;
}				t_space;

int				ft_print_unsigned(t_struct *p, char *res);
int				ft_print_hexa(t_struct *p, char *res);
char			*ft_procsign(t_struct *p, char *space, int slen);
char			*ft_prepsign(t_struct *p, char *s);
int				ft_print_int(t_struct *p, char *res);
int				ft_print_char(t_struct *p, char c);
int				ft_prehexa(va_list ap, t_struct *p, char *base);
int				ft_preint(va_list ap, t_struct *p);
int				ft_prechar(va_list ap, t_struct *p);
int				ft_prestr(va_list ap, t_struct *p);
int				ft_preunsigned(va_list ap, t_struct *p);
int				ft_print_str(t_struct *p, char *res);
t_space			*ft_prepspace(void);
char			*ft_fillspace(int size, char padding);
void			ft_freespace(t_space *space);
int				ft_parse(char **format, va_list ap, t_struct *p);
int				ft_print_pointer(va_list ap, t_struct *p);
int				ft_print_spec(t_struct *p);
int				ft_printf(const char *format, ...);
#endif
