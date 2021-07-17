/*
** EPITECH PROJECT, 2021
** item.c
** File description:
** function loading craft
*/

#include "c_star.h"
#include "utility.h"
#include "button.h"
#include <stdlib.h>
#include "my.h"

void click_drag(level_t *lvl, event_t *even, button_t *but);
char *reading_map(char const *path);
sfText *text_create(char *str, sfVector2f pos, sfFont *font);
item_t *init_item(button_t *but, char *name);

prefab_craft_t *load_craft(char *str)
{
    int len = count_lign(str);
    prefab_craft_t *new = malloc(sizeof(prefab_craft_t) * (1 + len));
    char **word;
    char **parc = parc_word(str, '\n');

    for (int i = 0; i < len; i++) {
        word = parc_word(parc[i], ' ');
        new[i].first = word[0];
        new[i].second = word[1];
        new[i].res = word[2];
        free(word);
    }
    return (new);
}

prefab_craft_t *init_all_craft(void)
{
    char *str = reading_map("craft.txt");

    if (str != NULL)
        return (load_craft(str));
    my_putstr("can't read");
    return (NULL);
}

button_list_t *new_item(button_list_t *blist, texture_t *tex, char *item)
{
    button_t *but;
    sfIntRect base = {0, 0, 128, 64};
    sfVector2f size = {1, 1};
    sfVector2f pos = {0, 0};

    but = button_creat(base, get_textur(tex, TCADRRE), pos, size);
    (but->action) = (click_drag);
    but->status = 0;
    but->nbr_anim = 0;
    but->delay = 1;
    but->type = DRAG;
    but->text = text_create("", pos, tex->font);
    but->item = init_item(but, item);
    blist = add_button(blist, but);
    return (blist);
}

int matching_craft(prefab_craft_t *str, char *s1, char *s2)
{
    if (my_strcmp(str->first, s1) == 0) {
        if (my_strcmp(str->second, s2) == 0) {
            return (1);
        }
    }
    return (0);
}

char *find_craft(prefab_craft_t *fab, item_t *s1, item_t *s2)
{
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    for (int i = 0; i < NB_CRAFT - 1; i++) {
        if (matching_craft(&fab[i], s1->name, s2->name) == 1)
            return (fab[i].res);
    }
    return (NULL);
}
