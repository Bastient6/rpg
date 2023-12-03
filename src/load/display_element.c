/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** display_element
*/

#include "load_file.h"

void display_element(sfRenderWindow *window, listellement_t *list)
{
    map_t *tmp = list->map;
    perso_t *tmp2 = list->perso;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    while (tmp2 != NULL) {
        sfRenderWindow_drawSprite(window, tmp2->sprite, NULL);
        tmp2 = tmp2->next;
    }
}
