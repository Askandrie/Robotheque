/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 00:55:26
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 20:14:11
 */

#ifndef LST_SHELVES_H
#define LST_SHELVES_H

#include "series.h"
#include "volume.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_lst_shelves
{
	char                 *shelf_name;
	t_vol3us              volumes;
	bool                  is_full;
	struct s_lst_shelves *next;
} t_lst_shelves;

t_lst_shelves *insert_lst_shelves(t_lst_shelves **head, char *shelf_name, t_vol3us volumes);
void           delete_node_lst_shelves(t_lst_shelves **head, t_lst_shelves *del_node);
void           delete_all_lst_shelves(t_lst_shelves **head);
void           print_lst_shelves(t_lst_shelves *head);
bool           check_lst_shelves_is_full(t_lst_shelves *head);

#endif