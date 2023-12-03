/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** event_gestion
*/

#include "my.h"
#include "load_file.h"

void actu_player(game_t *game)
{
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfView_setCenter(game->view, game->player->pos);
    if (game->player->pos.x >= (int)300 &&
    game->player->pos.x <= 500 && game->player->pos.y <= (int)80)
        if (game->event.key.code == sfKeySpace) {
            game->state = lopotipoucet;
        }
    if (game->player->pos.x >= (int)2805 && game->player->pos.y >= (int)-5
    && game->player->pos.x <= 2930 && game->player->pos.y <= 3)
        if (game->event.key.code == sfKeySpace) {
            game->old_state = lopotitchaperon;
            game->state = lopotitchaperon;
    }
    if (game->player->pos.x >= (int)210 && game->player->pos.y >= (int)2000 )
        if (game->event.key.code == sfKeySpace) {
            game->old_state = lopoticochon;
            game->state = lopoticochon;
    }
}

void event_gestion_bis(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyE && game->state == INVENTORY) {
            game->state = game->old_state; return;
        }
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyE) {
            game->old_state = game->state; game->state = INVENTORY;
        }
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyP) {
            game->state = PAUSE;return;
        }
    if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyTab)
            game->state = GAME;
        if (game->event.type == sfEvtKeyPressed
        && game->event.key.code == sfKeyP && game->state == PAUSE ){
            game->state = GAME; return;
        }
}

void event_gestion(game_t *game, list_t *list)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            sfMusic_stop(game->music);
            sfMusic_destroy(game->music);
            sfRenderWindow_close(game->window);
        }
        if (game->event.type == sfEvtKeyPressed &&
        game->event.key.code == sfKeyEscape)
            game->state = game->old_state;
        if (game->state == INVENTORY)
            inventory_event(game, list);
        if (game->state == lopotipoucet)
            lopotipoucet_event(game);
        event_gestion_bis(game);
        event_map(game, list);
    }
}

void items(game_t *game, list_t *list)
{
    sfVector2f pos = sfSprite_getPosition(game->player->sprite);
    for (map_t *item = game->history->list->map; item != NULL;
    item = item->next)
        if (pos.x >= item->pos.x - 100 && pos.x <= item->pos.x + 100 &&
        pos.y >= item->pos.y - 100 && pos.y <= item->pos.y + 100)
            jsp(game, list, item);
}
