/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:04:17 by snam              #+#    #+#             */
/*   Updated: 2021/05/18 16:04:28 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
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
