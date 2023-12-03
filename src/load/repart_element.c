/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** repart_element
*/

#include "load_file.h"

listellement_t *create_inv_list(void)
{
    listellement_t *list = malloc(sizeof(listellement_t));
    list->map = NULL;
    list->perso = NULL;
    return list;
}

void repart_element(listellement_t *list, char **tab)
{
    list->map = malloc(sizeof(map_t *));
    list->perso = malloc(sizeof(perso_t *));
    for (int i = 0; tab[i] != NULL; i++) {
        if (str_compare("map", tab[i]) == 0) {
            create_sprite_map(tab[i], list->map);
            list->map = list->map->next;
        }
        if (str_compare("perso", tab[i]) == 0) {
            create_sprite_perso(tab[i], list->perso);
            list->perso = list->perso->next;
        }
        tab++;
    }
}
