/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** pop_up
*/

#include <my.h>
#include <define.h>
#include <load_file.h>

void add_description(char *str, game_t *game)
{
    game->text_hint = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/rpg_font.ttf");
    sfText_setFont(game->text_hint, font);
    sfText_setString(game->text_hint, str);
    sfText_setCharacterSize(game->text_hint, 20);
    sfText_setColor(game->text_hint, sfBlack);
    sfText_setPosition(game->text_hint, (sfVector2f) {0, 0});
    sfText_setFillColor(game->text_hint, sfBlack);

    game->hint = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile
    ("assets/inventory/background.jpg", NULL);
    sfSprite_setTexture(game->hint, texture, sfTrue);
    sfSprite_setPosition(game->hint, (sfVector2f){0, 0});
}
