/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** fight
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

typedef enum end_fight
{
    EF_NULL,
    EF_ESCAPE,
    EF_P1_WIN,
    EF_P2_WIN
}end_fight_t;

typedef enum move_status
{
    MS_MENU,
    MS_ATTACK,
    MS_CHANGE,
    MS_OBJ
}move_status_t;

typedef enum pokename
{
    PICKACHU,
    BULBASAUR,
    CHERMANDER,
    SQUIRTLE,
    RASTACHU,
    POK_VIDE,
}pokename_t;

typedef enum attackname
{
    NUZZLE,
    THUNDER_SHOCK,
    FEINT,
    SLAM,
    WINE_WIP,
    RAZOR_LEAF,
    POISON_POWDER,
    TAKE_DOWN,
    SCRATCH,
    DRAGON_BREATH,
    FLAMETHROWER,
    INFERNO,
    TACKLE,
    WATER_GUN,
    WATER_PULSE,
    SKULL_BASH,
    TRIP,
    FAIT_TOURNER,
    SLAP,
    PUT_OUT
}attackname_t;

typedef struct attack
{
    int power;
    int accuracy;
    char name[80];
    char attype[80];
    attackname_t type;
}attack_t;

typedef struct pokemon
{
    int hp;
    int hp_max;
    int xp;
    int xp_max;
    int level;
    int defense;
    int defense_spe;
    int attack;
    int attack_spe;
    int speed;
    pokename_t type;
    char name[80];
    char poketype[80];
    attack_t set_attack[4];
}pokemon_t;

typedef struct trainer {
    char name[80];
    int main_pokemon;
    int pokemon_nb;
    move_status_t status;
    pokemon_t **pokemon;
}trainer_t;

typedef struct fight_data {
    trainer_t *trainer_1;
    trainer_t *trainer_2;
    pokemon_t **list_pokemon;
    attack_t **list_attack;
    int lap;
    end_fight_t end;
}fight_data_t;

attack_t **create_list_attack(void);
pokemon_t **create_list_pokemon(void);
void parse_attacks_pt1(pokemon_t *pokemon, attack_t **list);
pokemon_t *create_pokemon(pokename_t name, fight_data_t *fight);
void fight_engine(fight_data_t *fight);
//void copy_name(char (*dest)[80], char (*src)[80]);
void attack_init(pokemon_t *pokemon, fight_data_t *fight);
trainer_t *trainer_init(char *name);
int trainer_check_ko(int pokemon_nb, pokemon_t **pokemons);
void fight_check_ko(fight_data_t *fight);
void create_attack(attack_t **list, attack_t *new, attackname_t name);


#endif/* !FIGHT_H_ */
