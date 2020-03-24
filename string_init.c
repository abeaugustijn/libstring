/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:38:38 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 23:09:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

bool	string_init(size_t init_cap, char *init_value, t_string *result)
{
	size_t	init_len;

	if (init_value)
	{
		init_len = string_len(init_value);
		if (init_len > init_cap)
			return (true);
	}
	result->cap = init_cap;
	result->len = (init_value ? init_len : 0);
	result->str = malloc(init_cap + 1);
	if (!result->str)
		return (true);
	if (init_value)
		string_memcpy(result->str, init_value, init_len + 1);
	return (false);
}
