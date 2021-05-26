/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:43:05 by snam              #+#    #+#             */
/*   Updated: 2021/05/27 08:04:21 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>


int		get_next_line(int fd, char **line);
int		read_line(char **line, char **fd_backup, char *buf, int fd);
int		concat_backup(char **fd_backup, char **line);
int		free_alloc(char **backup, char **line);

int				split_nl(char **dst, char **src);
char			*ft_strjoin(char const *s1, char const *s2);
void		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_strncpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
