/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** stars_level
*/

#include "my.h"

void init_star(game_t *game)
{
    game->star = sfSprite_create();
    game->texture_star = sfTexture_createFromFile(
        "assets/sprites/etoile.png", NULL);
    game->rect_star = (sfIntRect){0, 0, 180, 180};
    sfSprite_setScale(game->star, (sfVector2f){0.1, 0.1});
    sfSprite_setTextureRect(game->star, game->rect_star);
    sfSprite_setTexture(game->star, game->texture_star, sfTrue);
}

void star_level(game_t *game)
{
    sfSprite_setPosition(game->star,
    (sfVector2f){game->player->pos.x - 50, game->player->pos.y - 50});
    if (game->player->level == 1) {
        game->rect_star.left = 180;
        sfSprite_setTextureRect(game->star, game->rect_star);
        sfRenderWindow_drawSprite(game->window, game->star, NULL);
    }
    if (game->player->level == 2) {
        game->rect_star.left = 0;
        game->rect_star.width = 360;
        sfSprite_setTextureRect(game->star, game->rect_star);
        sfRenderWindow_drawSprite(game->window, game->star, NULL);
    }
    if (game->player->level == 3) {
        game->rect_star.left = 0;
        game->rect_star.width = 540;
        sfSprite_setTextureRect(game->star, game->rect_star);
        sfRenderWindow_drawSprite(game->window, game->star, NULL);
    }
}
