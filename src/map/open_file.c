/*
** EPITECH PROJECT, 2021
** bootstrap_sokoban
** File description:
** open_file
*/

#include "map.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int open_init(char *filepath, int fd)
{
    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        my_putstr_error("FILE CANNOT BE OPENED\n");
        return (fd);
    }
    return (fd);
}

int stat_init(char *filepath, int s, int *file_size)
{
    struct stat file_info;

    s = stat(filepath, &file_info);
    if (s < 0) {
        my_putstr_error("FILE CANNOT BE OPENED\n");
        return (s);
    }
    *file_size = file_info.st_size;
    return (s);
}

int read_init(int fd, int file_size, char **buffer)
{
    int r = 0;
    char *str = malloc(sizeof(char) * (file_size + 1));

    r = read(fd, str, file_size);
    if (r < 0) {
        my_putstr_error("UNREADABLE FILE\n");
        return (r);
    }
    str[file_size] = '\0';
    *buffer = str;
    return (r);
}

char *open_file(char *filepath)
{
    int fd = 0;
    int s = 0;
    int r = 0;
    int file_size = 0;
    char *buffer = NULL;

    fd = open_init(filepath, fd);
    if (fd < 0)
        return (NULL);
    s = stat_init(filepath, s, &file_size);
    if (s < 0)
        return (NULL);
    r = read_init(fd, file_size, &buffer);
    if (r < 0)
        return (NULL);
    return (buffer);
}