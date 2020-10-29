/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_reset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:42 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:42 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <utils.h>

void	string_reset(t_string *str, bool clear)
{
	if (clear)
		ft_bzero(str->str, str->len);
	str->len = 0;
}
