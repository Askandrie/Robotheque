/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 20:29:33
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 18:37:07
 */

#ifndef FILE_LOAD_H
#define FILE_LOAD_H

#include "lst_books.h"
#include "lst_shelves.h"
#include "parsing_csv.h"
#include <csv.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

bool file_load_books(const char *path);
bool file_load_shelves(const char *path);

#endif