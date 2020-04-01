/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:44:35 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/01 20:50:03 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_resize(t_string *str)
{
	char	*new_str;

	if (str->cap == 0)
		str->cap++;
	str->cap *= 2;
	new_str = malloc(str->cap + 1);
	if (!new_str)
		return (true);
	ft_memcpy(new_str, str->str, str->len + 1);
	free(str->str);
	str->str = new_str;
	return (false);
}
