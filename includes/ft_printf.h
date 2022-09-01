/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itkimura <itkimura@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:11:48 by itkimura          #+#    #+#             */
/*   Updated: 2022/09/01 12:12:56 by itkimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "libft.h"

# define TYPE "csdiouxXpf%" 
# define LEN "0hlLjzt" 
# define INIT -1
# define INVALID -2
# define DOT_ONLY -3

enum e_flag
{
	NONE,
	MINUS,
	ZERO
};

enum e_length
{
	no_len,
	h,
	l,
	L,
	j,
	z,
	t,
	hh,
	ll,
};

enum e_type
{
	TYPE_C,
	TYPE_S,
	TYPE_D,
	TYPE_I,
	TYPE_O,
	TYPE_U,
	TYPE_SX,
	TYPE_LX,
	TYPE_P,
	TYPE_F,
	TYPE_PER,
};

typedef struct s_format{
	int		flag;
	int		width;
	int		length[9];
	int		type;
	int		precision;
	int		args_len;
	int		zero;
	int		space;
	char	*prefix;
	char	*basestr;
	int		base;
	int		res;
	int		sign;
	int		sharp;
	int		space_flag;
}				t_format;

/*
 * max_digits = 2 ^ -1023 - 53 = 1076 + 1 = 1077
 * The biggest [ossible int part = 53
 */

typedef struct s_float
{
	double		nb;
	int			dot;
	int			frac_len;
	uint8_t		sign;
	uint32_t	exp;
	uint64_t	frac;
	int8_t		intpart[53];
	int8_t		fracpart[1077];
}				t_float;

/*ft_printf.c*/
void	initialize_format(t_format *f);
int		get_digits(unsigned long long nb, int base);
void	put_flag(t_format *f, char **itr);
int		read_percentage(t_format *f, char **itr, va_list *ap);
int		ft_printf(const char *format, ...);
/*format.c*/
int		is_specifier(char **itr, char *str);
void	print_format(t_format *f, va_list *ap);
void	put_width(char **itr, t_format *f, va_list *ap);
void	put_precision(char **itr, t_format *f, va_list *ap);
void	put_length(char **itr, t_format *f);
/*nbr_format.c*/
void	set_sharp(t_format *f, unsigned long long nb);
void	set_base(t_format *f, unsigned long long nb);
void	set_nbrlen(t_format *f, unsigned long long nb);
void	set_nbrformat(t_format *f, unsigned long long nb);
/*nbr.c*/
void	put_nbr(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char));
/*str.c*/
void	put_c(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char));
void	print_s(t_format *f, char *s, void (*p_flag[])(t_format *, char));
void	put_s(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char));
/*print.c*/
int		int_putchar(char c);
void	flag_none(t_format *f, char c);
void	flag_minus(t_format *f, char c);
/*float.c*/
void	float_initialize(t_float *data);
void	float_format(t_format *f, t_float *data);
void	get_float(t_format *f, t_float *data, va_list *api, uint64_t *tmp);
void	put_f(t_format *f, va_list *ap, void (*p_flag[])(t_format *, char));
/*float.c*/
void	float_flag(t_format *f, t_float *data);
void	float_len(t_format *f, t_float *data);
void	float_format(t_format *f, t_float *data);
/*float_print.c*/
void	print_f(t_format *f, t_float *data, void (*p_flag[])(t_format *, char));
/*float_rounding.c*/
int		remaining(t_float *data, int start);
int		is_round(t_float *data);
void	round_check(int i, char *str, int *flag);
void	rounding(char *str, int round);
/*float_convert.c*/
void	convert_intbit(t_float *data, uint64_t int_tmp);
void	convert_intpart(t_float *data);
void	convert_fracbit(t_float *data, uint64_t frac_tmp, int8_t *n);
void	convert_fracpart(t_float *data);
/*float_utils.c*/
void	array_add(int8_t *a, int8_t *b, int size);
void	array_divbytwo(int8_t *n, int size);
void	array_double(int8_t *n, int size);
/*test.c*/
#endif
