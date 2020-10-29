/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:07:47 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:07:47 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <utils.h>

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
