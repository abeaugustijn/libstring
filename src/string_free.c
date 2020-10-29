/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_free.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:06:26 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/10/29 14:06:26 by aaugusti      ########   odam.nl         */
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
