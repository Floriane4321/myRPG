/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** fight_init
*/

#include "fight.h"

fight_data_t *fight_init(void)
{
    fight_data_t *fight = malloc(sizeof(fight_data_t));

    fight->lap = 0;
    fight->end = EF_NULL;
    fight->trainer_1 = trainer_init("BOB\0");
    fight->trainer_2 = trainer_init("AZ\0");
    fight->list_pokemon = create_list_pokemon();
    fight->list_attack = create_list_attack();
    fight->trainer_1->pokemon[0] = create_pokemon(PICKACHU, fight);
    fight->trainer_2->pokemon[0] = create_pokemon(BULBASAUR, fight);
    return (fight);
}

void fight_set_trainer(int trainer_nb, fight_data_t *fight, trainer_t *trainer)
{
    if (trainer_nb == 1)
        fight->trainer_1 = trainer;
    if (trainer_nb == 2)
        fight->trainer_2 = trainer;
}

void fight_reset_fight(fight_data_t *fight)
{
    fight->lap = 0;
    fight->trainer_1 = NULL;
    fight->trainer_2 = NULL;
    fight->end = EF_NULL;
}
