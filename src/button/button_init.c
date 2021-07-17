/*
** EPITECH PROJECT, 2021
** button_init.c
** File description:
** button_ini for each sesion
*/

#include "button.h"
#include "gdata.h"
#include "utility.h"
#include "m_event.h"

void exit_g(level_t *lvl, event_t *even, button_t *but);
void gt_mode_one(level_t *lvl, event_t *even, button_t *but);
void gt_mode_three(level_t *lvl, event_t *even, button_t *but);
void gt_menu(level_t *lvl, event_t *even, button_t *but);
void gt_pause(level_t *lvl, event_t *even, button_t *but);
void gt_mode_end(level_t *lvl, event_t *even, button_t *but);
void gt_mode_inventory(level_t *lvl, event_t *even, button_t *but);
void play_music(level_t *lvl, event_t *even, button_t *but);
void vol_music(level_t *lvl, event_t *even, button_t *but);
void keybordset_left(level_t *lvl, event_t *even, button_t *but);
void keybordset_right(level_t *lvl, event_t *even, button_t *but);
void keybordset_top(level_t *lvl, event_t *even, button_t *but);
void keybordset_down(level_t *lvl, event_t *even, button_t *but);
void drag_click(level_t *lvl, event_t *even, button_t *but);
void click_drag(level_t *lvl, event_t *even, button_t *but);
void swap_view_l(level_t *lvl, event_t *even, button_t *zip);
void swap_view_r(level_t *lvl, event_t *even, button_t *zip);
void pok_attack(level_t *lvl, event_t *even, button_t *but);
void pok_choise(level_t *lvl, event_t *even, button_t *but);
void pok_escape(level_t *lvl, event_t *even, button_t *but);
void attack_1(level_t *lvl, event_t *even, button_t *but);
void attack_2(level_t *lvl, event_t *even, button_t *but);
void attack_3(level_t *lvl, event_t *even, button_t *but);
void attack_4(level_t *lvl, event_t *even, button_t *but);
void ret_fct(level_t *lvl, event_t *even, button_t *but);
void drag_craft_s2(level_t *lvl, event_t *even, button_t *ziip);
void drag_craft_s1(level_t *lvl, event_t *even, button_t *ziip);
void click_craft(level_t *lvl, event_t *even, button_t *but);
sfTexture *get_textur(texture_t *drw, data_pnj_t type);
void ret_fsct(level_t *lvl, event_t *even, button_t *but);
sfText *text_create(char *str, sfVector2f pos, sfFont *font);
item_t *init_item(button_t *but, char *name);
void wind_resiz_low(level_t *lvl, event_t *even, button_t *but);
void wind_resiz_med(level_t *lvl, event_t *even, button_t *but);
void wind_resiz_hig(level_t *lvl, event_t *even, button_t *but);
void change_color_text(button_list_t *blist, mod_t scene);
    
