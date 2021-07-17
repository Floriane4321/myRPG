/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** parse_attacks
*/

#include "fight.h"

void parse_attacks_pt1(pokemon_t *pokemon, attack_t **list)
{
    if (pokemon->type == PICKACHU) {
        create_attack(list, &pokemon->set_attack[0], THUNDER_SHOCK);
    }
    if (pokemon->type == BULBASAUR) {
        create_attack(list, &pokemon->set_attack[0], TACKLE);
    }
    if (pokemon->type == CHERMANDER) {
        create_attack(list, &pokemon->set_attack[0], FLAMETHROWER);
    }
    if (pokemon->type == SQUIRTLE) {
        create_attack(list, &pokemon->set_attack[0], WATER_GUN);
    }
    if (pokemon->type == RASTACHU) {
        create_attack(list, &pokemon->set_attack[0], FAIT_TOURNER);
        create_attack(list, &pokemon->set_attack[1], TRIP);
    }
}