/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:16:39 by snam              #+#    #+#             */
/*   Updated: 2021/05/06 22:34:39 by snam             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n);



size_t	ft_strlen(const char *str);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char* str1, const char* str2, size_t num);
int		ft_atoi(const char* str);
int		ft_isalpha (int c);
int 	ft_isdigit(int c);
int 	ft_isalnum(int c);
int		ft_isascii(int c);
int 	ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t count, size_t size);
char	*strdup(const char *s);


char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
