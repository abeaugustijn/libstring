/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:32:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/24 23:09:52 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void	test_simple()
{
	t_string	str;

	string_init(10, NULL, &str);
	assert(str.cap == 10);
	assert(str.len == 0);
	string_push(&str, "test");
	assert(str.cap == 10);
	assert(str.len == 4);
	assert(!strcmp(str.str, "test"));
	string_push(&str, "123456");
	assert(str.cap == 10);
	assert(str.len == 10);
	assert(!strcmp(str.str, "test123456"));
	string_push(&str, "a");
	assert(str.cap == 20);
	assert(str.len == 11);
	assert(!strcmp(str.str, "test123456a"));
	string_shrink(&str);
	assert(str.cap == 11);
	assert(str.len == 11);
	assert(!strcmp(str.str, "test123456a"));
	free(str.str);
}

int	main(void)
{
	test_simple();
}
