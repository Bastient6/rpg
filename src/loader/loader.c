/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** loader
*/

#include <my.h>

int verif_command(game_t *game, char *str)
{
    char **array = my_str_to_word_array(str, ':');
    char **data;
    char **dialogue;
    if (my_strcmp(array[0], "map") == 0) {
        data = my_str_to_word_array(array[1], ' ');
        set_map(game, data[0]);
        game->map = read_file(data[1], game);
        game->history->tils = my_getnbr(data[2]);
        return 0;
    }
    if (my_strcmp(array[0], "pnj") == 0) {
        data = my_str_to_word_array(array[1], ' ');
        add_pnj_on_map(game->history->list, data);
        return 0;
    }
    if (my_strcmp(array[0], "item") == 0) {
        data = my_str_to_word_array(array[1], ' ');
        add_item_on_map(game->history->list, data);
        return 0;
    } return 1;
}

void load_file(game_t *game, char *filepath)
{
    char *buffer = open_file_loader(filepath);
    if (buffer == NULL) {
        my_putstr("Error: File not found\n");
        return;
    }
    char **array = my_str_to_word_array(buffer, '\n');
    for (int i = 0; array[i] != NULL; i++) {
        if (verif_command(game, array[i]) == 1) {
            add_dial_on_last_pnj
            (game->history->list, my_str_to_word_array(array[i], '|'));
        }
    }
}
