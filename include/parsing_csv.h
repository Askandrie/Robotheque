/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 13:21:02
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 23:37:53
 */

#ifndef PARSING_CSV_H
#define PARSING_CSV_H

#include "lst_books.h"
#include "lst_shelves.h"
#include <csv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_csv_buf
{
	char           *name;
	char           *height;
	char           *width;
	char           *depth;
	char           *sum_of_book;
	short           idx;
	t_lst_books   **books;
	t_lst_shelves **shelves;
} t_csv_buf;

void cb_field_books(void *s, size_t len, void *data);
void cb_row_books(int c, void *data);
void cb_field_shelves(void *s, size_t len, void *data);
void cb_row_shelves(int c, void *data);

#endif