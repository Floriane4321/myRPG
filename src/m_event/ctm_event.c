/*
** EPITECH PROJECT, 2021
** ctm_function
** File description:
** custom event
*/

#include "gdata.h"
#include "entity.h"
#include "m_event.h"
#include "my.h"

list_entity_t *list_entity_sup(list_entity_t *list, entity_t *ref);
list_entity_t *list_entity_addbot(list_entity_t *list, entity_t *entity);
button_list_t *new_item(button_list_t *blist, texture_t *tex, char *item);
button_list_t *list_button_sup(button_list_t *list, button_t *but);
void destroy_item(item_t *item);
int is_in_radius(sfVector2f tow, sfVector2f new, float range);
char *find_craft(prefab_craft_t *fab, item_t *s1, item_t *s2);

void ev_entity_destroy(gdata_t *data, mctm_event_t *ev)
{
    data->rpg->lvl[data->mode].entity = list_entity_sup(
    data->rpg->lvl[data->mode].entity, ev->to_free);
}

void ev_crafting(gdata_t *data, mctm_event_t *ev)
{
    char *res;
    event_t *event = data->m_event;
    button_list_t *list = data->rpg->lvl[data->mode].blist;

    res = find_craft(data->rpg->craft, event->craft.item1, event->craft.item2);
    if (res != NULL)
        list = new_item(list, data->rpg->drw, res);
    if (event->craft.item1 != NULL) {
        event->craft.item1->link->blink->blink = NULL;
        list = list_button_sup(list, event->craft.item1->link);
        destroy_item(event->craft.item1);
    }
    if (event->craft.item2 != NULL) {
        event->craft.item2->link->blink->blink = NULL;
        list = list_button_sup(list, event->craft.item2->link);
        destroy_item(event->craft.item2);
    }
    event->craft.item1 = NULL;
    event->craft.item2 = NULL;
}
