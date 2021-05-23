/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:32:49 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 18:48:33 by snam             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5000
// # endif


#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

