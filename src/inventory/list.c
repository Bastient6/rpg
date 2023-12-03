/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** list
*/

#include <my.h>
#include <load_file.h>

sfVector2f *boxes(int b, int z)
{
    sfVector2f *boxes = malloc(sizeof(sfVector2f) * 30);
    int x = C1.x + b;
    int y = L1.x + z;
    for (int i = 0; i < 30; i++, x += 60) {
        if (x >= C6.x + b) {
            x = C1.x + b;
            y += 60;
        }
        boxes[i] = (sfVector2f){x, y};
    }
    return boxes;
}

list_t *init_list(game_t *game)
{
    list_t *list = malloc(sizeof(list_t));
    list->first = NULL;
    list->last = NULL;
    list->inventory = sfSprite_create();
    list->background = sfSprite_create();
    sfTexture *background = sfTexture_createFromFile
    ("assets/inventory/background.jpg", NULL);
    sfSprite_setTexture(list->background, background, sfTrue);
    sfTexture *texture = sfTexture_createFromFile
    ("assets/inventory/inventory.png", NULL);
    sfSprite_setTexture(list->inventory, texture, sfTrue);
    sfVector2f vec = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    sfSprite_setPosition(list->inventory, (sfVector2f){vec.x - size.x / 2,
    vec.y - size.y / 2});
    sfSprite_setPosition(list->background, (sfVector2f){vec.x - size.x / 2,
    vec.y - size.y / 2});
    list->boxs = boxes(0, 0);
    return list;
}
