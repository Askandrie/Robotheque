/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 12:58:00
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 13:04:26
 */

#include "data.h"
#include "lst_books.h"

int get_sum_of_books(t_lst_books *books)
{
	int          sum     = 0;
	t_lst_books *current = books;

	while (current != NULL)
	{
		sum++;
		current = current->next;
	}
	return sum;
}