/*
** EPITECH PROJECT, 2020
** button.h
** File description:
** button header
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.h>
#include "data_base.h"

#define NBMAX_BUTTON 69
#define NB_CRAFT 4

typedef enum mode_e (mod_t);
typedef struct level_s (level_t);
typedef struct event_s (event_t);

typedef enum button_type_e
{
    STATIC,
    HEDEL,
    CLICK,
    FULL,
    SPE,
    DRAG,
    ZIP,
}button_type_t;

typedef struct prefab_craft_s
{
    char *first;
    char *second;
    char *res;
}prefab_craft_t;

typedef struct item_s
{
    char *name;
    struct button_s *link;
}item_t;

typedef struct button_s
{
    button_type_t type;
    sfSprite *button;
    sfVector2f mouse;
    sfVector2f pos;
    int status;
    float time;
    sfIntRect base;
    int print;
    sfVector2i rate_anim;
    int nbr_anim;
    float delay;
    sfText *text;
    item_t *item;
    struct button_s *blink;
    void (*action) (level_t *lvl, event_t *even, struct button_s *but);
    struct button_s *next;
}button_t;

typedef struct button_list_s
{
    int len;
    button_t *first;
}button_list_t;

/////////////////////////////////////////////////
/// \brief test 1 v 2
///
/// PRIVATE fonction
///
/////////////////////////////////////////////////
typedef struct prefab_button_s
{
    int scene;
    data_pnj_t t_index;
    button_type_t type;
    char *text;
    sfIntRect base;
    int statu;
    sfVector2f size;
    int nbr_anim;
    float delay;
    sfVector2f pos;
    sfVector2f tpos;
    void (*action) (level_t *lvl, event_t *even, struct button_s *but);
}prefab_button_t;

/////////////////////////////////////////////////
/// \brief create a button
/// 
/// \param set rectangle of the textur
/// \param pnj the textur
/// \param pos the position of the buton(left_top corner)
/// \param size the size ratio for scaling
///
/////////////////////////////////////////////////
button_t *button_creat(sfIntRect set, sfTexture *pnj, sfVector2f pos,
sfVector2f size);

void button_destroy(button_t *button);
void button_draw(sfRenderWindow *window, button_list_t *list);

button_list_t *list_button_creat(void);
void list_button_destroy(button_list_t *list);

////////////////////////////////////////////////
/// \brief add a button to the entity list
/// 
/// \param list .actual list
/// \param button the button to add
///
/// \return A ptr to the start of the list
/////////////////////////////////////////////////
button_list_t *add_button(button_list_t *list, button_t *button);
#endif
