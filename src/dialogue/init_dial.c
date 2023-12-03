/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** init_dial
*/

#include <my.h>

sfText *create_text(game_t *game)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/rpg_font.ttf");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setColor(text, sfWhite);
    sfVector2f view_position = sfView_getCenter(game->view);
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfText_setPosition(text, (sfVector2f){view_position.x -
    rect.width / 2, view_position.y + rect.height / 2 + 280});
    return text;
}
