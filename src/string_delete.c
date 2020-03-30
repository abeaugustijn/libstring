/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:25:19 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 12:29:30 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

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
