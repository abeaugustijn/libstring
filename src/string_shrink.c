/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_shrink.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:45 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:45 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_shrink(t_string *str)
{
	char	*new_str;

	new_str = malloc(str->len + 1);
	if (!new_str)
		return (true);
	ft_memcpy(new_str, str->str, str->len + 1);
	free(str->str);
	str->cap = str->len;
	str->str = new_str;
	return (false);
}
