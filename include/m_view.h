/*
** EPITECH PROJECT, 2021
** m_view.h
** File description:
** header for my view manager
*/

#ifndef M_VIEW_H_
#define M_VIEW_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>

typedef struct m_view_s
{
    sfView *view;
    sfView *minimap;
    sfFloatRect viewport;
}m_view_t;

#endif
