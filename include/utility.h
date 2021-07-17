/*
** EPITECH PROJECT, 2021
** utility.c
** File description:
** file for usfull function
*/

#ifndef UTILITY_H
#define UTILITY_H
#include <SFML/Graphics.h>
sfIntRect set_rect(int top, int bot, int x, int y);
sfVector2i set_vector(int x, int y);
sfVector2f set_vecf(float x, float y);
int cmp_rect(sfIntRect base, sfIntRect new);
sfIntRect add_rect(sfIntRect base, sfIntRect mod);
int cmp_vector(sfVector2f nb, sfFloatRect rect);
int count_word(char *str, char sepa);
char **parc_word(char *str, char sepa);
#endif
