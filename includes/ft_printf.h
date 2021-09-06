#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_item
{
	int		zero;
	int		negative;
	int		sign;
	int		padding;
	int		precision;
	int		precision_failed;
	int		point;
	int		conversion;
	void	*data;
	int		pure_width;
	int		failed;
}	t_item;

int			ft_printf(const char *format, ...);

int			parse(va_list ap, char **format);
t_item		*parse_item(char **format, va_list ap);
char		*parse_flags(char *tmp, t_item *item);
char		*parse_padding(char *tmp, t_item *item, va_list ap);
char		*parse_precision(char *tmp, t_item *item, va_list ap);
char		*parse_conversion(char *tmp, t_item *item);

void		*read_value(int conv, va_list ap);
void		*read_int(va_list ap);
void		*read_s(va_list ap);
void		*read_p(va_list ap);
void		*read_unsigned(va_list ap);
void		*read_per(void);

int			count_width(int mode, void *data);
int			count_digits(int num);
int			count_digits_unsigned_base(unsigned num, unsigned base);
int			count_digits_ptr(void *ptr);

int			in(char elem, const char *s);
int			max(int a, int b);
int			min(int a, int b);
void		ft_putstr_n(char *s, int n);
void		repeat_chr(int c, int n);

int			print(t_item *item);
int			print_int(t_item *item);
void		supplement(t_item *item, int opt_spaces);
int			print_unsigned(t_item *item, unsigned int base, char mode);
int			print_char(t_item *item);
int			print_s(t_item *item);
int			print_p(t_item *item);

#endif
