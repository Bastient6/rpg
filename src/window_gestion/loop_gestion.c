/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** loop_gestion
*/

#include <my.h>

void player_gestion_bis(game_t *game)
{
    int pos_x = (int) game->player->pos.x / game->history->tils + 1;
    if ((sfKeyboard_isKeyPressed(sfKeyQ)
    || sfKeyboard_isKeyPressed(sfKeyLeft)) &&
    (int) game->player->pos.x - 2 >= 0 && (my_getnbr(my_str_to_word_array
    (game->map[(int)((game->player->pos.y) / game->history->tils) + 1], ',')
    [pos_x])) == game->col) {
        game->player->pos.x -= 2;
        game->player->rect = (sfIntRect){game->player->rect.left, 576, 64, 64};
        annimation(game);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyRight)) &&
    (int) game->player->pos.x / game->history->tils + 1
    < game->map_x && (my_getnbr(my_str_to_word_array
    (game->map[(int)((game->player->pos.y) / game->history->tils) + 1], ',')
    [pos_x + 1])) == game->col){
        game->player->pos.x += 2;
        game->player->rect = (sfIntRect){game->player->rect.left, 704, 64, 64};
        annimation(game);
    }
}

void player_gestion(game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyZ)
    || sfKeyboard_isKeyPressed(sfKeyUp)) &&
    (int) game->player->pos.y >= 0 && (my_getnbr(my_str_to_word_array
    (game->map[(int)((game->player->pos.y - 2) / game->history->tils) + 1], ',')
    [(int)(game->player->pos.x / game->history->tils) + 1])) == game->col) {
        game->player->pos.y -= 2;
        game->player->rect = (sfIntRect){game->player->rect.left, 512, 64, 64};
        annimation(game);
    }
    if ((sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyDown))
    && (int) game->player->pos.y / game->history->tils + 2 <
    game->map_y && (my_getnbr(my_str_to_word_array
    (game->map[(int)((game->player->pos.y + 2) / game->history->tils) + 1], ',')
    [(int)(game->player->pos.x / game->history->tils) + 1])) == game->col) {
        game->player->pos.y += 2;
        game->player->rect = (sfIntRect){game->player->rect.left, 640, 64, 64};
        annimation(game);
    } player_gestion_bis(game);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    actu_player(game);
}

void loop_event(game_t *game)
{
    if (game->state == lopotipoucet)
        poucet_forest(game);
    if (game->state == lopotitchaperon)
        chaperon_map(game);
    if (game->state == lopoticochon)
        petit_cochon_map(game);
    if (game->state != INVENTORY && game->state != PAUSE)
        player_gestion(game);
    if (game->state == PAUSE)
        pause_fonction(game);
    if (game->state == QUIT) {
        sfMusic_stop(game->music); sfMusic_destroy(game->music);
        sfRenderWindow_close(game->window);
    }
    if (game->state == OPTION) {
        pause_fonction(game); option_fonction(game);
    }
    if (game->state == FULL)
        full_fonction(game);
    player_gestion(game);
}

float set_time(game_t *game)
{
    game->seconds = 0;
    game->clock = sfClock_create ();
    game->time = sfClock_getElapsedTime( game->clock );
    game->seconds = game->time.microseconds / 10000.0;
    return game->seconds;
}

void loop_gestion(game_t *game)
{
    list_t *list = init_list(game);
    game->col = -1;
    game->state = START;
    start_menu(game);
    while (sfRenderWindow_isOpen(game->window)){
        draw_exp(game);
        game->seconds = set_time(game);
        event_gestion(game, list);
        if (game->state == INVENTORY)
            inventory(game, list);
        else
            loop_event(game);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && game->state == GAME)
            game->state = PAUSE;
        if (game->state == SETTING)
            setting_fonction(game);
        if (game->player->exp == 0)
            sfRenderWindow_close(game->window); return;
        display_gestion(game, list); actu_obj(game);
    }
}
