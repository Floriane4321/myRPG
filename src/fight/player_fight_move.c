/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** player_fight_move
*/

#include "fight.h"

void player_attack(int attack_id, pokemon_t *attack, pokemon_t *defense)
{
    int level = attack->level * 0.4 + 2;
    int att = attack->attack;
    int pow = attack->set_attack[attack_id].power;
    int def = defense->defense;
    int pv_lost = (level * att * pow) / (def * 50) + 10;

    defense->hp = defense->hp - pv_lost;
    if (defense->hp < 0)
        defense->hp = 0;
}

void player_change_status(move_status_t new_move, trainer_t *trainer)
{
    trainer->status = new_move;
}

void player_change_pokemon(int new_pok, trainer_t *trainer)
{
    if (new_pok > trainer->pokemon_nb)
        return;
    if (trainer->pokemon[new_pok] == NULL
        && trainer->pokemon[new_pok]->hp > 0)
        return;
}
