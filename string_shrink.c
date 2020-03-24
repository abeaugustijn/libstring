/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:48:49 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 22:51:44 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

bool	string_shrink(t_string *str)
{
	char	*new_str;

	new_str = malloc(str->size + 1);
	if (!new_str)
		return (true);
	string_memcpy(new_str, str->str, str->size + 1);
	free(str->str);
	str->cap = str->size;
	str->str = new_str;
	return (false);
}
