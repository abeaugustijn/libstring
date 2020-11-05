/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libstring.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aaugusti <aaugusti@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:08:27 by aaugusti      #+#    #+#                 */
/*   Updated: 2020/11/05 14:24:48 by aaugusti      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRING_H
# define LIBSTRING_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

/*
**	The initial capacity of the result string returned by the 'join' functions.
*/

# ifndef JOIN_INIT_CAP
#  define JOIN_INIT_CAP 100
# endif

typedef struct	s_string {
	size_t	len;
	size_t	cap;
	char	*str;
}				t_string;

/*
**	Delete a subsection of the string. This will not resize the string to fit
**	the shorter string. If len == 0 or if the index is invalid, this function
**	will not do anything to the string. The new length of the string will be
**	set to the result.
**
**	@param {t_string *} str
**	@param {size_t} index - the index of the first char to be deleted
**	@param {size_t} len - the amount of characters (including the one on index)
**		to be deleted.
*/

void			string_delete(t_string *str, size_t index, size_t len);

/*
**	Free the string. This will also set all of the values in the string struct
**	to 0 to make sure no freed pointers will be used.
**
**	@param {t_string *} str
*/

void			string_free(t_string *str);

/*
**	Create a new string which inherits the given string. The len and cap fields
**	will be set to the length of the new string. New memory will be allocated
**	to store the new string.
**
**	@param {char *} from
**	@param {t_string *} str - to store the resulting struct
**
**	@return {bool} - true if the allocation failed
*/

bool			string_from(char *from, t_string *str);

/*
**	Create a new string which inherits a subsection of the given string. New
**	memory will be allocated for the string.
**
**	@param {char *} from
**	@param {size_t} start - index of the first character of the new string
**	@param {size_t} len - the length of the new string
**	@param {t_string *} result
**
**	@return {bool} - true is the allocation failed or an invalid range is given
*/

bool			string_from_range(char *from, size_t start, size_t len,
					t_string *str);

/*
**	Initialize a new string. An initial string (init_value) can be given. If the
**	length of this string exceeds the init_cap, true will be returned and
**	nothing will happen to the result string.
**
**	@param {size_t} init_cap - the amount of bytes which will be allocated in
**		this function.
**	@param {char *} init_value - the string to store at first. NULL if the new
**		string should be empty.
**	@param {t_string *} result
**
**	@return {bool} - true if the allocation failed
*/

bool			string_init(size_t init_cap, char *init_value,
					t_string *result);

/*
**	Insert a substring into an existing string. This will only allocate new
**	memory if the length of the new string exceeds the strings current
**	capacity. If insert is empty or if the index is invalid, false will be
**	returned and nothing will happen.
**
**	@param {t_string *} str
**	@param {size_t} index - the index in the string at which the substring will
**		be inserted. In the result, this value will be the index of the first
**		character of the substring.
**	@param {char *} insert - the string to insert
**
**	@return {bool} - true if the allocation fails
*/

bool			string_insert(t_string *str, size_t index, char *insert);

/*
**	Join an array of strings together into a single string. The strings will be
**	seperated by the seperator string which is given. Initially, the result
**	string will have a capacity defined by the JOIN_INIT_CAP compile constant.
**	At the end of the joining the result string will be shrunk down to minimal
**	size. The strings in the array will not be affected or freed in any way.
**
**	@param {t_string[]} arr - an array of t_strings
**	@param {size_t} arrlen - the amount of strings in the array
**	@param {char *} seperator
**	@param {t_string *} result
**
**	@return {bool} - true if an allocation failed
*/

bool			string_join(t_string arr[], size_t arrlen, char *seperator,
					t_string *result);

/*
**	Join an array of strings together into a single string. The strings will be
**	seperated by the seperator string which is given. Initially, the result
**	string will have a capacity defined by the JOIN_INIT_CAP compile constant.
**	At the end of the joining the result string will be shrunk down to minimal
**	size. The strings in the array will be freed, as well as the array itself.
**
**	@param {t_string[]} arr - an array of t_strings
**	@param {size_t} arrlen - the amount of strings in the array
**	@param {char *} seperator
**	@param {t_string *} result
**
**	@return {bool} - true if an allocation failed
*/

bool			string_join_consume(t_string arr[], size_t arrlen,
					char *seperator, t_string *result);