/* 
///order of data///
   scene(mod_t), texture(data_pnj_t), type of button(button_type_e,
   text(char *), rectangl of textur, statu (animation eta), scale, nbr_anim,
   delay(betwen 2 anim), pos, fonction_action.
*/
const prefab_button_t prefab_button[] = {
    {MENU, TSTOP, STATIC, "", {0, 0, 32, 32}, 0, {1, 1}, 0, 1.0,
    {1245, 3}, {0, 0}, (gt_mode_end)},
    {MENU, TGAME, FULL, "", {0, 0, 805, 255}, 0, {0.3, 0.3}, 4, 2.0,
    {130, 220}, {0, 0},(gt_mode_one)},
    {MENU, TSETTING, STATIC, "", {0, 0, 1180, 1140}, 0, {0.1, 0.1}, 0, 1.0,
    {0, 0}, {0, 0}, (gt_mode_three)},
    {MENU, TMENU, STATIC, "", {0, 0, 2909, 1915}, 0, {0.35, 0.35}, 0, 2.0,
    {0, 0}, {0, 0}, (ret_fct)},
    {MODE1, TSETTING, STATIC, "", {0, 0, 1180, 1140}, 0, {0.05, 0.05}, 0, 1.0,
    {-60, 0}, {0, 0}, (gt_mode_three)},
    {MODE1, TPAUSE, STATIC, "", {0, 0, 200, 208}, 0, {0.3, 0.3}, 0, 1.0,
    {-1285, -5}, {0, 0}, (gt_pause)},
    {PAUSE, TBACK_MENU, STATIC, "", {0, 0, 509, 124}, 0, {0.9, 0.9}, 0, 1.0,
    {420, 300}, {0, 0}, (gt_menu)},
    {PAUSE, TCONTINUE, STATIC, "", {0, 0, 556, 110}, 0, {0.9, 0.9}, 0, 1.0,
    {400, 420}, {0, 0}, (gt_mode_one)},
    {PAUSE, TQUIT, STATIC, "", {0, 0, 294, 108}, 0, {0.9, 0.9}, 0, 1.0,
    {500, 540}, {0, 0}, (exit_g)},
    {PAUSE, TMENU_PAUSE, STATIC, "", {63, 105, 1094, 1434}, 0, {0.8, 0.6}, 0,
    1.0, {270, 0}, {0, 0}, (ret_fct)},
    {OPTION, TRETOUR, STATIC, "", {0, 0, 100, 100}, 0, {0.8, 0.8}, 0, 1.0,
    {0, 0}, {-2560, 0}, (gt_menu)},
    {OPTION, TPOKEBAG, STATIC, "", {259, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {100, 20}, {0, 0}, (swap_view_l)},
    {OPTION, TPOKEBAG, STATIC, "", {284, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {1180, 20}, {0, 0}, (swap_view_r)},
    {OPTION, TCADRRE, STATIC, "", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {400, 330}, {0, 0}, (wind_resiz_low)},
    {OPTION, TCADRRE, STATIC, "", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {530, 330}, {0, 0}, (wind_resiz_med)},
    {OPTION, TCADRRE, STATIC, "", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {660, 330}, {0, 0}, (wind_resiz_hig)},
    {OPTION, TPOKEBAG, STATIC, "", {259, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {-1180, 20}, {0, 0}, (swap_view_l)},
    {OPTION, TPOKEBAG, STATIC, "", {284, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {-100, 20}, {0, 0}, (swap_view_r)},
    {OPTION, TRETOUR, STATIC, "", {0, 0, 100, 100}, 0, {0.8, 0.8}, 0, 1.0,
    {-1280, 0}, {-2560, 0}, (gt_menu)},
    {OPTION, TCASE, SPE, "", {0, 0, 330, 360}, 0, {0.35, 0.35}, 2, 1.0,
    {-700, 400}, {0, 0}, (play_music)},
    {OPTION, TBAR, SPE, "", {0, 0, 1000, 200}, 4, {0.35, 0.35}, 10, 1.0,
    {-674, 335}, {0, 0}, (vol_music)},
    {OPTION, TBACK_MENU2, STATIC, "", {0, 0, 1065, 250}, 0, {0.35, 0.35}, 0,
    1.0, {-843, 550}, {0, 0}, (gt_menu)},
    {MODE1, TCADRRE, STATIC, "CRAFT", {0, 0, 128, 64}, 0, {1.2, 1.2}, 0, 1.0,
    {-1280, 640}, {-1280, 650}, (gt_mode_inventory)},
    {OPTION, TMUSIC, STATIC, "", {0, 140, 2000, 2508}, 0, {0.35, 0.35}, 0, 1.0,
    {-1000, 0}, {0, 0}, (ret_fct)},
    {OPTION, TRETOUR, STATIC, "", {0, 0, 100, 100}, 0, {0.8, 0.8}, 0, 1.0,
    {-2560, 0}, {-2560, 0}, (gt_menu)},
    {OPTION, TCADRE, STATIC, "left", {0, 0, 736, 739}, 0, {0.2, 0.15}, 0, 1.0,
    {-2170, 200}, {-2150, 220}, (keybordset_left)},
    {OPTION, TCADRE, STATIC, "righ", {0, 0, 736, 739}, 0, {0.2, 0.15}, 0, 1.0,
    {-2170, 320}, {-2150, 340}, (keybordset_right)},
    {OPTION, TCADRE, STATIC, "top", {0, 0, 736, 739}, 0, {0.2, 0.15}, 0, 1.0,
    {-2170, 440}, {-2150, 460}, (keybordset_top)},
    {OPTION, TCADRE, STATIC, "down", {0, 0, 736, 739}, 0, {0.2, 0.15}, 0, 1.0,
    {-2170, 560}, {-2150, 580}, (keybordset_down)},
    {OPTION, TPOKEBAG, STATIC, "", {259, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {-2460, 20}, {-2560, 0}, (swap_view_l)},
    {OPTION, TPOKEBAG, STATIC, "", {284, 25, 9, 14}, 0, {4, 4}, 0, 1.0,
    {-1380, 20}, {0, 0}, (swap_view_r)},
    {FIGHT, TCADRE, STATIC, "Attaque", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {100, 450}, {120, 450}, (pok_attack)},
    {FIGHT, TCADRE, STATIC, "Pokemon", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {100, 525}, {120, 525}, (pok_choise)},
    {FIGHT, TCADRE, STATIC, "Fuite", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {100, 600}, {120, 600}, (pok_escape)},
    {FIGHT, TCADRE, STATIC, "", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {-1180, 450}, {120, 450}, (attack_1)},
    {FIGHT, TCADRE, STATIC, "", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {-1180, 600}, {120, 525}, (attack_2)},
    {FIGHT, TCADRE, STATIC, "", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {-900, 450}, {120, 600}, (attack_3)},
    {FIGHT, TCADRE, STATIC, "", {0, 0, 736, 739}, 0, {0.35, 0.1}, 0, 1.0,
    {-900, 600}, {120, 600}, (attack_4)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {64, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {208, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {352, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {496, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {640, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {784, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {928, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {1072, 100}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {64, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {208, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {352, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {496, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {640, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {784, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {928, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {1072, 200}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {64, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {208, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {352, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {496, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {640, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {784, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {928, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {1072, 300}, {0, 0}, (drag_click)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {200, 400}, {0, 0}, (drag_craft_s1)},
    {INVENTORY, TCADRE, ZIP, "", {0, 0, 736, 739}, 0, {0.179, 0.087}, 0, 1.0,
    {350, 400}, {0, 0}, (drag_craft_s2)},
    {INVENTORY, TCADRRE, STATIC, "", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {300, 500}, {0, 0}, (click_craft)},
    {INVENTORY, TCADRRE, DRAG, "yolo", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {900, 600}, {0, 0}, (click_drag)},
    {INVENTORY, TCADRRRRE, DRAG, "test", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {900, 300}, {0, 0}, (click_drag)},
    {INVENTORY, TCADRRRE, DRAG, "", {0, 0, 128, 64}, 0, {1, 1}, 0, 1.0,
    {900, 0}, {0, 0}, (click_drag)},
    {END, TLOUTRE, STATIC, "GAME OVER", {0, 0, 800, 700}, 0, {1.7, 1.5}, 0, 7.0,
    {0, 0}, {0, 0}, (exit_g)},
};

void ret_fct(level_t *lvl, event_t *even, button_t *but)
{
    return;
}

void gt_mode_one(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = MODE1;
}

void gt_menu(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = MENU;
}

void gt_pause(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = PAUSE;
}

button_list_t *ini_button(button_list_t *blist, texture_t *tex, mod_t scene)
{
    button_t *but;

    for (int i = 0; i < NBMAX_BUTTON; i++) {
        if ((mod_t)prefab_button[i].scene == scene) {
            but = button_creat(prefab_button[i].base,
            get_textur(tex, prefab_button[i].t_index),
            prefab_button[i].pos, prefab_button[i].size);
            (but->action) = prefab_button[i].action;
            but->status = prefab_button[i].statu;
            but->nbr_anim = prefab_button[i].nbr_anim;
            but->delay = prefab_button[i].delay;
            but->type = prefab_button[i].type;
            but->text = text_create(prefab_button[i].text,
            prefab_button[i].tpos, tex->font);
            but->item = init_item(but, "WOOD");
            blist = add_button(blist, but);
        }
        change_color_text(blist, scene);
    }
    return (blist);
}
