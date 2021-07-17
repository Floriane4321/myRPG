/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** trainer
*/

#include "fight.h"

void set_pokemon_trainer(pokename_t nam, fight_data_t *fight, trainer_t *train)
{
    int cell = 0;

    while (train->pokemon[cell] == NULL) {
        cell++;
    }
    if (cell < 6) {
        train->pokemon[cell] = create_pokemon(nam, fight);
        train->pokemon_nb = train->pokemon_nb;
    }
}

int trainer_check_ko(int pokemon_nb, pokemon_t **pokemons)
{
    int compt = 0;

    for (int i = 0; pokemons[i] != NULL; i++) {
        if (pokemons[i]->hp <= 0) {
            compt++;
        }
    }
    if (compt == pokemon_nb)
        return (1);
    return (0);
}

trainer_t *trainer_init(char *name)
{
    int len = my_strlen(name);
    trainer_t *trainer = malloc(sizeof(trainer_t));

    my_strncpy(trainer->name, name, len);
    trainer->pokemon_nb = 1;
    trainer->main_pokemon = 0;
    trainer->pokemon = malloc(sizeof(pokemon_t *) * 7);
    trainer->status = MS_MENU;
    for (int i = 0; i < 7; i++)
        trainer->pokemon[i] = NULL;
    return (trainer);
}
