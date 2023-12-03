/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** event
*/

#include "my.h"
#include "load_file.h"

void event_forest(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    if (pos.x >= FOREST_PP_X && pos.x <= FOREST_PP_X + 100 && pos.y >=
    FOREST_PP_Y && pos.y <= FOREST_PP_Y + 50 && game->history->scene == FOREST)
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace) {
            game->history->scene = INF_FOREST;
            sfSprite_setPosition(game->player->sprite,
            (sfVector2f){FOREST_PP_X + 100, FOREST_PP_Y});
            load_file(game, "assets/fichier_sys/forestpoucet.txt");
        }
}

void draw(game_t *game)
{
    add_description("bienvenue dans la maison\nvous trouverez differents\n\
    artefacts dans les pieces\nbaladez vous pour les collecter\nquand vous\
    serez prets,\ndirigez vous vers la porte d'entree", game);
}

void draw_cochon(game_t *game)
{
    add_description("bienvenue dans la foret vous \ny trouverez differents\n\
    cochons.\nBaladez vous pour les \ncollecter ! Une fois fini, trouvez\nle \
    loup et tuez le !", game);
}

void lopotipoucet_event(game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    if (pos.x >= UF_PP_X && pos.x <= UF_PP_X + 100 && pos.y >= UF_PP_Y &&
    pos.y <= UF_PP_Y + 50 && game->history->scene == ROOM) {
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace) {
            game->history->scene = HOUSE;
            draw(game);
            load_file(game, "assets/fichier_sys/lopotipoucet/lopotipoucet.txt");
            game->player->pos = (sfVector2f){704, 64};
        }
    }
    if (pos.x >= HOUSE_PP_X && pos.x <= HOUSE_PP_X + 100 && pos.y >= HOUSE_PP_Y
    && pos.y <= HOUSE_PP_Y + 50 && game->history->scene == HOUSE) {
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeySpace) {
            game->history->scene = FOREST;
            load_file(game, "assets/fichier_sys/lopotipoucet/forest.txt");
            game->player->pos = (sfVector2f){FOREST_PP_X, FOREST_PP_Y};
        }
    }
}
