/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:38:38 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:40:41 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Initialize a new string. A initial string (init_value) can be given. If the
**	length of this string exceeds the init_cap, true will be returned and
**	nothing will happen to the result string.
**
**	@param {size_t} init_cap - the amount of bytes which will be allocated in
**		this function.
**	@param {char *} init_value - the string to store at first. NULL if the new
**		string should be empty.
**	@param {t_string *} result
**
**	@return {bool} - true if the allocation failed
*/

bool	string_init(size_t init_cap, char *init_value, t_string *result)
{
	size_t	init_len;

	if (init_value)
	{
		init_len = ft_strlen(init_value);
		if (init_len > init_cap)
			return (true);
	}
	result->cap = init_cap;
	result->len = (init_value ? init_len : 0);
	result->str = malloc(init_cap + 1);
	if (!result->str)
		return (true);
	if (init_value)
		ft_memcpy(result->str, init_value, init_len + 1);
	return (false);
}
