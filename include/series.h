/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 17:13:07
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 16:53:23
 */

#ifndef SERIES_H
#define SERIES_H

#include "volume.h"

typedef struct s_series
{
	char    *title;
	t_vol3us vol;
	int      num;
} t_series;

void init_series(t_series *s, char *title, t_vol3us vol);
void print_series(t_series *s);

#endif