/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window_gestion
*/

#include "my.h"

void modify_window(sfRenderWindow *window, int width, int height, int fps)
{
    if (width > 0 && height > 0)
        sfRenderWindow_setSize(window, (sfVector2u){width, height});
    if (fps > 0)
        sfRenderWindow_setFramerateLimit(window, fps);
}

sfRenderWindow *create_window_full(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(video_mode, "My_RPG", sfFullscreen | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setTitle(window, "My_RPG");
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}

sfRenderWindow *create_window(void)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window =
    sfRenderWindow_create(video_mode, "My_RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setTitle(window, "My_RPG");
    sfRenderWindow_setKeyRepeatEnabled(window, sfFalse);
    return (window);
}
