/**
 * @ Author: Aska
 * @ Create Time: 2025-05-05 03:26:57
 * @ Modified by: Aska
 * @ Modified time: 2025-05-06 11:56:11
 */

#ifndef VOLUME_H
#define VOLUME_H

/**
 * 3D volume in millimeters.
 * Tous les champs sont const après initialisation.
 */
typedef struct s_vol3us
{
	const unsigned short width;  /**< Largeur en mm */
	const unsigned short height; /**< Hauteur en mm */
	const unsigned short depth;  /**< Profondeur en mm */
} t_vol3us;

/**
 * Crée un volume 3D.
 * @param height Hauteur en mm
 * @param width  Largeur en mm
 * @param depth  Profondeur en mm
 * @return t_vol3us
 */
t_vol3us create_vol3us(const unsigned short height, const unsigned short width, const unsigned short depth);

/** Retourne le volume (mm³). */
int get_volume(const t_vol3us vol);

/** Surface largeur×hauteur (mm²). */
int get_surface_hw(const t_vol3us vol);

/** Surface hauteur×profondeur (mm²). */
int get_surface_hd(const t_vol3us vol);

/** Surface largeur×profondeur (mm²). */
int get_surface_wd(const t_vol3us vol);

/** Affiche tous les attributs et le volume. */
void print_vol3us(const t_vol3us vol);

#endif /* VOLUME_H */