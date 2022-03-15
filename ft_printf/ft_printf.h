/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seubaek <seubaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 00:52:35 by seubaek           #+#    #+#             */
/*   Updated: 2021/06/10 17:30:19 by seubaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FORMAT "cspdiuxX%"

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# include <stdio.h>

typedef struct	s_args
{
	int		c;
	int		has_width;
	int		has_precision;
	int		width;
	int		precision;
	int		zero;
	int		minus;
	int		wid_star;
	int		prec_star;
	int		dot;
}				t_args;

void			init_args(t_args *args);
char			*read_args(t_args *args, char *str, va_list ap);
int				check_format(t_args *args, va_list ap);
char			*read_flag3(t_args *args, char *s, va_list ap);
char			*read_flag2(t_args *args, char *s);
char			*read_flag1(t_args *args, char *s, va_list ap);
int				ft_printf(const char *format, ...);

int				ft_putchar(char c);
int				ft_putstr(char *s);
char			*ft_strchr(char *str, char c);
int				ft_strlen(char *str);
int				is_digit(int num);
int				is_number(char c);
int				is_space(char c);
int				ft_putlstr(char *str, int len);
int				ft_putnbr(t_args *args, int num, int padding);
int				ft_unsigned_putnbr(t_args *args, unsigned int num, int padding);
int				ft_atoi(char *str);
int				unsigned_is_digit(unsigned int num);
int				ft_puthex(t_args *args, unsigned int num, int padding);
int				is_digit_hex(unsigned int num);
int				print_width(int width, int size);
int				ft_puthex_ad(t_args *args, unsigned long long num, int padding);
int				min_num_cond(int padding);
int				is_digit_hex_ad(unsigned long long num);

int				cond_c(t_args *args, va_list ap);
int				cond_s(t_args *args, va_list ap);
int				cond_d(t_args *args, va_list ap);
int				cond_u(t_args *args, va_list ap);
int				cond_x(t_args *args, va_list ap);
int				cond_p(t_args *args, va_list ap);

int				output_c(t_args *args, char c, int len);
int				output_s(t_args *args, char *str, int len);
int				output_d(t_args *args, int num, int len, int padding);
int				output_u(t_args *args, unsigned int num, int len,\
						int padding);
int				output_p(t_args *args, unsigned long long num, int len,\
						int padding);

#endif
