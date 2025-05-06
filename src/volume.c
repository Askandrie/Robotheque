/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 03:32:59
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 11:53:33
 */

#include "volume.h"
#include "color.h"
#include <stdio.h>

t_vol3us create_vol3us(const unsigned short height, const unsigned short width, const unsigned short depth)
{
	t_vol3us vol = {height, width, depth};

	return (vol);
}

int get_volume(const t_vol3us vol)
{
	return (vol.depth * vol.height * vol.width);
}

int get_surface_hw(const t_vol3us vol)
{
	return (vol.height * vol.width);
}

int get_surface_hd(const t_vol3us vol)
{
	return (vol.height * vol.depth);
}

int get_surface_wd(const t_vol3us vol)
{
	return (vol.width * vol.depth);
}

void print_vol3us(const t_vol3us vol)
{
	printf(R1G4B3 "Height	: " BOLD WHI "%3hu mm |\n" RESET, vol.height);
	printf(R1G4B3 "Width	: " BOLD WHI "%3hu mm |" R1G4B3 " Volume	: " BOLD WHI "%d mm³\n" RESET, vol.width, get_volume(vol));
	printf(R1G4B3 "Depth	: " BOLD WHI "%3hu mm |\n" RESET, vol.depth);
}