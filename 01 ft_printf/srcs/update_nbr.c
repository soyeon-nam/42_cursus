/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snam <snam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 10:50:49 by snam              #+#    #+#             */
/*   Updated: 2021/08/19 04:34:05 by snam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	update_width(char c, t_format_tag *tag)
{
	tag->width *= 10;
	tag->width += (c - '0');
}

void	update_precision(char c, t_format_tag *tag)
{
	tag->precision *= 10;
	tag->precision += (c - '0');
}
