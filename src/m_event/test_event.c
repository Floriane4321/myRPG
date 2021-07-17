/*
** EPITECH PROJECT, 2021
** test_even.c
** File description:
** test keyboard
*/

#include "gdata.h"
#include "m_event.h"
#include "map.h"
#include "my.h"

void exit_g(level_t *lvl, event_t *even);
void test_button_hedel(level_t *lvl, sfVector2f mouse, event_t *even);
void test_button_clecked(level_t *lvl, sfVector2f mouse, event_t *even);
void test_button_released(level_t *lvl, sfVector2f mouse, event_t *even);
void update_mouse_cursor(event_t *even, sfVector2f new);
char *find_craft(prefab_craft_t *fab, item_t *s1, item_t *s2);

void test_keyboard_next(level_t *lvl, event_t *even, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(even->set->top)) {
        even->player.dir = TOP;
        even->player.moving = 1;
    }
}

void test_keyboard(level_t *lvl, event_t *even, sfRenderWindow *window)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        even->c_mode = PAUSE;
    if (sfKeyboard_isKeyPressed(sfKeyLShift))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyF))
        even->c_mode = FIGHT;
    if (sfKeyboard_isKeyPressed(even->set->left)) {
        even->player.dir = LEFT;
        even->player.moving = 1;
    }
    if (sfKeyboard_isKeyPressed(even->set->right)) {
        even->player.dir = RIGHT;
        even->player.moving = 1;
    }
    if (sfKeyboard_isKeyPressed(even->set->down)) {
        even->player.dir = DOWN;
        even->player.moving = 1;
    }
    test_keyboard_next(lvl, even, window);
}

void test_hedel(level_t *lvl, event_t *even, gdata_t *data)
{
    sfVector2i mouse;
    sfVector2f new;

    mouse = sfMouse_getPositionRenderWindow(data->window);
    new = sfRenderWindow_mapPixelToCoords(data->window, mouse,
    data->origin);
    test_button_hedel(lvl, new, even);
    update_mouse_cursor(even, new);
}

void test_click(level_t *lvl, event_t *even, gdata_t *data)
{
    sfVector2i mouse;
    sfVector2f new;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse = sfMouse_getPositionRenderWindow(data->window);
        new = sfRenderWindow_mapPixelToCoords(data->window, mouse,
        data->origin);
        test_button_clecked(lvl, new, even);
    }
}

void test_released(level_t *lvl, event_t *even, gdata_t *data)
{
    sfVector2i mouse;
    sfVector2f new;

    if (even->even.mouseButton.button == sfMouseLeft) {
        mouse = sfMouse_getPositionRenderWindow(data->window);
        new = sfRenderWindow_mapPixelToCoords(data->window, mouse,
        data->origin);
        test_button_released(lvl, new, even);
    }
}
