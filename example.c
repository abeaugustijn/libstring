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
