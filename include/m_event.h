/*
** EPITECH PROJECT, 2020
** m_event.h
** File description:
** header custom event
*/

#ifndef M_EVENT_H
#define M_EVENT_H

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "entity.h"
#include "button.h"

typedef enum mode_e (mod_t);
typedef struct music_s (music_t);

typedef enum my_keyboard_e
{
    KLEFT,
    KDOWN,
    KTOP,
    KRIGHT,
}my_keyboard_t;

typedef enum ctm_event_type_e
{
    ENTITY_DESTROY,
    CRAFTING,
}ctm_event_type_t;

typedef struct mctm_event_s
{
    ctm_event_type_t type;
    entity_t *to_free;
    struct mctm_event_s *next;
}mctm_event_t;

typedef struct player_mod_s
{
    int dir;
    int moving;
    int wht_att;
}player_mod_t;

typedef struct keyboard_set_s
{
    button_t *but;
    int left;
    int down;
    int top;
    int right;
    int action1;
    int action2;
}keyboard_set_t;

typedef struct craft_s
{
    item_t *item1;
    item_t *item2;
    item_t *res;
    int comput;
}craft_t;

typedef struct ev_fight_s
{
    int attack_id;
    int fight;
}ev_fight_t;

typedef struct event_s
{
    sfEvent even;
    int close;
    player_mod_t player;
    enum mode_e c_mode;
    mctm_event_t *ev_list;
    music_t *music;
    int keyseting;
    int numkey;
    keyboard_set_t *set;
    button_t *drag;
    craft_t craft;
    ev_fight_t fight;
    map_t **map;
    map_info_t *m_info;
    sfVector2u win_size;
    sfSprite *cursor;
}event_t;

event_t *m_event_create(void);
void m_event_destroy(event_t *m_event);
#endif
