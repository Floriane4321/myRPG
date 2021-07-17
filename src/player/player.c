/*
** EPITECH PROJECT, 2021
** player.c
** File description:
** player manager
*/

#include "entity.h"
#include "rpg.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my.h"

list_entity_t *list_entity_addbot(list_entity_t *list, entity_t *entity);

void update_player(event_t *even, entity_t *entity, float delta)
{
    if (entity->status != 1) {
        entity->pos->target.x = (entity->pos->pos.x / 64) + entity->pos->dir.x;
        entity->pos->target.y = (entity->pos->pos.y / 64) + entity->pos->dir.y;
    }
}

void player_destroy(player_t *player)
{
    free(player);
}

player_t *player_creat(rpg_t *rpg)
{
    player_t *new = malloc(sizeof(player_t));

    new->entity = entity_creat(get_textur(rpg->drw, TPLAYER),
    PLAYER, VILAIN);
    new->entity->link.player = new;
    (new->ptr_update) = (update_player);
    (new->ptr_destroyer) = (player_destroy);
    rpg->lvl[MODE1].entity = list_entity_addbot(
    rpg->lvl[MODE1].entity, new->entity);
    return (new);
}
