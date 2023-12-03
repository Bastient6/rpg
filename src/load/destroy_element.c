/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** destroy_element
*/

#include "load_file.h"

void free_last_element_map(map_t **map)
{
    map_t *tmp = *map;
    if (tmp->next == NULL) {
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        *map = NULL;
        return;
    }
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    sfSprite_destroy(tmp->next->sprite);
    sfTexture_destroy(tmp->next->texture);
    free(tmp->next);
    tmp->next = NULL;
}

void free_last_element_perso(perso_t **perso)
{
    perso_t *tmp = *perso;
    if (tmp->next == NULL) {
        sfSprite_destroy(tmp->sprite);
        sfTexture_destroy(tmp->texture);
        *perso = NULL;
        return;
    }
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    sfSprite_destroy(tmp->next->sprite);
    sfTexture_destroy(tmp->next->texture);
    free(tmp->next);
    tmp->next = NULL;
}

void remove_all_element(listellement_t *list)
{
    while (list->map != NULL) {
        free_last_element_map(&list->map);
    }
    while (list->perso != NULL) {
        free_last_element_perso(&list->perso);
    }
}
