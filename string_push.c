/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:40:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 11:04:14 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

/*
**	Push a string of characters to the end of the existing string. If the
**	capacity allows it, no new memory will be allocated. Otherwise the function
**	allocates new memory until the new string will fit.
**
**	@param {t_string *} str
**	@param {char *} to_push
**
**	@return {bool} - true if an allocation failed
*/

bool	string_push(t_string *str, char *to_push)
{
	size_t	to_push_len;

	to_push_len = ft_strlen(to_push);
	if (string_resize_cap(str, str->len + to_push_len))
		return (true);
	ft_memcpy(&str->str[str->len], to_push, to_push_len + 1);
	str->len += to_push_len;
	return (false);
}
