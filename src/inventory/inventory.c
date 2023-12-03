/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** inventory
*/

#include "my.h"
#include "load_file.h"

void reset_map(inventaire_t *tmp, game_t *game, list_t *list)
{
    if (tmp->box == game->box) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
        tmp->box = is_a_box(mouse.x, mouse.y);
        if (tmp->box == 0) {
            tmp->box = game->box;
            sfSprite_setPosition(tmp->sprite, list->boxs[game->box - 1]);
        }
        sfSprite_setPosition(tmp->sprite, list->boxs[tmp->box - 1]);
    }
}

void inventory_event(game_t *game, list_t *list)
{
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    int posx = (int)center.x - (int)size.x / 2;
    int posy = (int)center.y - (int)size.y / 2;
    sfSprite_setPosition(list->inventory, (sfVector2f){posx + 300, posy + 80});
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if (game->event.mouseButton.type == sfEvtMouseButtonPressed &&
    game->box == 0) {
        game->box = is_a_box(mouse.x, mouse.y);
    }
    if (game->event.mouseButton.type == sfEvtMouseButtonReleased) {
        for (inventaire_t *tmp = list->first; tmp != NULL; tmp = tmp->next)
            reset_map(tmp, game, list);
        game->box = 0;
    }
}

void set_position_item(inventaire_t *tmp, game_t *game, sfVector2i p)
{
    if (tmp->box == game->box) {
        sfSprite_setPosition(tmp->sprite, (sfVector2f){p.x - 65, p.y - 25});
    }
}

void inventory(game_t *game, list_t *list)
{
    sfVector2f center = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    int posx = (int)center.x - (int)size.x / 2;
    int posy = (int)center.y - (int)size.y / 2;
    for (inventaire_t *tmp = list->first; tmp != NULL; tmp = tmp->next)
        sfSprite_setPosition(tmp->sprite, list->boxs[tmp->box]);
    if (game->box != 0) {
        sfVector2i p = sfMouse_getPositionRenderWindow(game->window);
        p.x += posx;
        p.y += posy;
        for (inventaire_t *tmp = list->first; tmp != NULL; tmp = tmp->next) {
            set_position_item(tmp, game, p);
        }
    }
}

void add_object_inventory(list_t *list, sfSprite *sprite,
sfTexture *texture, int box)
{
    inventaire_t *new = malloc(sizeof(inventaire_t));
    new->sprite = sprite;
    new->texture = texture;
    new->box = box;
    new->next = NULL;
    if (list->first == NULL) {
        list->first = new;
        list->last = new;
    } else {
        list->last->next = new;
        list->last = new;
    }
}
