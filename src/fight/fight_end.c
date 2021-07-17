/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** fight_end
*/

#include "fight.h"

void fight_check_ko(fight_data_t *fight)
{
    if (trainer_check_ko(fight->trainer_1->pokemon_nb,
        fight->trainer_1->pokemon) == 1) {
        fight->end = EF_P2_WIN;
        return;
    }
    if (trainer_check_ko(fight->trainer_2->pokemon_nb,
        fight->trainer_2->pokemon) == 1) {
        fight->end = EF_P1_WIN;
        return;
    }
}

void fight_escape(fight_data_t *fight)
{
    fight->end = EF_ESCAPE;
}