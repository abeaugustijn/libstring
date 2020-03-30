/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 19:45:39 by abe            #+#    #+#                */
/*   Updated: 2020/03/30 12:05:05 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>

/*
**	Copy n bytes from stc to dst. The behaviour is undefined if src and
**	dst overlap or if one of both is NULL. Use memmove for safe copying of
**	overlapping sections of memory. Returns dst. If dst or src are NULL,
**	NULL is returned.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_cpy;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_cpy = dst;
	while (n > 0)
	{
		*dst_cpy = *((unsigned char *)src);
		dst_cpy++;
		src++;
		n--;
	}
	return (dst);
}
