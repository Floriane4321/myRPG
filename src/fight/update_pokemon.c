/*
** EPITECH PROJECT, 2021
** update_pokemon.c
** File description:
** fonction update pokemon
*/

#include "gdata.h"
#include "m_event.h"
#include "fight.h"
#include <stdio.h>

pokemon_t *get_current_pok(trainer_t *trainer);
void player_attack(int attack_id, pokemon_t *attack, pokemon_t *defense);
void fight_escape(fight_data_t *fight);

ev_fight_t ini_event_fight(void)
{
    ev_fight_t fight;

    fight.attack_id = -1;
    fight.fight = 0;
    return (fight);
}

void reset_even_fight(event_t *even)
{
    if (even->fight.fight == 1 && even->fight.attack_id != -1) {
        even->fight.fight = 0;
        even->fight.attack_id = -1;
    }
}

void phase_attack(event_t *even, fight_data_t *fight)
{
    pokemon_t *pok = get_current_pok(fight->trainer_1);
    pokemon_t *adv = fight->trainer_2->pokemon[fight->trainer_2->main_pokemon];

    if (pok->set_attack[even->fight.attack_id].name == NULL) {
        even->fight.attack_id = -1;
        return;
    }
    player_attack(even->fight.attack_id, pok, adv);
    player_attack(even->fight.attack_id, adv, pok);
}

void phase_choise(trainer_t *trainer)
{
    return;
}

void update_pokemon(event_t *even, fight_data_t *fight)
{
    if (fight->end != EF_NULL) {
        fight->end == EF_NULL;
        even->c_mode = MODE1;
        return;
    }
    if (even->fight.fight == 0)
        return;
    if (even->fight.fight == 1 && even->fight.attack_id != -1)
        phase_attack(even, fight);
    if (even->fight.fight == 2)
        phase_choise(fight->trainer_1);
    if (even->fight.fight == 3)
        fight_escape(fight);
    reset_even_fight(even);
    fight_check_ko(fight);
}
