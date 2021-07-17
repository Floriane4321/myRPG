/*
** EPITECH PROJECT, 2020
** standar_mode
** File description:
** hightess function of hunter
*/

#include "gdata.h"
#include "m_event.h"
#include "map.h"
#include <stdio.h>

void m_event_update(event_t *even, gdata_t *data);
void (*game_set[7]) (event_t *, rpg_t *, float);
void update_game(gdata_t *data);
music_t *ini_music(texture_t *drw);
m_view_t *m_view_creat(sfRenderWindow *window);
sfSprite *creat_cursor(sfTexture *tex);

void preset_gamemode(gdata_t *data)
{
    ((data->gameset[MENU])) = (gamemode_menu);
    ((data->gameset[MODE1])) = (game_sesion_one);
    ((data->gameset[END])) = (game_end);
    ((data->gameset[PAUSE])) = (gamemode_pause);
    ((data->gameset[OPTION])) = (gamemode_option);
    ((data->gameset[FIGHT])) = (gamemode_fight);
    ((data->gameset[INVENTORY])) = (gamemode_inventory);
}

void init_game(gdata_t *data)
{
    sfVideoMode mode = {1280, 720, 32};

    data->clock = sfClock_create();
    data->window = sfRenderWindow_create(mode, "MY_RPG", sfResize |
    sfClose, NULL);
    sfRenderWindow_setMouseCursorVisible(data->window, sfFalse);
    data->origin = sfRenderWindow_getView(data->window);
    data->m_event = m_event_create();
    sfRenderWindow_setFramerateLimit(data->window, 30);
    preset_gamemode(data);
    data->rpg = rpg_create(data->origin);
    data->m_event->cursor = creat_cursor(get_textur(data->rpg->drw, TCURSOR));
    data->m_event->music = ini_music(data->rpg->drw);
}

int standar_mode(char *buffer)
{
    gdata_t *data = gdata_create();

    init_game(data);
    data->rpg->map = map_init(buffer, data->rpg->drw->pnj,
    data->rpg->m_info);
    data->rpg->obs_list = list_obs_init(data->rpg->map);
    sfClock_restart(data->clock);
    while (sfRenderWindow_isOpen(data->window)) {
        data->delta = sfClock_getElapsedTime(data->clock);
        sfClock_restart(data->clock);
        m_event_update(data->m_event, data);
        (data->gameset[data->mode])
        (data->m_event, data->rpg, data->delta.microseconds / 1000000.0);
        if (data->status == 1)
            sfRenderWindow_close(data->window);
        draw_game(data);
    }
    gdata_destroy(data);
    return (0);
}
