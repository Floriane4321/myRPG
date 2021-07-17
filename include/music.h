/*
** EPITECH PROJECT, 2021
** music.h
** File description:
** header music
*/

#ifndef MUSIC_H
#define MUSIC_H

#include "data_base.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include <stdlib.h>

typedef enum music_mode_s
{
    M_INI,
    M_PLAY,
    M_PAUSE,
    M_END,
}music_mode_t;

typedef struct music_s
{
    sfMusic *music;
    int play;
    float vol;
}music_t;

sfMusic *get_song(texture_t *drw, data_ogg_t type);
void update_music(music_t *music, texture_t *drw);
music_t *ini_music(texture_t *drw);

#endif
