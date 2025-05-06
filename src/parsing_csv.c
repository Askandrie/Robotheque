/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 13:20:46
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 18:38:46
 */

#include "parsing_csv.h"
#include "color.h"

void cb_field_books(void *s, size_t len, void *data)
{
	(void)data;
	fprintf(stdout, RED);
	fwrite(s, 1, len, stdout);
	putchar('|');
}

void cb_row_books(int c, void *data)
{
	(void)data;
	(void)c;
	putchar('\n');
}

void cb_field_shelves(void *s, size_t len, void *data)
{
	(void)data;
	fprintf(stdout, BLU);
	fwrite(s, 1, len, stdout);
	putchar('|');
}

void cb_row_shelves(int c, void *data)
{
	(void)data;
	(void)c;
	putchar('\n');
}