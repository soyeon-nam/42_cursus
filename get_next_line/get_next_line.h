/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:32:49 by snam              #+#    #+#             */
/*   Updated: 2021/05/10 16:06:15 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif


#include <unistd.h>

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size)
