/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:58:06 by aaugusti          #+#    #+#             */
/*   Updated: 2020/04/08 19:58:06 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <utils.h>

/*
**	The safer version of memcpy. Safely copies 'n' bytes from 'src' to 'dest'
**	taking into account they could overlap.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((unsigned char*)dest)[i - 1] = ((unsigned char*)src)[i - 1];
			i--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
