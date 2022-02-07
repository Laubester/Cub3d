/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:41:40 by mafortin          #+#    #+#             */
/*   Updated: 2022/02/07 12:01:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_atoi(const char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lst_add_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_sort_strtab(char **tab);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_tabsize(char **tab);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrim_free(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_substr_free(const char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_digit_len(size_t nb);
char		*ft_utoa(unsigned int n);
char		*ft_inv_string(char *str, int size);
char		*ft_itoa_hex(unsigned int nb);
void		ft_free_tab(char **tab);
int			ft_lst_return_int(t_list *list);
long		ft_atol(const char *str);
int			ft_matrice_size(char **tab);
int			ft_isdigit_s(int *c);
int			ft_isdigit_string(char *c);
int			ft_char_search(char *string, char to_find);
char		**ft_change_line(char **matrice, char *newline, int index);
void		ft_print_matrice(char **matrice);
char		**ft_matrice_cpy(char **matrice);
char		**ft_addline(char **matrice, char *line);
void		ft_print_matrice_fd(char **matrice, int fd);
bool		ft_majchar(char c);
char		*ft_strndup(const char *s1, size_t len);
char		**ft_remove_line(char **matrice, int index);
char		*ft_append_string(char *src, char c);
char		*ft_add_newline(char *str);
char		*ft_trim_string(char *str, char c);
int			ft_nbline_file(int fd);
bool		ft_empty_line(char *string);
int			ft_longest_string(char **matrice);
char		*ft_fill(int len, char c);
bool		ft_false(char *error_msg, int fd);

#endif
