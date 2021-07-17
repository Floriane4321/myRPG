/*
** EPITECH PROJECT, 2021
** get_obj_const.c
** File description:
** fonction tampon get
*/

#include "object.h"
#include "fight.h"

pokemon_t *get_current_pok(trainer_t *trainer)
{
    int main_pokemon = trainer->main_pokemon;
    pokemon_t *pok = NULL;

    if (trainer->pokemon[main_pokemon] != NULL)
        pok = trainer->pokemon[main_pokemon];
    return (pok);
}

int get_pv(pokemon_t *pok)
{
    return (pok->hp);
}

int get_pv_max(pokemon_t *pok)
{
    return (pok->hp_max);
}

char *get_name_pok(pokemon_t *pok)
{
    return (pok->name);
}

int get_exp(pokemon_t *pok)
{
    return (pok->xp);
}
