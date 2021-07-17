/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** debug_map
*/

#include "map.h"

map_t *debug_sprite_init(sfTexture *texture, sfIntRect rect, int dir,
                        tmap_t en)
{
    map_t *background = malloc(sizeof(map_t));

    background->pos = (sfVector2f){0, 0};
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, texture, 0);
    sfSprite_setTextureRect(background->sprite, rect);
    background->texture_type = en;
    return (background);
}

void input_control(sfEvent event, sfRenderWindow *w)
{
    while (sfRenderWindow_pollEvent(w, (&event))) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w);
    }
}

void map_debug(map_t **map) {
    sfTexture *texture = NULL;
    sfVideoMode video_mode = {1280, 720, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode, "window",
                            sfDefaultStyle, NULL);
    sfEvent event;

    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        input_control(event, window);
        sfRenderWindow_clear(window, (sfColor){0, 0, 0});
        display_map(map, window);
        sfRenderWindow_display(window);
    }
}