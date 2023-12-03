/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** event_map
*/

#include "my.h"

int da_box(list_t *list, int box)
{
    for (inventaire_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->box == box)
            return -1;
    }
    return 0;
}

int find_box(list_t *list)
{
    for (int i = 0; i < 30; i++) {
        if (da_box(list, i) == 0)
            return i;
    }
    return -1;
}

void delete_item(game_t *game, map_t *item)
{
    map_t *tmp = game->history->list->map;
    map_t *delete;
    if (tmp == item) {
        delete = tmp;
        game->history->list->map = tmp->next;
        free(delete);
        return;
    }
    for (; tmp->next != item; tmp = tmp->next);
    delete = tmp->next;
    tmp->next = item->next;
    free(delete);
}

void jsp(game_t *game, list_t *list, map_t *item)
{
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyA) {
        if (list->first == NULL) {
            add_object_inventory(list, item->sprite, item->texture, 0);
            return;
        }
        int box = find_box(list);
        if (box != -1) {
            add_object_inventory(list, item->sprite, item->texture, box);
            delete_item(game, item);
        }
        if (box == -1)
            add_description("Inventaire plein", game);
    }
}

void event_map(game_t *game, list_t *list)
{
    if (game->state == lopotitchaperon) {
        chaperon_event(game);
    }
    if (game->state == lopoticochon)
        petit_cochon_event(game);
    items(game, list);
}
