/*
** EPITECH PROJECT, 2021
** defender
** File description:
** entity.c
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include "entity.h"
#include "stdlib.h"

/// rect base, anim lign, col, mod anim, init pos, size

const prefab_pos_t prefab_pos[NB_ENTITY_TYPE] = {
    {{0, 0, 64, 64}, 4, 4, {64, 64}, {-8, 248}, {1.2, 1.2}},
    {{0, 0, 64, 64}, 4, 4, {64, 64}, {0, 0}, {1, 1}},
};

const tyme_t prefab_animation[NB_ENTITY_TYPE] = {
    {0, (0.2), 0},
    {0, (1.0), 0},
};

pos_t *pos_copy(int type)
{
    pos_t *new = malloc(sizeof(struct pos_s));
    prefab_pos_t base = prefab_pos[type];

    new->rect = base.initial;
    new->initial = base.initial;
    new->lig = 0;
    new->col = 0;
    new->nb_lig = base.nb_lig;
    new->nb_col = base.nb_col;
    new->mod = base.mod;
    new->pos = base.pos;
    new->dir.x = 0;
    new->dir.y = 0;
    new->target.x = 0;
    new->target.y = 0;
    new->size = base.size;
    return (new);
}

tyme_t *time_copy(int type)
{
    tyme_t *new = malloc(sizeof(struct tyme_s));
    tyme_t base = prefab_animation[type];

    new->time = base.time;
    new->delay = base.delay;
    new->delay2 = base.delay2;
    return (new);
}

void entity_destroy(list_entity_t *enti)
{
    entity_t *tmp = enti->entity;

    enti->next = NULL;
    enti->old = NULL;
    sfSprite_destroy(tmp->sprite);
    free(tmp->pos);
    free(tmp->time);
    (tmp->link.ptr->ptr_destroyer)(tmp->link.ptr);
    free(tmp);
    free(enti);
}

entity_t *entity_creat(sfTexture *tex, type_entity_t enti, int generic)
{
    entity_t *new = malloc(sizeof(struct entity_s));
    sfVector2f si = {1, 0.5};

    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, tex, sfTrue);
    new->z = 2;
    new->status = 0;
    new->pos = pos_copy(generic);
    new->time = time_copy(generic);
    new->generic = generic;
    new->etype = enti;
    sfSprite_setPosition(new->sprite, new->pos->pos);
    sfSprite_setTextureRect(new->sprite, new->pos->rect);
    sfSprite_setScale(new->sprite, new->pos->size);
    new->destroy = 0;
    return (new);
}
