/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** init_game
*/

#include "my.h"

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    player->pos = (sfVector2f){150, 0};
    player->sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/sprites/player.png", NULL);
    sfSprite_setTexture(player->sprite, texture, sfTrue);
    player->rect = (sfIntRect){0, 0, 64, 64};
    sfSprite_setTextureRect(player->sprite, player->rect);
    player->life = 100;
    player->attack = 10;
    player->defense = 10;
    player->speed = 10;
    player->level = 0;
    player->exp = 100;
    return player;
}

void load_map(game_t *game)
{
    game->history->map = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/maps/hub.png", NULL);
    sfSprite_setTexture(game->history->map, texture, sfTrue);
    game->text = create_text(game);
    sfText_setString(game->text, "Bonjoire");
    sfText_setString(game->text, NULL);
}

void init_sound(game_t *game)
{
    game->music = sfMusic_createFromFile("assets/music/sound.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 50);
    sfMusic_play(game->music);
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->pause = malloc(sizeof(pause_t));
    game->pause->option_button = malloc(sizeof(option_t));
    init_pause(game); init_option(game);
    init_sound(game); init_setting(game);
    game->map = read_file("assets/maps/hub.csv", game);
    game->window = create_window();
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f){1280, 720});
    game->clock = sfClock_create();
    game->history = create_history();
    game->player = create_player();
    game->text_hint = sfText_create();
    game->state = GAME;
    game->hint = NULL;
    game->old_state = GAME;
    game->poucet = 0;
    game->box = 0; game->full = 0;
    load_map(game);
    return game;
}
