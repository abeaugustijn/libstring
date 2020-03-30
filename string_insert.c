/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 08:58:34 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:43:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

/*
**	Insert a substring into an existing string. This will only allocate new
**	memory if the length of the new string exceeds the strings current
**	capacity. If insert is empty or if the index is invalid, false will be
**	returned and nothing will happen.
**
**	@param {t_string *} str
**	@param {size_t} index - the index in the string at which the substring will
**		be inserted. In the result, this value will be the index of the first
**		character of the substring.
**	@param {char *} insert - the string to insert
**
**	@return {bool} - true if the allocation fails
*/

bool		string_insert(t_string *str, size_t index, char *insert)
{
	size_t	insert_len;

	insert_len = ft_strlen(insert);
	if (!insert_len || index >= str->len)
		return (false);
	if (index >= str->len)
		return (false);
	while (insert_len + str->len > str->cap)
		if (string_resize(str))
			return (true);
	ft_memmove(&str->str[index + insert_len], &str->str[index],
			str->len - index + 1);
	ft_memcpy(&str->str[index], insert, insert_len);
	str->len += insert_len;
	return (false);
}
