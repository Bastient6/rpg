/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** init_loader
*/

#include <my.h>

history_t *create_history(void)
{
    history_t *history = malloc(sizeof(history_t));
    history->map = NULL;
    history->tils = 0;
    history->list = malloc(sizeof(listellement_t));
    history->list->map = NULL;
    history->list->perso = NULL;
    return history;
}
