/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** prompt
*/

#include "my.h"

void prompt(game_t *game)
{
    if (game->state != GAME) {
        sfVector2f center = sfView_getCenter(game->view);
        sfVector2f size = sfView_getSize(game->view);
        int px = (int)center.x - (int)size.x / 2;
        int py = (int)center.y - (int)size.y / 2;
        sfSprite_setPosition(game->hint, (sfVector2f){px, py});
        sfText_setPosition(game->text_hint, (sfVector2f){px + 60, py + 70});
        sfRenderWindow_drawSprite(game->window, game->hint, NULL);
        sfRenderWindow_drawText(game->window, game->text_hint, NULL);
    }
}
