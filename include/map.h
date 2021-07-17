/*
** EPITECH PROJECT, 2021
** map.h
** File description:
** header map
*/

#ifndef MAP_H
#define MAP_H

/////////////////////////////
////////// INCLUDE //////////
/////////////////////////////

#include <SFML/Graphics.h>
#include "gdata.h"
#include "my.h"
#include <stdlib.h>

/////////////////////////////
//////// STRUCTURE //////////
/////////////////////////////

typedef enum tmap
{
    GRASS,
    DIRT,
    ASPHALT,
    SAND,
    GRASSROAD,
    DIRTROAD,
    ASPHALTROAD,
    SANDROAD
}tmap_t;

typedef enum obs_type
{
    NOT_EXIST,
    OUT,
    FENCE,
    THREE,
    HOUSE,
    HIGH_GRASS
}obs_type_t;

typedef struct map_obs_s
{
    obs_type_t type;
    sfSprite *sprite;
    sfVector2f pos;
    struct map_obs_s *next;
}map_obs_t;

typedef struct map
{
    tmap_t texture_type;
    obs_type_t obs_type;
    sfSprite *sprite;
    sfVector2f pos;
    map_obs_t *obs;
}map_t;

typedef struct map_info
{
    int line_size;
    int cell_max;
}map_info_t;

/////////////////////////////
//////// PROTOTYPE //////////
/////////////////////////////

void map_debug(map_t **map);
map_t *debug_sprite_init(sfTexture *texture, sfIntRect rect, int dir,
                        tmap_t en);

//////// open_file.c ////////

char *open_file(char *filepath);

/////// my_putstr_error.c ////////

int my_putstr_error(char const *str);

//////// map_init.c //////////

int case_nbr(char *buffer);
map_t **map_init(char *buffer, sfTexture **textures, map_info_t *map_info);

//////// map_ground.c //////////

map_t *sprite_map_init(sfTexture *texture, float angle);
map_obs_t *sprite_obs_init(sfTexture *texture, sfVector2f pos, obs_type_t obs);

//////// parsing_map.c ////////////

map_t *parsing_map(sfTexture **textures, char *buffer, int i, map_t *map);

//////// list_obs_init.c //////////

map_obs_t *list_obs_init(map_t **map);

///////// display_map_element.c ///////

void display_obs(map_obs_t *obs, sfRenderWindow *window);
void display_map(map_t **map, sfRenderWindow *window);

///////// place_map_flag.c ///////////

int check_line_size(char *buffer, int i);
void place_map_flag(map_t **map, char *buffer);

///////// get_map_info.c //////////////

void get_map_info(char *buffer, map_info_t *map_info);

#endif
