/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:58:09 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 11:02:18 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Resize a string so the capacity will have a minimum value of the given
**	capacity. This is more efficient to use than string_resize if the desired
**	capacity is already known at the time of calling, because only one
**	allocation and strcpy are necessary for the operation. This will still
**	keep multiplying the current capacity with 2, like the normal string_resize
**	will.
**
**	@param {t_string *} str
**	@param {size_t} cap
**
**	@return {bool} - true if the allocation failed
*/

bool	string_resize_cap(t_string *str, size_t cap)
{
	char	*new_str;

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
