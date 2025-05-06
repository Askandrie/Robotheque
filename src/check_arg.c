/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 20:27:31
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 00:06:02
 */

#include "check_arg.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

static inline bool validate_arg_count(int ac)
{
	if (ac < ARGUMENTS + 1)
	{
		fprintf(stderr, "error: too few arguments\n");
		return false;
	}
	if (ac > ARGUMENTS + 1)
	{
		fprintf(stderr, "error: too many arguments\n");
		return false;
	}
	return true;
}

static inline const char *get_basename(const char *path)
{
	const char *name = strrchr(path, '/');
	return name ? name + 1 : path;
}

static inline const char *strip_leading_dots(const char *name)
{
	while (*name == '.')
		name++;
	return name;
}

static inline bool has_extension(const char *name, const char *ext)
{
	const char *dot = strrchr(name, '.');
	if (!dot || strcmp(dot, ext) != 0)
	{
		fprintf(stderr, "error: \"%s\" does not have \"%s\" extension\n", name, ext);
		return false;
	}
	return true;
}

bool check_entry_arg(int ac, char **av)
{
	if (!validate_arg_count(ac))
		return false;

	const char *basename = get_basename(av[1]);
	basename             = strip_leading_dots(basename);

	if (!has_extension(basename, EXTENSION_FILE))
		return false;

	return true;
}