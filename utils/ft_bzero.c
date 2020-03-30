/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:02:53 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 09:03:42 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libstring.h"

void	ft_bzero(void *mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)mem)[i] = 0;
		i++;
	}
}
