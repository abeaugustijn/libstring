/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:44:35 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 23:09:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

bool	string_resize(t_string *str)
{
	char	*new_str;
	size_t	new_cap;

	new_cap = str->cap * 2;
	new_str = malloc(new_cap + 1);
	if (!new_str)
		return (true);
	string_memcpy(new_str, str->str, str->len);
	new_str[str->len] = '\0';
	free(str->str);
	str->str = new_str;
	str->cap = new_cap;
	return (false);
}
