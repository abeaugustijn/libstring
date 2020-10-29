/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_split.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:46 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:46 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

static bool	is_split(char c, char *split_chars)
{
	size_t	i;

	if (c == '\0')
		return (false);
	i = 0;
	while (split_chars[i] && split_chars[i] != c)
		i++;
	return (split_chars[i] == c);
}

static bool	string_split_free(t_string *arr, size_t arrlen)
{
	size_t	i;

	i = 0;
	while (i < arrlen)
	{
		string_free(&arr[i]);
		i++;
	}
	free(arr);
	return (true);
}

static void	string_split_size(char *to_split, char *split_chars,
				size_t *result_size)
{
	size_t	i;

	*result_size = 0;
	i = 0;
	while (42)
	{
		while (is_split(to_split[i], split_chars))
			i++;
		if (!to_split[i])
			return ;
		(*result_size)++;
		while (to_split[i] && !is_split(to_split[i], split_chars))
			i++;
	}
}

bool		string_split_allocate(char *to_split, char *split_chars,
				t_string **result, size_t *result_size)
{
	string_split_size(to_split, split_chars, result_size);
	if (*result_size == 0)
		*result = NULL;
	if (!*to_split)
		return (true);
	*result = malloc(sizeof(t_string) * (*result_size));
	if (!*result)
		return (true);
	return (false);
}

bool		string_split(char *to_split, char *split_chars, t_string **result,
				size_t *result_size)
{
	size_t	arr_index;
	size_t	i;
	size_t	word_len;

	if (string_split_allocate(to_split, split_chars, result, result_size))
		return (true);
	i = 0;
	arr_index = 0;
	while (42)
	{
		while (is_split(to_split[i], split_chars))
			i++;
		if (!to_split[i])
			return (false);
		word_len = 0;
		while (to_split[i + word_len] &&
				!is_split(to_split[i + word_len], split_chars))
			word_len++;
		if (string_from_range(to_split, i, word_len, &(*result)[arr_index]))
			return (string_split_free(*result, arr_index - 1));
		arr_index++;
		i += word_len;
	}
}
