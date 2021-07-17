/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** start of game
*/

#include "my.h"
#include "gdata.h"
#include <stdlib.h>
#include "map.h"

char *reading_map(char const *path);

void slash_help(void)
{
    my_putstr("Usage: ./my_defender [map.text]\n ");
    my_putstr("\t Vous pouvez utiliser la touche ECHAPE de votre clavier \n");
    my_putstr("pour mettre en mode pause le jeu.\n");
    my_putstr("\tLe reste du jeux se joue a la souris tous les boutons sont ");
    my_putstr("fonctionnels meme avec le resize.");
    my_putstr("\nLe menu option vous permettra de choisir le volume.");
    my_putstr("\nles animations sont animes avec une sfclock");
    my_putstr("\n Le framerate est limite a 30.\n");
    my_putstr(" Le systeme de vague n'etant pas fonctionnel et pour le bien");
    my_putstr(" de la demonstration le jeux feras apparaitre tt les types de ");
    my_putstr("creature et vous permettra de placer autant de tour que  ");
    my_putstr("vous le voulez sans restriction.");
    my_putstr("\n Vous ne pourrez donc pas mourir ni gagner\n");
    my_putstr("\n chaque map est customisable,\n");
    my_putstr("le path et les entity sont customable grace au prefabe situee");
    my_putstr("dans les fichiers, src/entity/entity.c, pour les entity\n");
    my_putstr("quand au chemin des creatures vous pouvez le changer dans la");
    my_putstr("prefab flag_road dans le fichier src/creature/flag_creature.c");
    my_putstr("\nChaque image a ete faite a la main\n");
}

int main(int ac, char **av)
{
    map_t **map = NULL;
    char *buffer = NULL;

    if (ac != 2)
        return (84);
    if (ac == 2 && match(av[1], "-h") == 1) {
        slash_help();
        return (0);
    }
    buffer = open_file(av[1]);
    if (buffer == NULL)
        return (84);
    standar_mode(buffer);
    return (0);
}
