/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_from_range.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:34 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:34 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_from_range(char *from, size_t start, size_t len, t_string *str)
{
	size_t	from_len;

	from_len = ft_strlen(from);
	if (!from_len || start >= from_len)
		return (true);
	if (start + len > from_len)
		len = from_len - start;
	str->str = malloc(len + 1);
	if (!str->str)
		return (true);
	ft_memcpy(str->str, &from[start], len);
	str->str[len] = '\0';
	str->cap = len;
	str->len = len;
	return (false);
}
