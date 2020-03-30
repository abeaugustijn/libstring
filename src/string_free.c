/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <aaugusti@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 09:01:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 12:29:32 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libstring.h>
#include <stdlib.h>
#include <utils.h>

void	string_free(t_string *str)
{
	free(str->str);
	ft_bzero(str, sizeof(t_string));
}
