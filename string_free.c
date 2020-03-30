/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:01:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 10:36:28 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <stdlib.h>

/*
**	Free the string. This will also set all of the values in the string struct
**	to 0 to make sure no freed pointers will be used.
**
**	@param {t_string *} str
*/

void	string_free(t_string *str)
{
	free(str->str);
	ft_bzero(str, sizeof(t_string));
}
