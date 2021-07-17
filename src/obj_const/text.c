/*
** EPITECH PROJECT, 2021
** text.c
** File description:
** fonction text
*/

#include "object.h"
#include <SFML/Graphics.h>

const char prefab_text[][50] = {
    "",
    "coucou\n",
    "tchous !\n",
    "Key_boardSetting:",
    "Left :",
    "Right :",
    "Top :",
    "Down :",
    "Low :",
    "Medium:",
    "Tall :",
};

text_t *create_texte(unsigned int size, sfVector2f pos, int t_txt, sfFont *font)
{
    text_t *txt = malloc(sizeof(struct text_s));

    txt->text = sfText_create();
    txt->font = font;
    sfText_setFont(txt->text, txt->font);
    txt->pos.x = pos.x;
    txt->pos.y = pos.y;
    txt->t_text = t_txt;
    sfText_setPosition(txt->text, txt->pos);
    sfText_setString(txt->text, prefab_text[txt->t_text]);
    sfText_setCharacterSize(txt->text, size);
    sfText_setFillColor(txt->text, sfRed);
    return (txt);
}

void destroy_texte(text_t *txt)
{
    sfText_destroy(txt->text);
    sfFont_destroy(txt->font);
    free(txt);
}

void change_obj_text(obj_const_t *obj, fight_data_t *f_data)
{
    sfText_setString(obj->txt->text, prefab_text[obj->txt->t_text]);
}
