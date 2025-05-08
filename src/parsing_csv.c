/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 13:20:46
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 23:49:34
 */

#include "parsing_csv.h"
#include "color.h"
#include "lst_books.h"
#include "lst_shelves.h"
#include "series.h"
#include "volume.h"
#include <errno.h>
#include <limits.h>

static inline char *get_field(char *s, size_t len)
{
	char *field = (char *)malloc(len + 1);
	if (field == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return NULL;
	}
	strncpy(field, s, len);
	field[len] = '\0';
	return field;
}

static inline unsigned short char_to_ushort(const char *s)
{
	if (!s)
	{
		errno = EINVAL; // pointeur invalide
		return 0;
	}

	char *endptr;
	errno = 0; // nettoyer errno avant l’appel

	/* strtoul parce qu’on veut un entier non signé */
	unsigned long val = strtoul(s, &endptr, 10);

	/* 1) pas de caractère converti ? */
	if (endptr == s)
	{
		errno = EINVAL; // « pas de nombre au début de s »
		return 0;
	}

	/* 2) reste de chaîne non vide ? */
	if (*endptr != '\0')
	{
		errno = EINVAL; // « texte après le nombre »
		return 0;
	}

	/* 3) overflow / underflow ou trop grand pour unsigned short */
	if (errno == ERANGE || val > USHRT_MAX)
	{
		errno = ERANGE;
		return 0;
	}

	/* tout est OK */
	return (unsigned short)val;
}

void cb_field_books(void *s, size_t len, void *data)
{
	t_csv_buf *csv_buf = (t_csv_buf *)data;

	switch (csv_buf->idx)
	{
		case 0:
			csv_buf->name = get_field(s, len);
			break;
		case 1:
			csv_buf->height = get_field(s, len);
			break;
		case 2:
			csv_buf->width = get_field(s, len);
			break;
		case 3:
			csv_buf->depth = get_field(s, len);
			break;
		case 4:
			csv_buf->sum_of_book = get_field(s, len);
			break;
	}
	csv_buf->idx++;
}

void cb_row_books(int c, void *data)
{
	t_series             series;
	t_csv_buf           *csv_buf     = (t_csv_buf *)data;
	static int           idx         = 0;
	const unsigned short height      = char_to_ushort(csv_buf->height);
	const unsigned short width       = char_to_ushort(csv_buf->width);
	const unsigned short depth       = char_to_ushort(csv_buf->depth);
	const int            sum_of_book = char_to_ushort(csv_buf->sum_of_book);

	free(csv_buf->height);
	free(csv_buf->width);
	free(csv_buf->depth);
	free(csv_buf->sum_of_book);
	if (csv_buf->idx == 5)
	{
		t_vol3us vol = {width, height, depth};
		init_series(&series, csv_buf->name, vol, sum_of_book);
		t_lst_books *new_book = insert_lst_books(csv_buf->books, series, idx++);
		if (new_book == NULL)
		{
			fprintf(stderr, "Error: Failed to insert book\n");
			return;
		}
	}
	csv_buf->idx = 0;
	(void)c;
}

void cb_field_shelves(void *s, size_t len, void *data)
{
	t_csv_buf *csv_buf = (t_csv_buf *)data;

	switch (csv_buf->idx)
	{
		case 0:
			csv_buf->name = get_field(s, len);
			break;
		case 1:
			csv_buf->height = get_field(s, len);
			break;
		case 2:
			csv_buf->width = get_field(s, len);
			break;
		case 3:
			csv_buf->depth = get_field(s, len);
			break;
	}
	csv_buf->idx++;
}

void cb_row_shelves(int c, void *data)
{
	t_csv_buf           *csv_buf = (t_csv_buf *)data;
	const unsigned short height  = char_to_ushort(csv_buf->height);
	const unsigned short width   = char_to_ushort(csv_buf->width);
	const unsigned short depth   = char_to_ushort(csv_buf->depth);

	free(csv_buf->height);
	free(csv_buf->width);
	free(csv_buf->depth);
	if (csv_buf->idx == 4)
	{
		t_vol3us       vol       = {height, width, depth};
		t_lst_shelves *new_shelf = insert_lst_shelves(csv_buf->shelves, csv_buf->name, vol);
		if (new_shelf == NULL)
		{
			fprintf(stderr, "Error: Failed to insert shelf\n");
			return;
		}
	}
	csv_buf->idx = 0;
	(void)c;
}