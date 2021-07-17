/*
** EPITECH PROJECT, 2021
** defender
** File description:
** entity.h
*/

#ifndef ENTITIY_H_
#define ENTITIY_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>

#define NB_ENTITY_TYPE 2

typedef struct entity_default_s (entity_default_t);
typedef struct event_s (event_t);
typedef struct player_s (player_t);

typedef enum dir_e
{
    DOWN,
    LEFT,
    RIGHT,
    TOP,
}dir_t;

typedef enum type_entity_e
{
    PLAYER,
    PNJ,
}type_entity_t;

typedef enum archetype_textur_entity_s
{
    VILAIN,
    PROF_CHEN,
}archetype_textur_entity_t;

union entity_link_u
{
    entity_default_t *ptr;
    player_t *player;
};

typedef struct tyme_s
{
    float time;
    float delay;
    float delay2;
}tyme_t;

typedef struct pos_s
{
    sfIntRect rect;
    sfIntRect initial;
    int lig;
    int col;
    int nb_lig;
    int nb_col;
    sfVector2i mod;
    sfVector2f pos;
    sfVector2f dir;
    sfVector2i target;
    sfVector2f size;
}pos_t;

typedef struct prefab_pos_s
{
    sfIntRect initial;
    int nb_lig;
    int nb_col;
    sfVector2i mod;
    sfVector2f pos;
    sfVector2f size;
}prefab_pos_t;

typedef struct entity_s
{
    sfSprite *sprite;
    int z;
    pos_t *pos;
    tyme_t *time;
    archetype_textur_entity_t generic;
    type_entity_t etype;
    union entity_link_u link;
    int status;
    int destroy;
}entity_t;

typedef struct list_entity_s
{
    entity_t *entity;
    struct list_entity_s *next;
    struct list_entity_s *old;
}list_entity_t;

typedef struct entity_default_s
{
    void (*ptr_update)(event_t *, entity_t *, float);
    void (*ptr_destroyer)(void *);
}entity_default_t;

entity_t *entity_creat(sfTexture *tex, type_entity_t enti, int generic);
#endif
