/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:48:49 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:48:54 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Shrink the size of a string down to the minimum amount of bytes necessary
**	to store the string.
**
**	@param {t_string *} str
**
**	@return {bool} - true if the allocation failed
*/

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
