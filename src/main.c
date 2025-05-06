/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 03:08:10
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 18:46:00
 */

#include "check_arg.h"
#include "data.h"
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
		exit_code = file_load_books(av[1]);
	if (exit_code == true)
		exit_code = file_load_shelves(av[2]);

	print_lst_shelves(shelf);
	print_lst_books(books);
	delete_all_lst_books(&books);
	delete_all_lst_shelves(&shelf);

	return 0;
}
