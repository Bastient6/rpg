/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** display_gestion
*/

#include "my.h"

void display_inventory(list_t *list, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, list->inventory, NULL);
    inventaire_t *tmp = list->first;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void display_option(game_t *game)
{
    if (game->state == PAUSE) {
        sfRenderWindow_drawSprite(game->window, game->pause->play, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->option, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->quit, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->setting, NULL);
    }
    if (game->state == OPTION) {
        sfRenderWindow_drawSprite(game->window, game->pause->play, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->option, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->quit, NULL);
        sfRenderWindow_drawSprite(game->window, game->pause->setting, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->pause->option_button->point, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->pause->option_button->volume_m, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->pause->option_button->volume_c, NULL);
        sfRenderWindow_drawSprite(game->window,
        game->pause->option_button->volume_p, NULL);
    }
}

void display_general(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->history->map, NULL);
    sfRenderWindow_drawText(game->window, game->text, NULL);
    display_element(game->window, game->history->list);
    sfRenderWindow_setView(game->window, game->view);
    prompt(game);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    star_level(game);
}

void display_gestion(game_t *game, list_t *list)
{
    sfRenderWindow_clear(game->window, sfTransparent);
    if (game->state == INVENTORY)
        display_inventory(list, game->window);
    else if (game->state == PAUSE || game->state == OPTION)
        display_option(game);
    else
        display_general(game);
    if (game->state == FULL)
        sfRenderWindow_drawSprite(game->window, game->help, NULL);
    if (game->state == SETTING)
        sfRenderWindow_drawSprite(game->window, game->setting, NULL);
    if (game->state == lopotitchaperon)
        game->player->pos = (sfVector2f){96,128};
    if ((game->state == lopoticochon || game->state == lopotipoucet
    || game->state == lopotitchaperon)) {
        if (game->loup == NULL)
            game->loup = create_loup();
        display_loup(game, list);
    }
    sfRenderWindow_display(game->window);
}

void actu_obj(game_t *game)
{
    sfVector2f view_position = sfView_getCenter(game->view);
    sfFloatRect rect = sfText_getGlobalBounds(game->text);
    sfText_setPosition(game->text, (sfVector2f){view_position.x -
    rect.width / 2, view_position.y + rect.height / 2 + 280});
}
