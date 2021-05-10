/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:00:42 by snam              #+#    #+#             */
/*   Updated: 2021/05/10 21:52:04 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s)
{
	char			*ret;
	unsigned int	len_s;
	unsigned int	i;

	len_s = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len_s)
	{
		ret[i] = s[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}

