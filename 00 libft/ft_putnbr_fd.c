/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:25:44 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 16:15:47 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(int nb, int fd)
{
	char	a;

	a = nb % 10 + 48;
	nb = nb / 10;
	if (nb > 0)
		print(nb, fd);
	write(fd, &a, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
		print(nb, fd);
	}
	else
		print(nb, fd);
}
