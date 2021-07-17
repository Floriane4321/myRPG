/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** reset_pokemon
*/

#include "fight.h"

pokemon_t reset_pokemon(void)
{
    pokemon_t pokemon = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    pokemon.name[0] = '\0';
    return (pokemon);
}