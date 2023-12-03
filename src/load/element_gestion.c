/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** element_gestion
*/

#include <my.h>

void add_item_on_map(listellement_t *list, char **data)
{
    map_t *tmp = list->map;
    map_t *new;
    int b = 0;
    if (list->map == NULL) {
        list->map = malloc(sizeof(map_t));
        new = list->map;
        b = 1;
    } else
        new = malloc(sizeof(map_t));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(data[3], NULL);
    new->pos.x = my_getnbr(data[1]); new->pos.y = my_getnbr(data[2]);
    new->name = my_strdup(data[0]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    if (b == 0) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    } new->next = NULL;
}

void add_pnj_on_map(listellement_t *list, char **data)
{
    perso_t *tmp = list->perso;
    perso_t *new; int b = 0;
    if (list->perso == NULL) {
        list->perso = malloc(sizeof(perso_t));
        new = list->perso;
        b = 1;
    } else
    new = malloc(sizeof(perso_t));
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(data[3], NULL);
    new->pos.x = my_getnbr(data[1]); new->pos.y = my_getnbr(data[2]);
    new->name = my_strdup(data[0]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setScale(new->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(new->sprite, new->pos);
    if (b == 0) {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    } new->next = NULL;
}

void add_dial_on_last_pnj(listellement_t *list, char **data)
{
    perso_t *tmp = list->perso;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->dialogue = data;
}

void set_map(game_t *game, char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    game->history->map = sprite;
}
