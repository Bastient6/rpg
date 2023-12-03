/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** load_file
*/

#ifndef LOAD_FILE_H_
    #define LOAD_FILE_H_
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <define.h>
    typedef struct inventaire_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        int box;
        struct inventaire_s *next;
    }inventaire_t;

    typedef struct list_s {
        sfVector2f *boxs;
        sfSprite *inventory;
        sfSprite *background;
        inventaire_t *first;
        inventaire_t *last;
    } list_t;

    typedef struct perso_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        char *name;
        char **dialogue;
        int state;
        struct perso_s *next;
    }perso_t;

    typedef struct map_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfVector2f pos;
        char *name;
        struct map_s *next;
    }map_t;

    typedef struct listellement_s {
        struct perso_s *perso;
        struct map_s *map;
    }listellement_t;

    int str_compare(char *str1, char *str2);
    char **open_file(char *filepath);
    char **my_str_to_word_array(char *str, char separator);
    void create_sprite_inventaire(char *file, inventaire_t *element);
    void create_sprite_map(char *file, map_t *element);
    void create_sprite_perso(char *file, perso_t *element);
    void repart_element(listellement_t *list, char **tab);
    int my_getnbr(char const *str);
    void display_sprite(sfRenderWindow *window, listellement_t *list);
    void destroy_list(listellement_t *list);
    int my_strlen(char const *str);
#endif /* !LOAD_FILE_H_ */
