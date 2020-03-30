/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstring.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:36:16 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 11:02:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

typedef struct	s_string {
	size_t	len;
	size_t	cap;
	char	*str;
}				t_string;

bool	string_from(char *from, t_string *str);
bool	string_init(size_t init_cap, char *init_value, t_string *result);
bool	string_insert(t_string *str, size_t i, char *insert);
bool	string_push(t_string *str, char *to_push);
bool	string_replace(t_string *str, char *to_find, char *replace);
bool	string_resize(t_string *str);
bool	string_resize_cap(t_string *str, size_t cap);
bool	string_shrink(t_string *str);
void	string_delete(t_string *str, size_t index, size_t len);
void	string_free(t_string *str);

/*
**	Utils
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *mem, size_t size);

#endif
