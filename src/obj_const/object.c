/*
** EPITECH PROJECT, 2021
** object.c
** File description:
** main fonction object
*/

#include "object.h"
#include "mylist_obj.h"

const prefab_obj_const_t prefab_obj_const[] = {
    {OPTION, TSKY2, {0, 0, 600, 337}, {2.14, 2.1}, {0, 0}, 1, {0, 0}, 0, VIDE,
    POK_VIDE, DVIDE},
    {OPTION, TBULLE, {0, 50, 498, 386}, {2, 3}, {150, 0}, 1, {-2110, 0}, 40,
    VIDE, POK_VIDE, DVIDE},
    {OPTION, TSKY2, {0, 0, 600, 337}, {2.14, 2.1}, {-1280, 0}, 1, {0, 0}, 0,
    VIDE, POK_VIDE, DVIDE},
    {OPTION, TSKY2, {0, 0, 600, 337}, {2.14, 2.1}, {-2560, 0}, 1, {0, 0}, 0,
    VIDE, POK_VIDE, DVIDE},
    {OPTION, TBULLE, {0, 50, 498, 386}, {2, 3}, {-2410, 0}, 1, {-2110, 0}, 40,
    VIDE, POK_VIDE, DKEYBOARD},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {-2270, 200}, 32, VIDE,
    POK_VIDE, DLEFT},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {-2270, 320}, 32, VIDE,
    POK_VIDE, DRIGHT},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {-2270, 440}, 32, VIDE,
    POK_VIDE, DTOP},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {-2270, 560}, 32, VIDE,
    POK_VIDE, DDOWN},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {400, 250}, 32, VIDE,
    POK_VIDE, DLOW},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {530, 250}, 32, VIDE,
    POK_VIDE, DMED},
    {OPTION, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {700, 250}, 32, VIDE,
    POK_VIDE, DHIG},
    {FIGHT, TBLANC, {0, 0, 1600, 950}, {1, 1}, {0, 0}, 1, {0, 0}, 0, VIDE,
    POK_VIDE, DVIDE},
    {FIGHT, TCADRE_FLECHE, {0, 0, 128, 64}, {2.5, 2}, {210, 50}, 1, {0, 0}, 0,
    VIDE, POK_VIDE, DVIDE},
    {FIGHT, TCADRE_FLECHE_D, {0, 0, 128, 64}, {2.5, 2}, {745, 275}, 1, {0, 0},
    0, VIDE, POK_VIDE, DVIDE},
    {FIGHT, TPOK_BANDE, {0, 0, 1280, 300}, {1, 1}, {0, 420}, 1, {0, 0}, 0,
    VIDE, POK_VIDE, DVIDE},
    {FIGHT, TPV, {0, 0, 150, 75}, {1, 1}, {800, 310}, 1, {25, 15}, 25,
    PV_POK_ADV, POK_VIDE, DVIDE},
    {FIGHT, TPV_CADRE, {0, 0, 150, 75}, {1, 1}, {800, 310}, 1, {0, 0}, 30,
    VIDE, POK_VIDE, DVIDE},
    {FIGHT, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {800, 250}, 50,
    NAME_POK_PLY, POK_VIDE, DVIDE},
    {FIGHT, TBULBA, {0, 0, 246, 246}, {2, 2}, {700, -240}, 0, {0, 0}, 0,
    POK_ADV, BULBASAUR, DVIDE},
    {FIGHT, TPV, {0, 0, 150, 75}, {1, 1}, {280, 90}, 1, {25, 15}, 25,
    PV_POK_PLY, POK_VIDE, DVIDE},
    {FIGHT, TPV_CADRE, {0, 0, 150, 75}, {1, 1}, {280, 90}, 1, {0, 0}, 30, VIDE,
    POK_VIDE, DVIDE},
    {FIGHT, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 1, {280, 30}, 50,
    NAME_POK_ADV, POK_VIDE, DVIDE},
    {FIGHT, TROUCOOL_D, {0, 0, 250, 250}, {1, 1}, {200, 175}, 0, {0, 0}, 0,
    POK_PLY, PICKACHU, DVIDE},
    {FIGHT, TBLANC, {0, 0, 0, 0}, {1, 1}, {0, 0}, 0, {120, 460}, 30, NAME_ATT_1,
    POK_VIDE, DVIDE},
};

obj_const_t *create_obj_const(texture_t *t, sfTexture *tex, int i)
{
    obj_const_t *obj = malloc(sizeof(struct obj_const_s));

    obj->type = prefab_obj_const[i].type;
    obj->rect = prefab_obj_const[i].rect;
    obj->scale = prefab_obj_const[i].scale;
    obj->pos = prefab_obj_const[i].pos;
    obj->status = prefab_obj_const[i].status;
    obj->stat = 1;
    obj->max = 1;
    obj->name = prefab_obj_const[i].name;
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, tex, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setScale(obj->sprite, obj->scale);
    obj->txt = create_texte(prefab_obj_const[i].size, prefab_obj_const[i].dplc,
    (int)prefab_obj_const[i].text, t->font);
    obj->next = NULL;
    return (obj);
}

obj_const_t *ini_obj_const(obj_const_t *li, texture_t *t, mod_t scene)
{
    obj_const_t *obj;

    li = NULL;
    for (int i = 0; i < NBMAX_OBJ_CONST; i++) {
        if ((mod_t)prefab_obj_const[i].scene == scene) {
            obj = create_obj_const
            (t, get_textur(t, prefab_obj_const[i].t_index), i);
            li = add_end_obj(li, obj);
        }
    }
    return (li);
}

void list_obj_const_destroy(obj_const_t *obj)
{
    obj_const_t *tmp;
    obj_const_t *now = obj;

    while (now != NULL) {
        tmp = now;
        sfSprite_destroy(now->sprite);
        destroy_texte(now->txt);
        now = now->next;
        free(tmp);
    }
}

void display_obj_const(sfRenderWindow *window, obj_const_t *obj)
{
    obj_const_t *tmp = obj;

    while (tmp != NULL) {
        if (tmp->status == 1) {
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
            sfRenderWindow_drawText(window, tmp->txt->text, NULL);
        }
        tmp = tmp->next;
    }
}
