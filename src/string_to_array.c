/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_to_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:47 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:47 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>

char	**string_to_array(size_t len, t_string array[])
{
	char	**res;
	size_t	i;

	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = NULL;
	i = 0;
	while (i < len)
	{
		res[i] = array[i].str;
		i++;
	}
	return (res);
}
