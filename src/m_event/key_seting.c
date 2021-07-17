/*
** EPITECH PROJECT, 2021
** key_setting.c
** File description:
** function set keyboard
*/

#include "gdata.h"
#include "m_event.h"
#include "button.h"

void key_for_wht_act(event_t *even, int tmp)
{
    switch (even->numkey) {
    case (KLEFT):
        even->set->left = tmp;
        return;
    case (KDOWN):
        even->set->down = tmp;
        return;
    case (KTOP):
        even->set->top = tmp;
        return;
    case (KRIGHT):
        even->set->right = tmp;
        return;
    }
}
void swap_keyboard(event_t *even, gdata_t *data)
{
    int tmp = even->even.key.code;
    char str;

    str = tmp + 65;
    sfText_setString(even->set->but->text, &str);
    key_for_wht_act(even, tmp);
    even->keyseting = 0;
}

keyboard_set_t *creat_keyboard(void)
{
    keyboard_set_t *new = malloc(sizeof(keyboard_set_t));

    new->but = NULL;
    new->left = sfKeyA;
    new->right = sfKeyQ;
    new->top = sfKeyS;
    new->down = sfKeyW;
    return (new);
}
