/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 20:27:43
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 00:05:34
 */

#ifndef CHECK_ARG_H
#define CHECK_ARG_H

#include <stdbool.h>

#define EXTENSION_FILE ".csv"
#define ARGUMENTS 2

bool check_entry_arg(int ac, char **av);

#endif