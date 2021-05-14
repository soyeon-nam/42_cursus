/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 14:44:55 by snam              #+#    #+#             */
/*   Updated: 2021/05/08 17:04:03 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!ret)
		return (0);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, ft_strlen(s1) + 1);
	return(ret);
}
