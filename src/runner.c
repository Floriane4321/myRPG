/*
** EPITECH PROJECT, 2021
** rpg.c
** File description:
** file for my_rpg
*/

#include <stdlib.h>
#include "gdata.h"
#include "m_event.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include "utility.h"
#include <stddef.h>
#include <SFML/Config.h>
#include "button.h"

player_t *player_creat(rpg_t *rpg);
button_list_t *ini_button(button_list_t *blist, texture_t *tex, mod_t scene);
sfTexture **loading_texture(void);
sfMusic **loading_song(void);
fight_data_t *fight_init(void);
void set_speview(level_t *lvl);
prefab_craft_t *init_all_craft(void);

void exit_g(level_t *lvl, event_t *even)
{
    even->close = 1;
}

level_t *init_lvl(rpg_t *rpg, level_t *lvl, const sfView *origin)
{
    for (int i = 0; i < NB_SCENE; i++) {
        lvl[i].blist = list_button_creat();
        lvl[i].blist = ini_button(lvl[i].blist, rpg->drw, i);
        lvl[i].entity = NULL;
        lvl[i].obj_const = ini_obj_const(lvl[i].obj_const, rpg->drw, i);
        lvl[i].game = sfView_copy(origin);
        lvl[i].ui = sfView_copy(origin);
    }
    set_speview(lvl);
    return (lvl);
}

texture_t *loading_pnj(void)
{
    texture_t *drw;

    drw = malloc(sizeof(struct texture_s));
    drw->pnj = loading_texture();
    drw->ogg = loading_song();
    drw->font = sfFont_createFromFile("image/ARIAL.TTF");
    return (drw);
}

rpg_t *rpg_create(const sfView *origin)
{
    rpg_t *rpg = malloc(sizeof(struct rpg_s));

    rpg->drw = loading_pnj();
    rpg->lvl = malloc(sizeof(struct level_s) * NB_SCENE);
    rpg->lvl = init_lvl(rpg, rpg->lvl, origin);
    rpg->player = player_creat(rpg);
    rpg->map = NULL;
    rpg->m_info = malloc(sizeof(map_info_t));
    rpg->obs_list = NULL;
    rpg->fight = fight_init();
    rpg->craft = init_all_craft();
    return (rpg);
}

void rpg_destroy(rpg_t *hunter)
{
    free(hunter);
}
