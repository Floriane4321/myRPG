/*
** EPITECH PROJECT, 2021
** defender
** File description:
** update.c
*/

#include "gdata.h"
#include "m_event.h"
#include "entity.h"
#include "utility.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>

void handel_entity_destroy(event_t *even, entity_t *entity);
int cmp_cord(sfVector2f nb1, sfVector2f nb2, float marge);
int is_amove(event_t *even, entity_t *entity);
int is_arotat(event_t *even, entity_t *entity, sfVector2f old);
int testing_map_cell(event_t *even, sfVector2i targ);
void set_entity_rotat(entity_t *entity);

int update_entity_tyme(tyme_t *entity, float delta)
{
    entity->time = entity->time + delta;
    entity->delay2 = entity->time + entity->delay2;
    if (entity->time > entity->delay) {
        entity->time = entity->time - entity->delay;
        return (1);
    }
    return (0);
}

void update_entity_pos(entity_t *entity, float delta)
{
    pos_t *pos = entity->pos;
    sfVector2f vec;
    float w = entity->pos->target.x * 64;
    float z = (entity->pos->target.y) * 64;

    pos->pos.x = pos->pos.x + pos->dir.x * 64 * delta * entity->status;
    pos->pos.y = pos->pos.y + pos->dir.y * 64 * delta * entity->status;
    vec.x = w;
    vec.y = z;
    if (cmp_cord(entity->pos->pos, vec, 8) == 1) {
        entity->pos->pos.x = entity->pos->target.x * 64;
        entity->pos->pos.y = entity->pos->target.y * 64;
        entity->status = 0;
    }
}

void update_entity_anim(event_t *even, entity_t *entit, float delta, int statu)
{
    pos_t *pos = entit->pos;
    sfVector2f oldir = pos->dir;

    if (statu == 1 && entit->status == 0 && is_amove(even, entit) == 1) {
        if (is_arotat(even, entit, oldir) == 1 && entit->status != 1) {
            set_entity_rotat(entit);
        } else if (testing_map_cell(even, entit->pos->target) == 0)
            entit->status = 1;
    }
    if (statu == 1 && entit->status == 1)
        pos->col++;
    if (pos->col >= pos->nb_col)
        pos->col = 0;
    pos->rect.left = pos->col * pos->mod.x;
    sfSprite_setPosition(entit->sprite, pos->pos);
    sfSprite_setTextureRect(entit->sprite, pos->rect);
}

void update_entity_spetype(event_t *even, entity_t *entity, float delta)
{
    (entity->link.ptr->ptr_update)(even, entity, delta);
}

void update_entity(event_t *even, list_entity_t *entity, float delta)
{
    int statu = 0;

    if (entity == NULL)
        return;
    for (list_entity_t *start = entity; start != NULL; start = start->next) {
        statu = update_entity_tyme(start->entity->time, delta);
        update_entity_spetype(even, start->entity, delta);
        update_entity_pos(start->entity, delta);
        update_entity_anim(even, start->entity, delta, statu);
    }
}
