/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_replace.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:41 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:41 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

bool	string_replace(t_string *str, char *to_find, char *replace)
{
	size_t	i;
	size_t	to_find_len;
	size_t	replace_len;

	to_find_len = ft_strlen(to_find);
	if (!to_find_len)
		return (false);
	replace_len = ft_strlen(replace);
	i = 0;
	while (str->str[i])
	{
		if (!ft_strncmp(&str->str[i], to_find, to_find_len))
		{
			string_delete(str, i, to_find_len);
			if (string_insert(str, i, replace))
				return (true);
			i += replace_len;
		}
		else
			i++;
	}
	return (false);
}
