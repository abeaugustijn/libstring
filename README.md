# libstring
_Make strings fun again_

⚠️ **This library is a work in progress. New functionality will still be added and bugs will be fixed. Please open an issue for any discrepancies encountered in the library.**

## Introduction
As all of us know, strings in C are an absolute pain to work with. All of the hustle with terminating, freeing and allocating the right amount of bytes can become very tedious when programming even the simplest functionality. This library aims for more useable and less tedious string manipulation, while keeping everything as efficient as possible. Of course, doing your own memory management around stings will, without a doubt, make your code more efficient, but the aim of this library is to make a compromise between effiency and usability while keeping overhead to a minimum.

## Features
libstring is not complicated. It uses a single `t_string` struct to store the necessary data to manipulate the string effectively. The struct is as follows:
```c
typedef struct  s_string {
  // The current length of the string. Does not include a '\0' char.
  size_t  len;
  
  // The capacity of the string.
  // This is the size to which the string can grow before a new allocation is necessary.
  size_t  cap;
  
  // A pointer to the block of memory in which the string itself is stored.
  // This block is always cap + 1 in size to account for the terminating character.
  char    *str
}               t_string;
```
The information in this struct should only be affected by the library functions. Manipulation of these values outside of the library functions can result in undefined behaviour.

## Compilation
The library includes a basic makefile. To compile the library for usage in an application, just use the general make command.
```
$ make
...
$ ls libstring.a
libstring.a
```
Some tests are included in the library aswell (see [test.c](test.c)). These can be compiled and executed as following.
```
$ make test
...
$ ./test
```
To debug the library, the `DEBUG` environment variable needs to be set to `1`. This disables optimization and includes debugging symbols in the library aswell as the test executable.
```
$ DEBUG=1 make re
```

## Example
A simple workflow with the library:
```c
#include "libstring.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int			i;
	t_string	arguments;

	// Create a new string from the given string.
	if (string_from("Args: ", &arguments))	
		return (1); // Return if the allocation of the new string failed.
	i = 0;
	while (i < argc)
	{
		// Push the current argument to the end of the string
		if (string_push(&arguments, argv[i]))
			return (1);
		// Add a ", " to seperate the arguments.
		if (i + 1 < argc)
			if (string_push(&arguments, ", "))
				return (1);
		i++;
	}
	// Replace all occurences of "foo" with "bar".
	string_replace(&arguments, "foo", "bar");

	// Add a newline to the end
	string_push(&arguments, "\n");

	// Shrink the string to the minimum size required, so no excess memory is
	// allocated.
	string_shrink(&arguments);

	// Print the string by accessing the 'str' element of the argument struct.
	printf("%s", arguments.str);

	// Free the string
	string_free(&arguments);
}
```
As you can see, you don't need to worry about memory management anymore! Just make sure you free the string when you are done with it and everything will be fine.

## Functions
These are the basic functions used to manipulate a string.
```c
void
string_delete(t_string *str, size_t index, size_t len);

void
string_free(t_string *str);

bool
string_from(char *from, t_string *str);

bool
string_init(size_t init_cap, char *init_value, t_string *result);

bool
string_insert(t_string *str, size_t index, char *insert);

bool
string_join(t_string arr[], size_t arrlen, char *seperator, t_string *result);

bool
string_join_consume(t_string arr[], size_t arrlen, char *seperator, t_string *result);

bool
string_join_std(char *arr[], size_t arrlen, char *seperator, t_string *result);

bool
string_join_std_consume(char *arr[], size_t arrlen, char *seperator, t_string *result);

bool
string_push(t_string *str, char *to_push);

bool
string_replace(t_string *str, char *to_find, char *replace);

bool
string_resize_cap(t_string *str, size_t cap);

bool
string_resize(t_string *str);

bool
string_shrink(t_string *str);

bool
string_split(char *to_split, char *split_chars, t_string **result, size_t *result_size);
```

[More extensive documentation](libstring.h)

## Contributions
Feel free to open an issue if you encounter any problems with the library. Pull requests are highly apprecieated as well.

## TODOs
These are some functions which will likely be added in the near future.
* string_dup - duplicate a string
* string_index_of - find the index of a substring
* string_to_low - convert all characters to lowercase
* string_to_up - convert all characters to uppercase
* string_trim - remove all whitespace surrounding the string
