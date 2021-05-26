/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:32:49 by snam              #+#    #+#             */
/*   Updated: 2021/05/27 02:09:38 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5000
// # endif

#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
int		affix_buf(char **sep, char **line, int *size);
char	*concat_line(char *buf, int *size, char **line, char	*temp);
int		free_alloc(char **temp, char **line);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy_until_nl(char *dst, char *src, unsigned int n);
size_t	ft_strcat_until_nl(char *dst, const char *src, size_t size);
