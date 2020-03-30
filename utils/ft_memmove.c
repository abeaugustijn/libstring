/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: abe <abe@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 20:17:50 by abe            #+#    #+#                */
/*   Updated: 2020/03/30 09:51:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../libstring.h"

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
