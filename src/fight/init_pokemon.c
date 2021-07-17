/*
** EPITECH PROJECT, 2021
** init
** File description:
** init pokemon
*/

#include "fight.h"

void alloc_pokemon_list(pokemon_t **pokemons)
{
    for (int i = 0; i < 5; i++) {
        pokemons[i] = malloc(sizeof(pokemon_t));
    }
    pokemons[5] = NULL;
}

pokemon_t **create_list_pokemon(void)
{
    pokemon_t **pokemons = malloc(sizeof(pokemon_t *) * 6);

    alloc_pokemon_list(pokemons);
    *pokemons[0] = (pokemon_t){72, 72, 0, 300, 1, 10, 50, 55, 50, 3,
    PICKACHU, "Roucool\0", "electric\0"};
    *pokemons[1] = (pokemon_t){80, 80, 0, 300, 1, 19, 65, 49, 65, 1,
    BULBASAUR, "Bulbasaur\0", "grass\0"};
    *pokemons[2] = (pokemon_t){39, 78, 0, 300, 1, 13, 50, 52, 60, 2,
    CHERMANDER, "Chermander\0", "fire\0"};
    *pokemons[3] = (pokemon_t){44, 79, 0, 300, 1, 25, 64, 48, 50, 1,
    SQUIRTLE, "Squirtle\0", "water\0"};
    *pokemons[4] = (pokemon_t){20, 69, 0, 420, 1, 29, 0, 10 , 69, 1,
    RASTACHU, "Rastakachu\0", "weed\0"};

    return (pokemons);
}

void alloc_list_attack(attack_t **attacks)
{
    for (int i = 0; i < 20; i++) {
        attacks[i] = malloc(sizeof(attack_t));
    }
    attacks[20] = NULL;
}

void create_list_attack2(attack_t **attacks)
{
    *attacks[10] = (attack_t){75, 75, "flamethrower\0", "fire\0",
    FLAMETHROWER};
    *attacks[11] = (attack_t){100, 50, "inferno\0", "fire\0", INFERNO};
    *attacks[12] = (attack_t){40, 100, "tackle\0", "normal\0", TACKLE};
    *attacks[13] = (attack_t){45, 95, "water gun\0", "water\0", WATER_GUN};
    *attacks[14] = (attack_t){65, 88, "water pulse\0", "water\0", WATER_PULSE};
    *attacks[15] = (attack_t){130, 45, "skull bash\0", "normal\0", SKULL_BASH};
    *attacks[16] = (attack_t){150, 50, "trip\0", "weed\0", TRIP};
    *attacks[17] = (attack_t){0, 85, "fait tourner\0", "sleep\0", FAIT_TOURNER};
    *attacks[18] = (attack_t){10, 100, "slap\0", "normal\0", SLAP};
    *attacks[19] = (attack_t){50, 90, "put out\0", "fire\0", PUT_OUT};
}

attack_t **create_list_attack(void)
{
    attack_t **attacks = malloc(sizeof(attack_t *) * 21);

    alloc_list_attack(attacks);
    *attacks[0] = (attack_t){20, 100, "nuzzle\0", "electric\0", NUZZLE};
    *attacks[1] = (attack_t){40, 75, "thunder shock\0", "electric\0",
    THUNDER_SHOCK};
    *attacks[2] = (attack_t){30, 100, "feint\0", "normal\0", FEINT};
    *attacks[3] = (attack_t){80, 60, "slam\0", "normal\0", SLAM};
    *attacks[4] = (attack_t){45, 100, "wine whip\0", "grass\0", WINE_WIP};
    *attacks[5] = (attack_t){55, 90, "razor leaf\0", "grass\0", RAZOR_LEAF};
    *attacks[6] = (attack_t){15, 75, "poison powder\0", "poison\0",
    POISON_POWDER};
    *attacks[7] = (attack_t){80, 65, "take down\0", "normal\0", TAKE_DOWN};
    *attacks[8] = (attack_t){40, 100, "scrath\0", "normal\0", SCRATCH};
    *attacks[9] = (attack_t){60, 85, "dragon breath\0", "dragon\0",
    DRAGON_BREATH};
    create_list_attack2(attacks);
    return (attacks);
}
