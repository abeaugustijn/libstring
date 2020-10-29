/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_push.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:39 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:39 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

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
