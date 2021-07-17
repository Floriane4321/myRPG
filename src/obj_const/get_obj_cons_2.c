/*
** EPITECH PROJECT, 2021
** get_obj_const_2.c
** File description:
** fonction tampon get next
*/

#include "object.h"
#include "fight.h"

int get_exp_max(pokemon_t *pok)
{
    return (pok->xp_max);
}

char *get_status(pokemon_t *pok)
{
    return ("ok");
}

char *get_name_attack(pokemon_t *pok, int nb)
{
    if (nb > 3)
        return (NULL);
    return (pok->set_attack[nb].name);
}
