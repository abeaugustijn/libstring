/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:37 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:37 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

bool		string_insert(t_string *str, size_t index, char *insert)
{
	size_t	insert_len;

	insert_len = ft_strlen(insert);
	if (!insert_len || index > str->len)
		return (false);
	if (string_resize_cap(str, str->len + insert_len))
		return (true);
	ft_memmove(&str->str[index + insert_len], &str->str[index],
			str->len - index + 1);
	ft_memcpy(&str->str[index], insert, insert_len);
	str->len += insert_len;
	return (false);
}
