/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:01:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 11:59:58 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include "utils/utils.h"
#include <stdlib.h>

void	string_free(t_string *str)
{
	free(str->str);
	ft_bzero(str, sizeof(t_string));
}
