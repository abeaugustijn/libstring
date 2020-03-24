/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:36:16 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 23:09:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include <stddef.h>
# include <stdbool.h>

typedef struct	s_string {
	size_t	len;
	size_t	cap;
	char	*str;
}				t_string;

bool	string_init(size_t init_cap, char *init_value, t_string *result);
void	*string_memcpy(void *dst, const void *src, size_t n);
bool	string_push(t_string *str, char *to_push);
bool	string_resize(t_string *str);
bool	string_shrink(t_string *str);
size_t	string_len(char *str);

#endif
