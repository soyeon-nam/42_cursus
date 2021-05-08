/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:16:45 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 17:22:32 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	char		*ptr;
	int			sign;
	long long	nb;

	ptr = str;
	while (ft_isspace(*ptr))
		++ptr;
	sign = 1;
	if (*ptr == '+' || *ptr == '-')
	{
		sign = (*ptr == '-') ? -1 : 1;
		++ptr;
	}
	nb = 0;
	while ('0' <= *ptr && *ptr <= '9')
	{
		nb = (nb * 10) + (*ptr - '0');
		++ptr;
	}
	return ((int)(nb * sign));
}

/*
long vs int
https://smallpants.tistory.com/10
*/
