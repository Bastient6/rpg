/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** exp
*/

#include "my.h"

void draw_exp(game_t *game)
{
    char texte[10];
    sprintf(texte, "%d", game->player->exp);
    sfFont* police = sfFont_createFromFile("assets/font/rpg_font.ttf");
    game->text = sfText_create();
    sfText_setString(game->text, texte);
    sfText_setFont(game->text, police);
    sfText_setCharacterSize(game->text, 20);
    sfVector2f position = {game->player->pos.x + 50, game->player->pos.y - 50};
    sfText_setPosition(game->text, position);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}

void draw_exp_loup(game_t *game)
{
    char texte[10];
    sprintf(texte, "%d", game->loup->exp);
    sfFont* police = sfFont_createFromFile("assets/font/rpg_font.ttf");
    game->text = sfText_create();
    sfText_setString(game->text, texte);
    sfText_setFont(game->text, police);
    sfText_setCharacterSize(game->text, 20);
    sfVector2f position = {game->loup->pos.x + 50, game->loup->pos.y - 50};
    sfText_setPosition(game->text, position);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}
