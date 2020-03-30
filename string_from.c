/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:01:41 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:56:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Create a new string which inherits the given string. The len and cap fields
**	will be set to the length of the new string. New memory will be allocated
**	to store the new string.
**
**	@param {char *} from
**	@param {t_string *} str - to store the resulting struct
**
**	@return {bool} - true if the allocation failed
*/

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
