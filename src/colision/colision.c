/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** colision
*/

#include "my.h"

char **load_char(char **dest, char *src)
{
    int i = 0;
    int y = 0;
    int x = 0;
    for (; src[i] != '\0'; i++){
        if (src[i] == '\n'){
            dest[y][x] = '\0';
            y++;
            x = 0;
        } else {
            dest[y][x] = src[i];
            x++;
        }
    }
    return dest;
}

char **load_2d_tabl(char *src, game_t *game)
{
    int i = 0;
    int y = 0;
    int x = 0;
    for (; src[i] != '\0'; i++){
        if (src[i] == '\n')
            y++;
    }
    game->map_y = y;
    char **dest = malloc(sizeof(char *) * (y + 1));
    dest[y] = NULL;
    int j = 0;
    for (int i = 0; src[i] != 0; i++){
        if (src[i] == '\n'){
            game->map_x = x;
            dest[j] = malloc(sizeof(char) * (x + 1));
            x = 0;
            j++;
        }
        x++;
    }return dest;
}

char **read_file(char const * filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    struct stat a;
    stat(filepath, &a);
    int size = a.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    char **dest = load_2d_tabl(buffer, game);
    dest = load_char(dest, buffer);
    char **dest2 = my_str_to_word_array(dest[0], ',');
    for (int i = 0; dest2[i] != NULL; i++){
        game->map_x = i;
    }
    close(fd);
    return dest;
}
