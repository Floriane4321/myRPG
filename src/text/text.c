/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** file for fucntion generat sftext
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"

sfText *text_create(char *str, sfVector2f pos, sfFont *font)
{
    sfText *new = sfText_create();

    sfText_setFont(new, font);
    sfText_setString(new, str);
    sfText_setPosition(new, pos);
    sfText_setCharacterSize(new, 50);
    sfText_setColor(new, sfBlack);
    return (new);
}
