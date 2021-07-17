/*
** EPITECH PROJECT, 2021
** music.c
** File description:
** fonction music
*/

#include "music.h"
#include "data_base.h"

music_t *ini_music(texture_t *drw)
{
    music_t *music = malloc(sizeof(struct music_s));

    music->play = 0;
    music->vol = 20;
    music->music = get_song(drw, RALPH);
    return (music);
}

void update_music(music_t *music, texture_t *drw)
{
    sfMusic_setLoop(music->music, 1);
    sfMusic_setVolume(music->music, music->vol);
    if (music->play == M_INI) {
        sfMusic_play(music->music);
        sfMusic_setVolume(music->music, music->vol);
        music->play = 4;
    }
    if (music->play == M_PLAY) {
        sfMusic_play(music->music);
        music->play = 4;
    }
    if (music->play == M_PAUSE)
        sfMusic_pause(music->music);
    if (music->play == M_END)
        sfMusic_stop(music->music);
}
