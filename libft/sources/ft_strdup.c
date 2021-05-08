/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:00:42 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 15:00:43 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*strdup(const char *s)
{
	char			*str;
	unsigned int	len_s;
	unsigned int	i;

	i = 0;
	len_s = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!str)
		return (0);
	while (i < len_s)
	{
		str[i] = s[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

//변수 개수를 적게 사용하는 것이 좋은 건가?
