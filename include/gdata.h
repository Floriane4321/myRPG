/*
** EPITECH PROJECT, 2020
** gdata.h
** File description:
** include for gdata
*/

#ifndef GDATA_H
#define GDATA_H

#include "rpg.h"
#include "map.h"

#define NB_SCENE 8

typedef struct rpg_s (rpg_t);
typedef struct event_s (event_t);
typedef struct music_s (music_t);

typedef enum mode_e
{
    MENU,
    OPTION,
    PAUSE,
    MODE1,
    END,
    FIGHT,
    INVENTORY,
}mod_t;

typedef struct gdata_s
{
    mod_t mode;
    void (*gameset[7]) (event_t *, rpg_t *, float);
    sfRenderWindow *window;
    const sfView *origin;
    event_t *m_event;
    rpg_t *rpg;
    sfClock *clock;
    sfTime delta;
    float memo;
    int status;
}gdata_t;

/////////////////////////////////////////////////
/// \brief create a struture gdata and init it to defautl valu
/////////////////////////////////////////////////
gdata_t *gdata_create();

/////////////////////////////////////////////////
/// \brief destroy game struct
///
/// \param data structure des donne
///
/////////////////////////////////////////////////
void gdata_destroy(gdata_t *data);

/////////////////////////////////////////////////
/// \brief first function of the game
///
/// \param map str read from file
///
/////////////////////////////////////////////////
int standar_mode();

/////////////////////////////////////////////////
/// \brief fonction who symbolise a scene,
///
/// fonction call in standar mode with a ptr fontion
/// \param event custom event of the game
/// \param data data of the game (rpg)
/// \param delta time elapse betwen the last loop
///
/////////////////////////////////////////////////
void gamemode_menu(event_t *event, rpg_t *data, float delta);
void game_sesion_one(event_t *event, rpg_t *data, float delta);
void game_end(event_t *event, rpg_t *data, float delta);
void gamemode_pause(event_t *event, rpg_t *data, float delta);
void gamemode_option(event_t *event, rpg_t *data, float delta);
void gamemode_fight(event_t *event, rpg_t *data, float delta);
void gamemode_inventory(event_t *event, rpg_t *data, float delta);

/////////////////////////////////////////////////
/// \brief lunch the general draw of the game
///
/// \param data data of all the game
///
/////////////////////////////////////////////////  
void draw_game(gdata_t *data);

#endif
