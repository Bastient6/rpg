/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
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

typedef struct button_start_s{
    sfVector2f pos;
    sfVector2f size;
    void (*callback)(game_t *game);
}button_start_t;

void resume(game_t *game);
void quit(game_t *game);
void setting(game_t *game);

const button_start_t button_start_list[] = {
    { { 850, 450}, { 130, 60 }, &resume },
    { { 850, 550 }, { 130, 60 }, &quit },
    { { 850, 650 }, { 130, 60 }, &setting },
};


#endif /* !BUTTON_H_ */
