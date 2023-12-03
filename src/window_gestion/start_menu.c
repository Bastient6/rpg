/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** start_menu
*/

#include "my.h"
#include "button_start.h"

void init_start(game_t *game)
{
    game->start = malloc(sizeof(start_t));
    game->start->new_game = sfSprite_create();
    game->start->quit = sfSprite_create();
    game->start->setting = sfSprite_create();
    sfSprite_setTexture(game->start->new_game,
    sfTexture_createFromFile("assets/pause/play.png", NULL), sfTrue);
    sfSprite_setTexture(game->start->quit,
    sfTexture_createFromFile("assets/pause/quit.png", NULL), sfTrue);
    sfSprite_setTexture(game->start->setting,
    sfTexture_createFromFile("assets/pause/setting.png", NULL), sfTrue);
    sfSprite_setScale(game->start->new_game, (sfVector2f){2,2});
    sfSprite_setScale(game->start->quit, (sfVector2f){2,2});
    sfSprite_setScale(game->start->setting, (sfVector2f){2,2});
}

void loop_menu(game_t *game, sfVector2i pos)
{
    for (int i = 0; i < 4; i++) {
        button_start_t button = button_start_list[i];
        if (game->full == 1){
            button.pos.x += 44;
            button.pos.y += 30;
        }
        if (pos.x >= button.pos.x && pos.x <= button.pos.x + button.size.x
            && pos.y >= button.pos.y && pos.y <= button.pos.y + button.size.y)
            button.callback(game);
    }
}

void start_menu(game_t *game)
{
    while (game->state == START) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfSprite_setPosition(game->start->new_game, (sfVector2f){850, 450});
        sfSprite_setPosition(game->start->quit, (sfVector2f){850, 550});
        sfSprite_setPosition(game->start->setting, (sfVector2f){850, 650});
        sfRenderWindow_drawSprite(game->window, game->start->new_game, NULL);
        sfRenderWindow_drawSprite(game->window, game->start->quit, NULL);
        sfRenderWindow_drawSprite(game->window, game->start->setting, NULL);
        sfRenderWindow_display(game->window);
        sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            if (game->event.type == sfEvtMouseButtonPressed)
                loop_menu(game, pos);
        }
    }
}
