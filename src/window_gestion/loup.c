/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** create_loup
*/

#include "my.h"

void loup_combat(game_t *game, sfFloatRect rect, sfFloatRect rect2)
{
    if (game->player->exp < 100 &&
        !sfFloatRect_intersects(&rect2, &rect, NULL))
            game->player->exp += 1;
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
    sfFloatRect_intersects(&rect2, &rect, NULL)){
            game->loup->exp -= 3;
            game->player->rect2 = (sfIntRect){320, 960, 64, 64};
            sfSprite_setTextureRect(game->player->sprite, game->player->rect2);
            sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
            sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void loup_dead(game_t *game, list_t *list)
{
    if (game->loup->exp > 0)
        sfRenderWindow_drawSprite(game->window, game->loup->sprite, NULL);
    if (game->loup->exp <= 0) {
        sfSprite_destroy(game->loup->sprite);
        free(game->loup);
        game->loup = NULL;
        load_file(game, "assets/fichier_sys/hub.txt");
        if (game->state == lopoticochon)
            game->player->pos = (sfVector2f){250, 1985};
        if (game->state == lopotipoucet)
            game->player->pos = (sfVector2f){400, 150};
        if (game->state == lopotitchaperon)
            game->player->pos = (sfVector2f){800, 250};
        game->player->level += 1;
        game->sate_chap = 0;
        game->state = GAME;
        display_gestion(game, list);
    }
}

void display_of_time(game_t *game, sfFloatRect rect, sfFloatRect rect2)
{
    if (game->seconds > 0.0001) {
        game->time = sfClock_getElapsedTime(game->clock);
        sfClock_restart(game->clock);
        game->loup->rect.left += 200;
        if (game->loup->rect.left >= 996)
            game->loup->rect.left = 0;
        if (sfFloatRect_intersects(&rect2, &rect, NULL))
            game->player->exp -= 1;
        loup_combat(game, rect, rect2);
        sfSprite_setTextureRect(game->loup->sprite, game->loup->rect);
    }
}

void display_loup(game_t *game, list_t *list)
{
    draw_exp_loup(game);
    event_gestion(game, list);
    if (game->state == lopoticochon)
        game->loup->pos = (sfVector2f){1000, 20};
    if (game->state == lopotipoucet)
        game->loup->pos = (sfVector2f){800, 20};
    if (game->state == lopotitchaperon)
        game->loup->pos = (sfVector2f){300,128};
    sfSprite_setPosition(game->loup->sprite, game->loup->pos);
    sfFloatRect rect = sfSprite_getGlobalBounds(game->loup->sprite);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(game->player->sprite);
    display_of_time(game, rect, rect2);
    loup_dead(game, list);
}

loup_t *create_loup(void)
{
    loup_t *loup = malloc(sizeof(loup_t));
    loup->pos = (sfVector2f){150, 150};
    loup->sprite = sfSprite_create();
    sfTexture *texture =
    sfTexture_createFromFile("assets/sprites/loup.png", NULL);
    sfSprite_setPosition(loup->sprite, loup->pos);
    sfSprite_setTexture(loup->sprite, texture, sfTrue);
    loup->rect = (sfIntRect){0, 0, 200, 200};
    sfSprite_setTextureRect(loup->sprite, loup->rect);
    loup->life = 100;
    loup->attack = 10;
    loup->defense = 10;
    loup->speed = 10;
    loup->level = 1;
    loup->exp = 100;
    return loup;
}
