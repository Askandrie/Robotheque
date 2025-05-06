/**
 * @ Author: Aska
 * @ Create Time: 2025-05-06 13:21:02
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 18:34:46
 */

#ifndef PARSING_CSV_H
#define PARSING_CSV_H

#include <csv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cb_field_books(void *s, size_t len, void *data);
void cb_row_books(int c, void *data);
void cb_field_shelves(void *s, size_t len, void *data);
void cb_row_shelves(int c, void *data);

#endif