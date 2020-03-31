/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 18:43:35 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 18:45:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

void	string_reset(t_string *str, bool clear)
{
	if (clear)
		ft_bzero(str->str, str->len);
	str->len = 0;
}
