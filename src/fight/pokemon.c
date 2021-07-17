/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** pokemon
*/

#include "fight.h"

void copy_name(char (*dest)[80], char (*src)[80])
{
    int i;

    my_putstr(*src);
    my_putstr("\n");
    for (i = 0; *src[i] != '\0'; i++) {
        *dest[i] = *src[i];
    }
    my_putstr(*dest);
    my_putstr("\n");
}

void copy_pokemon_data(pokemon_t *dest, pokemon_t *src)
{
    dest->hp = src->hp;
    dest->hp_max = src->hp_max;
    dest->xp = src->xp;
    dest->xp_max = src->xp_max;
    dest->level = src->level;
    dest->defense = src->defense;
    dest->defense_spe = src->defense_spe;
    dest->attack = src->attack;
    dest->attack_spe = src->attack_spe;
    dest->speed = src->speed;
    dest->type = src->type;
    my_strcpy(dest->name, src->name);
    my_strcpy(dest->poketype, src->poketype);
    for (int i = 0; i < 4; i++) {
        dest->set_attack[i] = (attack_t){0, 0, "\0", "\0", 0};
    }
}

pokemon_t *create_pokemon(pokename_t name, fight_data_t *fight)
{
    pokemon_t *new = NULL;
    pokemon_t **list = fight->list_pokemon;

    for (int i = 0; list[i] != NULL; i++) {
        if (name == list[i]->type) {
            new = malloc(sizeof(pokemon_t));
            copy_pokemon_data(new, list[i]);
            attack_init(new, fight);
            return (new);
        }
    }
    return (new);
}
