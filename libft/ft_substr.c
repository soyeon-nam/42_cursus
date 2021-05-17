/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:03:25 by snam              #+#    #+#             */
/*   Updated: 2021/05/10 13:07:08 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	//man substr 대로 해줘야 하는건가
	/*if (!s)
		return (0);*/
	if (len == 0 || (start + 1 >= ft_strlen(s)))
	{
		str = (char *)malloc(1);
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start > 0)
		start -= 1;
	else if (start == 0)
		0;
	while (s[start + i] && (i < len))
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = 0;
	return (str);
}