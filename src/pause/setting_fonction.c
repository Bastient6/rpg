/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** setting_fonction
*/

#include "my.h"

void init_setting(game_t *game)
{
    game->setting = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    ("assets/pause/image.png", NULL);
    sfSprite_setTexture(game->setting, texture, sfTrue);
}

void setting_fonction(game_t *game)
{
    sfVector2f center = sfView_getCenter(game->view);
    int posx = (int)center.x - 217 / 2;
    int posy = (int)center.y - 116 / 2;
    sfSprite_setPosition(game->setting, (sfVector2f){posx, posy});
    sfSprite_setScale(game->setting, (sfVector2f){2,2});
}
