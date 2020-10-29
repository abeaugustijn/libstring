/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_pushc.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:40 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:40 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

bool	string_pushc(t_string *str, char to_push)
{
	if (string_resize_cap(str, str->len + 1))
		return (true);
	str->str[str->len] = to_push;
	str->len++;
	str->str[str->len] = '\0';
	return (false);
}
