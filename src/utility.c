/*
** EPITECH PROJECT, 2020
** utility.c
** File description:
** usfull function
*/

#include "utility.h"

sfIntRect set_rect(int top, int bot, int x, int y)
{
    sfIntRect tmp;

    tmp.left = top;
    tmp.top = bot;
    tmp.width = x;
    tmp.height = y;
    return (tmp);
}

sfVector2f set_vecf(float x, float y)
{
    sfVector2f new;

    new.x = x;
    new.y = y;
    return (new);
}

sfVector2i set_vector(int x, int y)
{
    sfVector2i new;

    new.x = x;
    new.y = y;
    return (new);
}

sfIntRect add_rect(sfIntRect base, sfIntRect mod)
{
    sfIntRect rect;

    rect.top = base.top + mod.top;
    rect.left = base.left + mod.left;
    rect.height = base.height + mod.height;
    rect.width = base.width + mod.width;
    return (rect);
}

int cmp_rect(sfIntRect base, sfIntRect new)
{
    if (base.left >= new.left && base.top >= new.top &&
        base.width >= new.width && base.height >= new.height)
        return (1);
    return (0);
}
