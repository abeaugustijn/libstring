/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:01:41 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 12:00:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include "utils/utils.h"
#include <stdlib.h>

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
