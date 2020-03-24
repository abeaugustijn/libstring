/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:56:40 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 22:57:21 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stddef.h>

void	*string_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_cpy;

	if (!dst && !src)
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
