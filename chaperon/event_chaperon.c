/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** event_chaperon
*/

#include <my.h>
#include <load_file.h>

void chaperon_event(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    if (pos.x >= CP_PP_X && pos.x <= CP_PP_X + 100 && pos.y >= CP_PP_Y &&
    pos.y <= CP_PP_Y + 50)
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace) {
            game->state = CHAPERON;
            sfSprite_setPosition(game->player->sprite,
            (sfVector2f){800, 250});
            load_file(game, "assets/fichier_sys/chaperon_rouge.txt");
    }
}
