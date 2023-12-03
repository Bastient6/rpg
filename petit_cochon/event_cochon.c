/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** chaperon_map
*/

#include "my.h"
#include "load_file.h"

void petit_cochon_event(game_t *game)
{
    draw_cochon(game);
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    if (pos.x >= CC_PP_X && pos.x <= CC_PP_X + 100 && pos.y >= CC_PP_Y &&
    pos.y <= CC_PP_Y + 50)
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace) {
            game->state = COCHON;
            sfSprite_setPosition(game->player->sprite,
            (sfVector2f){CC_PP_X + 100, CC_PP_Y});
            load_file(game, "assets/fichier_sys/petit_cochon.txt");
    }
}
