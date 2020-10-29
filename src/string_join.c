/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_join.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:38 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:38 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>

bool	string_join_std_consume(char *arr[], size_t arrlen, char *seperator,
			t_string *result)
{
	size_t	i;

	if (string_join_std(arr, arrlen, seperator, result))
		return (true);
	i = 0;
	while (i < arrlen)
	{
		free(&arr[i]);
		i++;
	}
	free(arr);
	return (false);
}

bool	string_join_std(char *arr[], size_t arrlen, char *seperator,
			t_string *result)
{
	size_t	i;

	if (string_init(JOIN_INIT_CAP, NULL, result))
		return (true);
	i = 0;
	while (i < arrlen)
	{
		if (string_push(result, arr[i]))
			return (true);
		if (i + 1 < arrlen)
			if (string_push(result, seperator))
				return (true);
		i++;
	}
	string_shrink(result);
	return (false);
}

bool	string_join_consume(t_string arr[], size_t arrlen, char *seperator,
			t_string *result)
{
	size_t	i;

	if (string_join(arr, arrlen, seperator, result))
		return (true);
	i = 0;
	while (i < arrlen)
	{
		string_free(&arr[i]);
		i++;
	}
	free(arr);
	return (false);
}

bool	string_join(t_string arr[], size_t arrlen, char *seperator,
			t_string *result)
{
	size_t	i;

	if (string_init(JOIN_INIT_CAP, NULL, result))
		return (true);
	i = 0;
	while (i < arrlen)
	{
		if (string_push(result, arr[i].str))
			return (true);
		if (i + 1 < arrlen)
			if (string_push(result, seperator))
				return (true);
		i++;
	}
	string_shrink(result);
	return (false);
}
