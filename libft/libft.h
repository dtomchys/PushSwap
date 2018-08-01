/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:33:12 by dtomchys          #+#    #+#             */
/*   Updated: 2017/11/10 20:20:51 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# define BUFF_SIZE 16

char	g_buf[4096];
int		g_i;

typedef enum		e_mod
{
	EMPTY = 0, M_H, M_HH, M_L, M_LL, M_Z, M_J
}					t_mod;

typedef struct		s_flag
{
	char			a[2];
	int				size;
}					t_flag;

typedef struct		s_info
{
	char			*buf;
	t_flag			formater[4];
	int				light[4];
	int				minus;
	int				zero;
	int				err;
	t_mod			modi;
	char			neg;
}					t_info;

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, char *src, size_t s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int,
		char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstrv(char **strv);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);

char				*ft_recursion(char *s, t_info *arg, va_list *ap);
char				*ft_set_mod(char *s, t_info *arg, va_list *ap);
char				*ft_set_pre(char *s, t_info *arg, va_list *ap);
char				*ft_set_wid(char *s, t_info *arg, va_list *ap);
char				*ft_set_sign(char *s, t_info *arg, va_list *ap);
char				*ft_set_sharp(char *s, t_info *arg, va_list *ap);
char				*ft_handle_ch(char *s, t_info *arg, va_list *ap);
char				*ft_handle_num(char *s, t_info *arg, va_list *ap);
char				*ft_handle_num_base(char *s, t_info *arg, va_list *ap);
int					ft_printf(const char *format, ...);
void				ft_put_buf(unsigned int ch, int amount);
void				ft_reset_arg(t_info *arg);
void				ft_display_buf(void);
char				*ft_dec_wstr(wchar_t *ws);
int					ft_wchar_len(wchar_t wc);
int					ft_wstr_bytelen(wchar_t *wstr);
int					ft_wstrlen(wchar_t *wstr);
char				*ft_itoa_base(uintmax_t nbr, int base);

#endif
