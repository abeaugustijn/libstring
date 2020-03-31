/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:32:47 by aaugusti          #+#    #+#             */
/*   Updated: 2020/03/31 12:53:03 by aaugusti         ###   ########.fr       */
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
	string_pushc(&str, 'b');
	assert(str.cap == 20);
	assert(str.len == 12);
	assert(!strcmp(str.str, "test123456ab"));
	string_shrink(&str);
	assert(str.cap == 12);
	assert(str.len == 12);
	assert(!strcmp(str.str, "test123456ab"));
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
	string_free(&str);
}

static void	test_join(void)
{
	t_string	*arr;
	t_string	str;

	arr = malloc(3 * sizeof(t_string));
	assert(arr);
	assert(!string_from("test", &arr[0]));
	assert(!string_from("foo", &arr[1]));
	assert(!string_from("bar", &arr[2]));
	assert(!string_join(arr, 3, ", ", &str));
	assert(str.len == 14);
	assert(str.len == str.cap);
	assert(!strcmp(str.str, "test, foo, bar"));
	string_free(&str);
	assert(!string_join(arr, 3, "", &str));
	assert(str.len == 10);
	assert(str.len == str.cap);
	assert(!strcmp(str.str, "testfoobar"));
	string_free(&str);
	assert(!string_join_consume(arr, 3, ".", &str));
	assert(str.len == 12);
	assert(str.len == str.cap);
	assert(!strcmp(str.str, "test.foo.bar"));
	string_free(&str);
}

static void	test_from_range(void)
{
	t_string	str;
	char		*test_str;

	test_str = "this is a test!!";
	assert(!string_from_range(test_str, 0, 4, &str));
	assert(str.len == 4);
	assert(str.cap == 4);
	assert(!strcmp(str.str, "this"));
	string_free(&str);
	assert(!string_from_range(test_str, 5, 5, &str));
	assert(str.len == 5);
	assert(str.cap == 5);
	assert(!strcmp(str.str, "is a "));
	string_free(&str);
	assert(!string_from_range(test_str, 5, 500, &str));
	assert(str.len == 11);
	assert(str.cap == 11);
	assert(!strcmp(str.str, "is a test!!"));
	string_free(&str);
	assert(string_from_range(test_str, 500, 5, &str));
}

static void test_split_free(t_string *arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i < arr_size)
	{
		string_free(&arr[i]);
		i++;
	}
	free(arr);
}

static void	test_split(void)
{
	char		*to_split;
	t_string	*result;
	size_t		result_size;

	to_split = "   test abc     ,., def ,   .x";
	assert(!string_split(to_split, " ,.", &result, &result_size));
	assert(result_size == 4);
	assert(!strcmp(result[0].str, "test"));
	assert(!strcmp(result[1].str, "abc"));
	assert(!strcmp(result[2].str, "def"));
	assert(!strcmp(result[3].str, "x"));
	test_split_free(result, result_size);

	to_split = "test";
	assert(!string_split(to_split, " ,.", &result, &result_size));
	assert(result_size == 1);
	assert(!strcmp(result[0].str, "test"));
	test_split_free(result, result_size);

	to_split = "";
	assert(string_split(to_split, " ,.", &result, &result_size));
	assert(result_size == 0);
	assert(result == NULL);

	to_split = "123  ";
	assert(!string_split(to_split, "", &result, &result_size));
	assert(result_size == 1);
	assert(!strcmp(result[0].str, "123  "));
	test_split_free(result, result_size);

	to_split = "";
	assert(string_split(to_split, "", &result, &result_size));
	assert(result_size == 0);
	assert(result == NULL);
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
	{ "join",			test_join },
	{ "from_range",		test_from_range },
	{ "split",			test_split },
	{ NULL,				NULL },
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
