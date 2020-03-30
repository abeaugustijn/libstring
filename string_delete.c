/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:25:19 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:35:32 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

/*
**	Delete a subsection of the string. This will not resize the string to fit
**	the shorter string. If len == 0 or if the index is invalid, this function
**	will not do anything to the string. The new length of the string will be
**	set to the result.
**
**	@param {t_string *} str
**	@param {size_t} index - the index of the first char to be deleted
**	@param {size_t} len - the amount of characters (including the one on index)
**		to be deleted.
*/

void	string_delete(t_string *str, size_t index, size_t len)
{
	size_t	res_len;

	if (index >= str->len)
		return ;
	if (index + len > str->len)
		len = str->len - index;
	if (!len)
		return ;
	res_len = str->len - len - index;
	ft_memcpy(&str->str[index], &str->str[index + len], res_len + 1);
	str->len -= len;
}
