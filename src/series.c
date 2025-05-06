/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 18:11:08
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 16:52:41
 */

#include "series.h"
#include "volume.h"
#include <stdio.h>
#include <string.h>

void init_series(t_series *s, char *title, t_vol3us vol)
{
	memcpy(&s->vol, &vol, sizeof vol);
	s->title = title;
	s->num   = 0;
}

void print_series(t_series *s)
{
	if (s == NULL)
		return;
	printf("Title: %s | Num: %d\n", s->title, s->num);
	print_vol3us(s->vol);
}