/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpohl <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 17:21:44 by bpohl             #+#    #+#             */
/*   Updated: 2020/04/18 09:20:06 by bpohl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int i);
void				*ft_memccpy(void *restrict dst,
					const void *restrict src,
					int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src,
					size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *str, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcat(char *dst,
					const char *src,
					size_t dstsize);
size_t				ft_strlcpy(char *dst,
					const char *src,
					size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s,
					char (*f)(unsigned int, char));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1,
					const char *s2,
					size_t n);
char				*ft_strnstr(const char *haystack,
					const char *needle,
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s,
					unsigned int start,
					size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
size_t				ft_wordcount(char *str);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));
int					ft_fprintf(const int fd,
							   const char *format, ...);
int					ft_printf(const char *format, ...);

#endif
