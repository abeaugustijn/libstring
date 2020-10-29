/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_from.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:32 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:32 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_from(char *from, t_string *str)
{
	size_t	len;

	len = ft_strlen(from);
	str->str = malloc(len + 1);
	if (!str->str)
		return (true);
	ft_memcpy(str->str, from, len + 1);
	str->cap = len;
	str->len = len;
	return (false);
}
