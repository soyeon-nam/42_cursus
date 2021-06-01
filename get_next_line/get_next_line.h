/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:43:05 by snam              #+#    #+#             */
/*   Updated: 2021/06/01 23:00:11 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>


int		get_next_line(int fd, char **line);
int		concat_new_buf(char **line, char **fd_backup, char **buf);
char	*make_ret_line(char **s1, char **s2);
int		concat_old_backup(char **fd_backup, char **line, char *buf);

int				split_nl(char **dst, char **src);
void		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_strncpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
#endif