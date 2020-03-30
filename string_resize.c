/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:44:35 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 11:03:26 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Double the capacity of an existing string. This will allocate new memory,
**	copy the contents of the old string to the new string, set the str element
**	of the string struct to the new memory and free the old string.
**
**	@param {t_string *} str
**
**	@return {bool} - true if the allocation failed
*/

bool	string_resize(t_string *str)
{
	char	*new_str;

	str->cap *= 2;
	new_str = malloc(str->cap + 1);
	if (!new_str)
		return (true);
	ft_memcpy(new_str, str->str, str->len + 1);
	free(str->str);
	str->str = new_str;
	return (false);
}
