/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:14:46 by hmassonn          #+#    #+#             */
/*   Updated: 2017/01/16 18:23:35 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# define EMPTY_STR 1000000000
# define BUFF_SIZE 9
# define FLAGZ flags->hh == 0 && flags->h == 0 && flags->l == 0
# define STRZ flags->ll == 0 && flags->j == 0 && flags->z == 0
# define ZEROZ str[0] == '0' && str[1] == '\0' && flags->point

typedef unsigned char	t_unch;

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			plus;
	int			dieze;
	int			space;
	int			width_min;
	int			point;
	int			precision;
	int			maj;
	int			o;
	int			omaj;
	int			d;
	int			x;
	int			type;
	int			neg;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			u;
}				t_flags;

typedef struct	s_conv
{
	int			(*convert[14])(char *nb, va_list ap, t_flags *flags);
}				t_conv;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_fd
{
	char		*stock[5000];
}				t_fd;

int				convert_s(char *nb, va_list ap, t_flags	*flags);
int				convert_smaj(char *nb, va_list ap, t_flags	*flags);
int				convert_p(char *nb, va_list ap, t_flags *flags);
int				convert_di(char *nb, va_list ap, t_flags	*flags);
int				convert_dmaj(char *nb, va_list ap, t_flags *flags);
int				convert_o(char *nb, va_list ap, t_flags *flags);
int				convert_omaj(char *nb, va_list ap, t_flags *flags);
int				convert_u(char *nb, va_list ap, t_flags *flags);
int				convert_umaj(char *nb, va_list ap, t_flags *flags);
int				convert_x(char *nb, va_list ap, t_flags *flags);
int				convert_xmaj(char *nb, va_list ap, t_flags *flags);
int				convert_c(char *nb, va_list ap, t_flags	*flags);
int				convert_cmaj(char *nb, va_list ap, t_flags	*flags);
int				convert_modulo(char *nb, va_list ap, t_flags *flags);
t_flags			*check_minus(t_flags *flags, char format);
t_flags			*check_plus(t_flags *flags, char format);
t_flags			*check_point(t_flags *flags, char format);
t_conv			*init_conv(t_conv *conv);
int				smaj_end(size_t len, t_flags *flags, char *size);
void			ft_putwchar(wchar_t c);
void			ft_putwstr(wchar_t const *str);
size_t			ft_wstrlen(wchar_t *str);
int				ft_puthexa(unsigned int n);
int				ft_puthexamaj(unsigned int n);
t_flags			*check_flags(const char *restrict format, int *i,
	t_flags *flags);
t_flags			*check_size(const char *restrict format, int *i,
	t_flags *flags);
t_flags			*init_flags(t_flags *flags);
char			*pull_str_flags(char*str, t_flags *flags);
char			*pull_char_flags(char*str, t_flags *flags);
char			*push_flags(char *str, t_flags *flags);
wchar_t			*pull_wstr_flags(wchar_t *str, t_flags *flags);
char			*ft_strextend(char *str, int length, char c);
wchar_t			*ft_wstrextend(wchar_t *str, int length, char c);
char			*ft_strextendend(char *str, int length, char c);
wchar_t			*ft_wstrextendend(wchar_t *str, int length, char c);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strnlen(const char *s, char n);
char			*ft_strdup(const char *s1);
int				*ft_strintdup(int *str, int nb);
void			ft_strintcpy(int *src, int *dst, int nb);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcpyend(char *dst, const char *src);
wchar_t			*ft_wstrcpyend(wchar_t *dst, const wchar_t *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_sqrt(int nb);
int				ft_abs(int x);
void			ft_swap(int *a, int *b);
void			ft_swapchar(char **a, char **b);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strarrcmp(char *str, char **tab);
char			*ft_itoa(int n);
char			*ft_itoamax(intmax_t n);
char			*ft_uitoamax(uintmax_t n);
char			*ft_itoa_base(uintmax_t value, int base);
char			*ft_itoa_basemaj(uintmax_t value, int base);
void			ft_putchar(char c);
int				ft_putcharnb(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strndup(const char *s1, size_t n);
void			ft_arrdel(char **array);
char			**ft_arrnew(size_t rows, size_t columns);
void			ft_arrprint(char **array);
char			**ft_arrdup(char **tab);
int				ft_arrlen(char **tab);
void			ft_arrcpy(char **src, char **dst);
int				get_next_line(int fd, char **line);
int				ft_printf(const char *restrict format, ...);

#endif
