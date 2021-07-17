/*
** EPITECH PROJECT, 2021
** object.h
** File description:
** header object
*/

#ifndef OBJECT_CONST_H
#define OBJECT_CONST_H

#include "rpg.h"
#include "fight.h"

#define NBMAX_OBJ_CONST 25
#define NBMAX_TYPE_OBJ 15

typedef struct fight_data(fight_data_t);

typedef enum pref_text_e
{
    DVIDE,
    DCOUCOU,
    DTCHOUS,
    DKEYBOARD,
    DLEFT,
    DRIGHT,
    DTOP,
    DDOWN,
    DLOW,
    DMED,
    DHIG,
}pref_text_t;

typedef enum obj_const_type_e
{
    VIDE,
    PV_POK_PLY,
    PV_POK_ADV,
    NAME_POK_PLY,
    NAME_POK_ADV,
    BARRE_EXP,
    ETAT_POK_PLY,
    ETAT_POK_ADV,
    TEXT,
    POK_PLY,
    POK_ADV,
    NAME_ATT_1,
    NAME_ATT_2,
    NAME_ATT_3,
    NAME_ATT_4,
}obj_const_type_t;

typedef struct text_s
{
    int t_text;
    sfText *text;
    sfFont *font;
    sfColor color;
    sfVector2f pos;
}text_t;

typedef struct obj_const_s
{
    int type;
    pokename_t name;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *sprite;
    int status;
    text_t *txt;
    int stat;
    int max;
    struct obj_const_s *next;
}obj_const_t;

typedef struct prefab_obj_const_s
{
    int scene;
    data_pnj_t t_index;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    int status;
    sfVector2f dplc;
    unsigned int size;
    obj_const_type_t type;
    pokename_t name;
    pref_text_t text;
}prefab_obj_const_t;

// object const
obj_const_t *ini_obj_const(obj_const_t *li, texture_t *t, mod_t scene);
void list_obj_const_destroy(obj_const_t *obj);

// update
void obj_const_update(obj_const_t *obj, fight_data_t *f_data);
void obj_const_update_display(sfSprite *s, sfIntRect rect, int stat, int max);

// cange object
void change_obj_pv_player(obj_const_t *obj, fight_data_t *f_data);
void change_obj_pv_adv(obj_const_t *obj, fight_data_t *f_data);
void change_obj_name_pok_player(obj_const_t *obj, fight_data_t *f_data);
void change_obj_name_pok_adv(obj_const_t *obj, fight_data_t *f_data);
void change_obj_exp_pok(obj_const_t *obj, fight_data_t *f_data);
void change_obj_condition_pok_player(obj_const_t *obj, fight_data_t *f_data);
void change_obj_condition_pok_adv(obj_const_t *obj, fight_data_t *f_data);
void change_obj_text(obj_const_t *obj, fight_data_t *f_data);

// text
text_t *create_texte(unsigned int size, sfVector2f pos, int t_txt, sfFont *f);
void destroy_texte(text_t *txt);

// get
pokemon_t *get_current_pok(trainer_t *trainer);
int get_pv(pokemon_t *pok);
int get_pv_max(pokemon_t *pok);
char *get_name_pok(pokemon_t *pok);
int get_exp(pokemon_t *pok);
int get_exp_max(pokemon_t *pok);
char *get_status(pokemon_t *pok);

#endif
