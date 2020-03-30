/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: aaugusti <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 13:11:29 by aaugusti       #+#    #+#                */
/*   Updated: 2020/03/30 12:04:55 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>

/*
**	Compare at most 'n' bytes of 's1' and 's2'. If a difference is encountered
**	the difference between the two chars is returned (s1 - s2). If no difference
**	is found, 0 is returned.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	while (*s1 == *s2 && n > 1 && *s1 && *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