/*
**	Join an array of strings together into a single string. The strings will be
**	seperated by the seperator string which is given. Initially, the result
**	string will have a capacity defined by the JOIN_INIT_CAP compile constant.
**	At the end of the joining the result string will be shrunk down to minimal
**	size. The strings in the array will not be affected or freed in any way.
**
**	@param {char *[]} arr - an array of strings
**	@param {size_t} arrlen - the amount of strings in the array
**	@param {char *} seperator
**	@param {t_string *} result
**
**	@return {bool} - true if an allocation failed
*/

bool			string_join_std(char *arr[], size_t arrlen, char *seperator,
			t_string *result);

/*
**	Join an array of strings together into a single string. The strings will be
**	seperated by the seperator string which is given. Initially, the result
**	string will have a capacity defined by the JOIN_INIT_CAP compile constant.
**	At the end of the joining the result string will be shrunk down to minimal
**	size. The strings in the array will be freed, as well as the array itself.
**
**	@param {t_string[]} arr - an array of t_strings
**	@param {size_t} arrlen - the amount of strings in the array
**	@param {char *} seperator
**	@param {t_string *} result
**
**	@return {bool} - true if an allocation failed
*/

bool			string_join_std_consume(char *arr[], size_t arrlen,
					char *seperator, t_string *result);

/*
**	Push a string of characters to the end of the existing string. If the
**	capacity allows it, no new memory will be allocated. Otherwise the function
**	allocates new memory until the new string will fit.
**
**	@param {t_string *} str
**	@param {char *} to_push
**
**	@return {bool} - true if the allocation failed
*/

bool			string_push(t_string *str, char *to_push);

/*
**	Push a single character to the end of the string. If there is no space left
**	in the string buffer, new memory will be allocated.
**
**	@param {t_string *} str
**	@param {char} to_push
**
**	@return {bool} - true if the allocation failed
*/

bool			string_pushc(t_string *str, char to_push);

/*
**	Search a string for a substring and replace it with another string.
**
**	@param {t_string *} str
**	@param {char *} to_find - the string to replace
**	@param {char *} replace - the string to replace it with.
**
**	@return {bool} true if an allocation failed
*/

bool			string_replace(t_string *str, char *to_find, char *replace);

/*
**	Resets a string. This basically means setting the size to 0. Optionally,
**	the string can be cleared.
**
**	@param {t_string *} str
**	@param {bool} clear
*/

void			string_reset(t_string *str, bool clear);

/*
**	Resize a string so the capacity will have a minimum value of the given
**	capacity. This is more efficient to use than string_resize if the desired
**	capacity is already known at the time of calling, because only one
**	allocation and strcpy are necessary for the operation. This will still
**	keep multiplying the current capacity with 2, like the normal string_resize
**	will.
**
**	@param {t_string *} str
**	@param {size_t} cap
**
**	@return {bool} - true if the allocation failed
*/

bool			string_resize_cap(t_string *str, size_t cap);

/*
**	Double the capacity of an existing string. This will allocate new memory,
**	copy the contents of the old string to the new string, set the str element
**	of the string struct to the new memory and free the old string.
**
**	@param {t_string *} str
**
**	@return {bool} - true if the allocation failed
*/

bool			string_resize(t_string *str);

/*
**	Shrink the size of a string down to the minimum amount of bytes necessary
**	to store the string.
**
**	@param {t_string *} str
**
**	@return {bool} - true if the allocation failed
*/

bool			string_shrink(t_string *str);

/*
**	Split a string on given characters. The result will be an array of strings.
**	If any allocation fails, all allocated memory will be freed and true will
**	be returned.
**
**	@param {char *} to_split - should not be empty. If empty, result will be
**		NULL returned and result_size will bet set to 0.
**	@param {char *} split_chars - a string of characters defining the
**		characters on which the string will be splitted.
**	@param {t_string **} result
**	@param {size_t} result_size - the amount of elements in the resulting array
**
**	@return {bool} true if an allocation failed
*/

bool			string_split(char *to_split, char *split_chars,
					t_string **result, size_t *result_size);

/*
**	Convert a t_string array to a NULL-terminated char* array. This does not
**	copy the actual strings itself. The members of the resulting array will be
**	the same as the `str` elements of the t_string array.
**
**	@param {size_t} len - The amount of strings in the given array
**	@param {t_string[]} array
**
**	@return {char *[]} - NULL if the allocation failed
*/

char			**string_to_array(size_t len, t_string array[]);

#endif
