/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** init_pause
*/

#include "button.h"

void init_pause(game_t *game)
{
    game->pause->play = sfSprite_create();
    game->pause->option = sfSprite_create();
    game->pause->quit = sfSprite_create();
    game->pause->setting = sfSprite_create();
    sfSprite_setTexture(game->pause->play,
    sfTexture_createFromFile("assets/pause/play.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->option,
    sfTexture_createFromFile("assets/pause/option.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->quit,
    sfTexture_createFromFile("assets/pause/quit.png", NULL), sfTrue);
    sfSprite_setTexture(game->pause->setting,
    sfTexture_createFromFile("assets/pause/setting.png", NULL), sfTrue);
}

void set_sprite(game_t *game, int posx, int posy)
{
    sfSprite_setPosition(game->pause->play, (sfVector2f){posx, posy - 80});
    sfSprite_setScale(game->pause->play, (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->option, (sfVector2f){posx, posy - 160});
    sfSprite_setScale(game->pause->option, (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->quit, (sfVector2f){posx, posy - 240});
    sfSprite_setScale(game->pause->quit, (sfVector2f){2,2});
    sfSprite_setPosition(game->pause->setting, (sfVector2f){posx, posy});
    sfSprite_setScale(game->pause->setting, (sfVector2f){2,2});
}

void pause_fonction(game_t *game)
{
    sfVector2f center = sfView_getCenter(game->view);
    int posx = (int)center.x - 75 / 2;
    int posy = (int)center.y - 75 / 2;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    set_sprite(game, posx, posy);
    if (game->event.type != sfEvtMouseButtonPressed)
        return;
    for (int i = 0; i < 4; i++) {
        button_t button = button_list[i];
        if (game->full == 1){
            button.pos.x += 44;
            button.pos.y += 30;
        }
        if (pos.x >= button.pos.x && pos.x <= button.pos.x + button.size.x
        && pos.y >= button.pos.y && pos.y <= button.pos.y + button.size.y)
            button.callback(game);
    }
}
