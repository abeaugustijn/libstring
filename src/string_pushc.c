/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_pushc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:40:33 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 12:46:49 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

bool	string_pushc(t_string *str, char to_push)
{
	if (string_resize_cap(str, str->len + 1))
		return (true);
	str->str[str->len] = to_push;
	str->len++;
	str->str[str->len] = '\0';
	return (false);
}
