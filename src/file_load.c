/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 20:29:22
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 03:08:24
 */

#include "file_load.h"
#include "lst_books.h"
#include <strings.h>

static bool is_folder(const char *path)
{
	struct stat sb;
	if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
		return true;
	return false;
}

static bool open_file(FILE **fp, const char *path)
{
	if (is_folder(path))
	{
		fprintf(stderr, "Error: %s is a directory\n", path);
		return false;
	}
	*fp = fopen(path, "r");
	if (*fp == NULL)
	{
		fprintf(stderr, "Error: cannot open file \"%s\"\n", path);
		return false;
	}
	return true;
}

static bool close_file(FILE *fp)
{
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error: Failed to close file\n");
		return false;
	}
	return true;
}

static bool file_to_csv_parsing_books(FILE *fp, t_lst_books **books)
{
	struct csv_parser p;
	char              buf[1024];
	t_csv_buf         csv_buf;
	size_t            bytes;

	csv_init(&p, 0);
	bzero(&csv_buf, sizeof csv_buf);
	csv_buf.books = books;
	csv_set_space_func(&p, NULL);
	csv_set_delim(&p, ',');
	csv_set_quote(&p, '"');
	csv_set_term_func(&p, NULL);
	while ((bytes = fread(buf, 1, sizeof buf, fp)) > 0)
	{
		csv_parse(&p, buf, bytes, cb_field_books, cb_row_books, &csv_buf);
	}
	csv_fini(&p, cb_field_books, cb_row_books, &csv_buf);
	csv_free(&p);
	return true;
}

bool file_load_books(const char *path, t_lst_books **books)
{
	FILE *fp;
	if (!open_file(&fp, path))
		return false;
	bool ok = file_to_csv_parsing_books(fp, books) && close_file(fp);
	return ok;
}

static bool file_to_csv_parsing_shelves(FILE *fp, t_lst_shelves **shelf)
{
	struct csv_parser p;
	char              buf[1024];
	t_csv_buf         csv_buf;
	size_t            bytes;

	csv_init(&p, 0);
	bzero(&csv_buf, sizeof csv_buf);
	csv_buf.shelves = shelf;
	csv_set_space_func(&p, NULL);
	csv_set_delim(&p, ',');
	csv_set_quote(&p, '"');
	csv_set_term_func(&p, NULL);
	while ((bytes = fread(buf, 1, sizeof buf, fp)) > 0)
	{
		csv_parse(&p, buf, bytes, cb_field_shelves, cb_row_shelves, &csv_buf);
	}
	csv_fini(&p, cb_field_shelves, cb_row_shelves, &csv_buf);
	csv_free(&p);
	return true;
}

bool file_load_shelves(const char *path, t_lst_shelves **shelf)
{
	FILE *fp;
	if (!open_file(&fp, path))
		return false;
	bool ok = file_to_csv_parsing_shelves(fp, shelf) && close_file(fp);
	return ok;
}