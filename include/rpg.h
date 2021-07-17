/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** header for rpg
*/

#ifndef HUNTER_T
#define HUNTER_T

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include "button.h"
#include "entity.h"
#include "m_view.h"
#include "map.h"
#include "object.h"

typedef struct map (map_t);
typedef struct map_obs_s (map_obs_t);
typedef struct map_info (map_info_t);
typedef struct obj_const_s(obj_const_t);
typedef struct fight_data(fight_data_t);

typedef struct player_s
{
    void (*ptr_update)(event_t *, entity_t *, float);
    void (*ptr_destroyer)(struct player_s *);
    entity_t *entity;
    int lvl;
}player_t;

typedef struct level_s
{
    button_list_t *blist;
    list_entity_t *entity;
    obj_const_t *obj_const;
    sfView *game;
    sfView *ui;
    int nb;
}level_t;

typedef struct rpg_s
{
    texture_t *drw;
    player_t *player;
    level_t *lvl;
    m_view_t *view;
    map_t **map;
    map_obs_t *obs_list;
    prefab_craft_t *craft;
    map_info_t *m_info;
    fight_data_t *fight;
}rpg_t;

rpg_t *rpg_create(const sfView *origin);
void rpg_destroy(rpg_t *rpg);

void updat_sesion_one(event_t *event, rpg_t *data, float delta);

button_list_t *ini_bmenu(button_list_t *blist, texture_t *tex);
#endif
