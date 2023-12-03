/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** button_option
*/

#ifndef BUTTON_OPTION_H_
    #define BUTTON_OPTION_H_
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include "my.h"

typedef struct button_option_s{
    sfVector2f pos;
    sfVector2f size;
    void (*callback)(game_t *game);
}button_option_t;

void moins(game_t *game);
void plus(game_t *game);
void coupe(game_t *game);
void help(game_t *game);

const button_option_t button_option[] = {
    { { 1071, 246}, { 60, 60 }, &moins },
    { { 1071, 131 }, { 60, 60 }, &plus },
    { { 1071, 353 }, { 60, 60 }, &coupe },
    { { 1071, 462 }, { 60, 60 }, &help },
};

#endif /* !BUTTON_OPTION_H_ */
