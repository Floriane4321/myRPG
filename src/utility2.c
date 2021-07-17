/*
** EPITECH PROJECT, 2021
** defender
** File description:
** utility2.C
*/

#include "my.h"
#include "utility.h"
#include <math.h>
#include <stdlib.h>

int cmp_vector(sfVector2f nb, sfFloatRect rect)
{
    if (nb.x >= rect.left && nb.x <= rect.left + rect.width &&
        nb.y >= rect.top && nb.y <= rect.top + rect.height)
        return (1);
    return (0);
}

int cmp_cord(sfVector2f nb1, sfVector2f nb2, float marge)
{
    if (nb1.x >= nb2.x - marge && nb1.x <= nb2.x + marge &&
        nb1.y >= nb2.y - marge && nb1.y <= nb2.y + marge)
        return (1);
    return (0);
}

int is_in_radius(sfVector2f tow, sfVector2f new, float range)
{
    float res = sqrt(powf(tow.y - new.y, 2) + powf(tow.x - new.x, 2));

    if (res < range)
        return (1);
    return (0);
}

int count_word(char *str, char sepa)
{
    int i = 0;
    int comp = 0;
    int tmp = 0;

    while (str[i] != '\0') {
        if (tmp == 0 && str[i] != sepa) {
            comp++;
            tmp = 1;
        } else if (tmp == 1 && str[i] == sepa)
            tmp = 0;
        i++;
    }
    return (comp);
}

char **parc_word(char *str, char sepa)
{
    int len = count_word(str, sepa);
    char **new = malloc(sizeof(char *) * (1 + len));
    int tmp = 0;
    int old = 0;

    new[len] = NULL;
    for (int i = 0; i < len; i++) {
        while (str[tmp] != sepa && str[tmp] != '\0')
            tmp++;
        new[i] = malloc(sizeof(char) * (1 + tmp - old));
        new[i] = my_strncpy(new[i], &str[old], tmp - old);
        new[i][tmp - old] = '\0';
        tmp++;
        old = tmp;
    }
    return (new);
}
