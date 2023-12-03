/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** option
*/

#include "button_option.h"

void init_option(game_t *game)
{
    game->pause->option_button->volume_c = sfSprite_create();
    game->pause->option_button->volume_m = sfSprite_create();
    game->pause->option_button->volume_p = sfSprite_create();
    game->pause->option_button->point = sfSprite_create();
    sfSprite_setTexture(game->pause->option_button->volume_c,
    sfTexture_createFromFile("assets/pause/volume_c.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->option_button->volume_m,
    sfTexture_createFromFile("assets/pause/volume_m.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->option_button->volume_p,
    sfTexture_createFromFile("assets/pause/volume_p.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->option_button->point,
    sfTexture_createFromFile("assets/pause/point.png", NULL), sfTrue);
}

void set_sprite_option(game_t *game, int posx, int posy)
{
    sfSprite_setPosition(game->pause->option_button->volume_c,
    (sfVector2f){posx + 130, posy - 80});
    sfSprite_setScale(game->pause->option_button->volume_c,
    (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->option_button->volume_m,
    (sfVector2f){posx + 130, posy - 160});
    sfSprite_setScale(game->pause->option_button->volume_m,
    (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->option_button->volume_p,
    (sfVector2f){posx + 130, posy - 240});
    sfSprite_setScale(game->pause->option_button->volume_p, (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->option_button->point,
    (sfVector2f){posx + 130, posy});
    sfSprite_setScale(game->pause->option_button->point, (sfVector2f){2,2});
}

void option_fonction(game_t *game)
{
    sfVector2f center = sfView_getCenter(game->view);
    int posx = (int)center.x - 75 / 2, posy = (int)center.y - 75 / 2;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    set_sprite_option(game, posx, posy);
    if (game->event.type != sfEvtMouseButtonPressed)
        return;
    for (int i = 0; i < 4; i++) {
        button_option_t button = button_option[i];
        if (game->full == 1){
            button.pos.x += 42;
            button.pos.y += 16;
        }
        if (pos.x >= button.pos.x && pos.x <= button.pos.x + button.size.x
        && pos.y >= button.pos.y && pos.y <= button.pos.y + button.size.y)
            button.callback(game);
    }
}
