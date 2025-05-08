/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 17:13:07
 * @ Modified by: Aska
 * @ Modified time: 2025-05-07 20:19:59
 */

#ifndef SERIES_H
#define SERIES_H

#include "volume.h"

typedef struct s_series
{
	char        *name;
	unsigned int num;
	t_vol3us     vol;
} t_series;

void init_series(t_series *s, char *title, t_vol3us vol, int num);
void print_series(t_series *s);

#endif