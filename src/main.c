/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** main
*/

#include <my.h>

int main(void)
{
    game_t *game = init_game();
    load_file(game, "assets/fichier_sys/hub.txt");
    sfText_setString(game->text, "Hub");
    game->sate_chap = 0;
    init_star(game);
    init_start(game);
    loop_gestion(game);
    return 0;
}
