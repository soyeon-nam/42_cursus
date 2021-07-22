/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 20:19:38 by snam              #+#    #+#             */
/*   Updated: 2021/07/22 23:32:21 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void			**free_malloc(char **str, int i)
{
	while (i < 0)
	{
		free(str[i]);
		--i;
	}
	free(str);
	return (0);
}

static int				count_word(char *s)
{
	unsigned int count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			++s;
		if (!*s)
			break ;
		while (*s && *s != ' ')
			++s;
		++count;
	}
	return (count);
}

static char				*slpit_word(char *start, int num)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(sizeof(char) * (num + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < num)
	{
		ptr[i] = start[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

int					split_argv(char ***argv)
{
	char			*s;
	char			**str;
	char			*start;
	int				argc;
	int				i;

	s = (*argv)[1];
	argc = count_word((char *)s);
	str = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < argc)
	{
		while (*s == ' ')
			++s;
		start = (char *)s;
		while (0 <= *s && *s <= 9)
			++s;
		if (*s != ' ')
		{
			free_malloc(str, i - 1);
			return (0);
		}
		if (!(str[i] = slpit_word(start, s - start)))
		{
			free_malloc(str, i);
			return (0);
		}
		++i;
	}
	str[i] = 0;
	*argv = str;
	return (argc);
}
