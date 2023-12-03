/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** create_sprite
*/

#include "load_file.h"

void create_sprite_inventaire(char *file, inventaire_t *element)
{
    char **tab = my_str_to_word_array(file, ':');
    element->pos.x = my_getnbr(tab[2]);
    element->pos.y = my_getnbr(tab[3]);
    element->texture = sfTexture_createFromFile(tab[1], NULL);
    element->sprite = sfSprite_create();
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
}

void create_sprite_map(char *file, map_t *element)
{
    char **tab = my_str_to_word_array(file, ':');
    element->pos.x = my_getnbr(tab[2]);
    element->pos.y = my_getnbr(tab[3]);
    element->texture = sfTexture_createFromFile(tab[1], NULL);
    element->sprite = sfSprite_create();
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
}

void create_sprite_perso(char *file, perso_t *element)
{
    char **tab = my_str_to_word_array(file, ':');
    element->pos.x = my_getnbr(tab[2]);
    element->pos.y = my_getnbr(tab[3]);
    element->texture = sfTexture_createFromFile(tab[1], NULL);
    element->sprite = sfSprite_create();
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setTexture(element->sprite, element->texture, sfTrue);
}
