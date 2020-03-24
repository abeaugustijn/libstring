/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:40:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 23:06:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

bool	string_push(t_string *str, char *to_push)
{
	size_t	to_push_len;

	to_push_len = string_len(to_push);
	while (str->size + to_push_len > str->cap)
		if (string_resize(str))
			return (true);
	string_memcpy(&str->str[str->size], to_push, to_push_len + 1);
	str->size += to_push_len;
	return (false);
}
