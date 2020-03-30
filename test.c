/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:32:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/30 12:21:13 by aaugusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstring.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	test_simple(void)
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
	string_free(&str);
}

static void	test_delete(void)
{
	t_string	str;

	assert(!string_init(10, "12345", &str));
	string_delete(&str, 2, 2);
	assert(!strcmp(str.str, "125"));
	assert(str.len == 3);
	string_free(&str);
	assert(!string_init(10, "abcdefghij", &str));
	string_delete(&str, 8, 10);
	assert(!strcmp(str.str, "abcdefgh"));
	assert(str.len == 8);
	string_free(&str);
	assert(!string_init(10, "abcdefghij", &str));
	string_delete(&str, 8, 0);
	assert(!strcmp(str.str, "abcdefghij"));
	assert(str.len == 10);
	string_free(&str);
	assert(!string_init(10, "abd", &str));
	string_delete(&str, 0, 1);
	assert(!strcmp(str.str, "bd"));
	assert(str.len == 2);
	string_free(&str);
}

static void	test_insert(void)
{
	t_string	str;

	assert(!string_init(5, "test", &str));
	string_insert(&str, 1, "abc");
	assert(str.len == 7);
	assert(str.cap == 10);
	assert(!strcmp(str.str, "tabcest"));
	string_insert(&str, 4, "def");
	assert(str.len == 10);
	assert(str.cap == 10);
	assert(!strcmp(str.str, "tabcdefest"));
	string_insert(&str, 12, "jalalala");
	assert(str.len == 10);
	assert(str.cap == 10);
	assert(!strcmp(str.str, "tabcdefest"));
	string_insert(&str, 3, "");
	assert(str.len == 10);
	assert(str.cap == 10);
	assert(!strcmp(str.str, "tabcdefest"));
	string_insert(&str, strlen(str.str), " bar");
	assert(str.len == 14);
	assert(str.cap == 20);
	assert(!strcmp(str.str, "tabcdefest bar"));
	string_free(&str);
}

static void	test_replace(void)
{
	t_string	str;
	size_t		cap;

	assert(!string_from("xxxxtestxxxxtesxxtests", &str));
	cap = strlen("xxxxtestxxxxtesxxtests");
	assert(str.len == cap);
	assert(str.cap == cap);
	assert(!string_replace(&str, "test", "abc"));
	assert(!strcmp(str.str, "xxxxabcxxxxtesxxabcs"));
	assert(str.len == strlen("xxxxabcxxxxtesxxabcs"));
	assert(str.cap == cap);
	assert(!string_replace(&str, "x", ""));
	assert(!strcmp(str.str, "abctesabcs"));
	assert(str.len == strlen("abctesabcs"));
	assert(str.cap == cap);
	assert(!string_push(&str, "oooooooxxxxoooooooooooo"));
	assert(!strcmp(str.str, "abctesabcsoooooooxxxxoooooooooooo"));
	assert(str.len == strlen("abctesabcs") + strlen("oooooooxxxxoooooooooooo"));
	cap *= 2;
	assert(str.cap == cap);
	assert(!string_replace(&str, "x", "abcdefg"));
	assert(!strcmp(str.str,
		"abctesabcsoooooooabcdefgabcdefgabcdefgabcdefgoooooooooooo"));
	cap *= 2;
	assert(str.cap == cap);
	assert(str.len ==
		strlen("abctesabcsoooooooabcdefgabcdefgabcdefgabcdefgoooooooooooo"));
	string_free(&str);
}

static void	test_replace_end(void)
{
	t_string	str;

	assert(!string_from("test foo", &str));
	assert(!string_replace(&str, "foo", "bar"));
	assert(!strcmp(str.str, "test bar"));
	assert(str.len == 8);
	assert(str.cap == 8);
}

typedef struct	s_test {
	char	*name;
	void	(*func)(void);
}				t_test;

t_test	g_tests[] = {
	{ "simple",			test_simple },
	{ "delete",			test_delete },
	{ "insert",			test_insert },
	{ "replace",		test_replace },
	{ "replace_end",	test_replace_end },
	{ NULL,			NULL },
};

int	main(void)
{
	size_t	i;

	i = 0;
	while (g_tests[i].name)
	{
		printf("Testing %s\n", g_tests[i].name);
		g_tests[i].func();
		printf("\tPassed.\n\n");
		i++;
	}
}
