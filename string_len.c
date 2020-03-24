/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:52:26 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 22:52:50 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"

size_t	string_len(char *str)
{
	size_t	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}
