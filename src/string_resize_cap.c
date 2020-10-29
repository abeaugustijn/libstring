/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_resize_cap.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:44 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:44 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_resize_cap(t_string *str, size_t cap)
{
	char	*new_str;

	if (str->cap == 0)
		str->cap++;
	while (cap > str->cap)
		str->cap *= 2;
	new_str = malloc(str->cap + 1);
	if (!new_str)
		return (true);
	ft_memcpy(new_str, str->str, str->len + 1);
	free(str->str);
	str->str = new_str;
	return (false);
}
