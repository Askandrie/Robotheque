/**
 * @ Author: Aska
 * @ Create Time: 2025-05-07 14:11:37
 * @ Modified by: Aska
 * @ Modified time: 2025-05-08 05:03:02
 */

#include "engine.h"
#include "color.h"
#include "lst_books.h"
#include "lst_shelves.h"
#include "series.h"
#include <stddef.h>
#include <stdio.h>

// static inline bool place_series(t_lst_books *book, t_lst_shelves *shelf)
// {
// 	while (book->is_placed == false)
// 	{
// 	}
// }

static inline void add_book(t_series *series, unsigned int *shelf_space_remain, unsigned int *count_books)
{
	if (*count_books == 0)
		print_series(series);
	printf(HGRE "Add book %3i/%3i | ", (*count_books)++, series->num);
	printf(HMAG "Sum of book size: %i\n" RESET, *shelf_space_remain += series->vol.depth);
}

static inline void vertical_count(t_lst_books *books, t_lst_shelves *shelves, unsigned int *count_books, unsigned int *shelf_width_space_remain)
{
	*count_books                           = 0;
	unsigned int shelf_height_space_remain = 0;
	while (shelf_height_space_remain < shelves->volumes.height && *count_books <= books->series.num)
	{
		add_book(&books->series, &shelf_height_space_remain, count_books);
	}
	*shelf_width_space_remain = books->series.vol.height;
}

bool engine(t_lst_books **books, t_lst_shelves **shelves)
{
	t_lst_books   *tmp_book                 = *books;
	t_lst_shelves *tmp_shelf                = *shelves;
	unsigned int   shelf_width_space_remain = 0;
	unsigned int   count_books              = 0;

	while (!check_lst_books_is_placed(*books) || !check_lst_shelves_is_full(*shelves))
	{
		add_book(&tmp_book->series, &shelf_width_space_remain, &count_books);
		if (count_books * tmp_book->series.vol.depth > tmp_book->series.vol.height)
		{
			// unsigned short tmp_max_height = tmp_shelf->volumes.height / tmp_book->series.vol.depth;
			if (tmp_book->series.num > count_books && tmp_book->series.vol.height + shelf_width_space_remain < tmp_shelf->volumes.height)
				vertical_count(tmp_book, tmp_shelf, &count_books, &shelf_width_space_remain);
		}
		if (shelf_width_space_remain > tmp_shelf->volumes.width)
		{
			printf("Shelf %s is full\n", tmp_shelf->shelf_name);
			tmp_shelf->is_full = true;
			tmp_shelf          = tmp_shelf->next;
			if (tmp_shelf == NULL)
				break;
			shelf_width_space_remain = 0;
		}
		if (count_books > tmp_book->series.num)
		{
			printf("Book %s is placed\n", tmp_book->series.name);
			tmp_book->is_placed = true;
			tmp_book            = tmp_book->next;
			if (tmp_book == NULL)
				break;
			count_books = 0;
		}
	}
	return true;
}