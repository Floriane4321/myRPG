/*
** EPITECH PROJECT, 2021
** cursor.c
** File description:
** cursor manager
*/

#include "gdata.h"

sfSprite *creat_cursor(sfTexture *tex)
{
    sfSprite *cursor = sfSprite_create();

    sfSprite_setTextureRect(cursor, (sfIntRect){0, 0, 64, 64});
    sfSprite_setTexture(cursor, tex, sfTrue);
    return (cursor);
}
