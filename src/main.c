/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 03:08:10
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 23:03:10
 */

#include "check_arg.h"
// #include "data.h"
#include "engine.h"
#include "file_load.h"
#include "lst_books.h"
#include "lst_shelves.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_lst_books   *books = NULL;
	t_lst_shelves *shelf = NULL;
	bool           exit_code;

	exit_code = check_entry_arg(ac, av);
	if (exit_code == true)
		exit_code = file_load_books(av[1], &books);
	if (exit_code == true)
		exit_code = file_load_shelves(av[2], &shelf);

	engine(&books, &shelf);

	delete_all_lst_books(&books);
	delete_all_lst_shelves(&shelf);

	return 0;
}
