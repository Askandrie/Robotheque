/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 00:55:26
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 17:38:22
 */

#ifndef LST_BOOKS_H
#define LST_BOOKS_H

#include "series.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_lst_books
{
	t_series            series;
	struct s_lst_books *next;
} t_lst_books;

t_lst_books *insert_lst_books(t_lst_books **head, t_series series);
void         delete_node_lst_books(t_lst_books **head, t_lst_books *del_node);
void         delete_all_lst_books(t_lst_books **head);
void         print_lst_books(t_lst_books *head);

#endif