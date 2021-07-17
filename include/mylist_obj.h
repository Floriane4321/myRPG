/*
** EPITECH PROJECT, 2020
** mylist.h
** File description:
** name fonction
*/

#ifndef MYLIST_OBJ_H
#define MYLIST_OBJ_H

#include <stddef.h>
#include "object.h"

typedef struct list_s
{
    char *data;
    char **av;
    char *rdc;
    int status;
    struct list_s *next;
}list_t;

list_t *my_params_to_list(int ac, char *const *av);

int my_list_size(obj_const_t *begin);
void put_list(list_t *list);
obj_const_t *create_cell(char *data, char *rdc);
obj_const_t *addcell(obj_const_t *list, int i, char *data, char *rdc);
obj_const_t *free_cell(obj_const_t *list, int i);
void free_list(obj_const_t *list);

obj_const_t *reverse(obj_const_t *list);
obj_const_t *add_begin(obj_const_t *list, obj_const_t *cell);
obj_const_t *add_end_obj(obj_const_t *list, obj_const_t *cell);
obj_const_t *unlike_beggin(obj_const_t *list, obj_const_t *cell);

list_t *transform_2_array_in_list(char **str);
char **transform_list_in_2_array(list_t *list);

#endif
