/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** my
*/

#pragma once

#include "load_file.h"

typedef struct player_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfIntRect rect2;
    inventaire_t *inventaire;
    int life;
    int attack;
    int defense;
    int speed;
    int level;
    int exp;
} player_t;

typedef struct loup_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    inventaire_t *inventaire;
    int life;
    int attack;
    int defense;
    int speed;
    int level;
    int exp;
} loup_t;

typedef struct list_sprite_s {
    sfSprite *sprite;
    struct list_sprite_s *next;
} list_sprite;

typedef struct history_s {
    sfSprite *map;
    int scene;
    int tils;
    listellement_t *list;
} history_t;

typedef struct option_s {
    sfSprite *volume_m;
    sfSprite *volume_c;
    sfSprite *volume_p;
    sfSprite *point;
} option_t;

typedef struct pause_s {
    sfSprite *play;
    sfSprite *option;
    sfSprite *quit;
    sfSprite *setting;
    option_t *option_button;
} pause_t;

typedef struct start_s {
    sfSprite *new_game;
    sfSprite *quit;
    sfSprite *setting;
} start_t;

typedef struct game_s {
    sfRenderWindow *window;
    sfEvent event;
    sfView *view;
    player_t *player;
    loup_t *loup;
    sfClock *clock;
    sfText *text;
    history_t *history;
    sfMusic *music;
    sfTime time;
    sfSprite *hint;
    sfText *text_hint;
    int map_y;
    int map_x;
    int poucet;
    int box;
    int state;
    int old_state;
    float seconds;
    char **map;
    pause_t *pause;
    int full;
    int col;
    int sate_chap;
    sfSprite *help;
    sfSprite *setting;
    sfTexture *texture_star;
    sfSprite *star;
    sfIntRect rect_star;
    sfVector2f posloup;
    start_t *start;
} game_t;

sfRenderWindow *create_window(void);

sfRenderWindow *create_window_full(void);

void modify_window(sfRenderWindow *window, int width, int height, int fps);

listellement_t *create_inv_list(void);

void event_gestion(game_t *game, list_t *list);

void init_start(game_t *game);

void init_star(game_t *game);

void start_menu(game_t *game);

void loop_gestion(game_t *game);

void draw_cochon(game_t *game);

void init_setting(game_t *game);

void setting_fonction(game_t *game);

loup_t *create_loup(void);

void petit_cochon_event(game_t *game);

game_t *init_game(void);

void event_map(game_t *game, list_t *list);

void petit_cochon_map(game_t *game);

int my_strlen(char const *str);

void display_gestion(game_t *game, list_t *list);

char *open_file_loader(char *filepath);

char **my_str_to_word_array(char *str, char separator);

history_t *create_history(void);

void load_file(game_t *game, char *filepath);

void annimation(game_t *game);

char *my_strdup(char *str);

void display_loup(game_t *game, list_t *list);

void add_item_on_map(listellement_t *list, char **data);

void draw_exp(game_t *game);

void draw_exp_loup(game_t *game);

void star_level(game_t *game);

void add_pnj_on_map(listellement_t *list, char **data);

void add_dial_on_last_pnj(listellement_t *list, char **data);

void set_map(game_t *game, char *filepath);

void display_element(sfRenderWindow *window, listellement_t *list);

char ** read_file(char const * filepath, game_t *game);

void actu_player(game_t *game);

void remove_all_element(listellement_t *list);

int my_strcmp(char const *s1, char const *s2);

list_t *init_list(game_t *game);

int is_a_box(int x, int y);

void inventory(game_t *game, list_t *list);

sfVector2f *boxes(int b, int z);

void poucet_forest(game_t *game);

void pause_fonction(game_t *game);

void init_pause(game_t *game);

void init_option(game_t *game);

void option(game_t *game);

void option_fonction(game_t *game);

void prompt(game_t *game);

void set_music(game_t *game, int volume);

void lopotipoucet_event(game_t *game);

void items(game_t *game, list_t *list);

void jsp(game_t *game, list_t *list, map_t *item);

sfText *create_text(game_t *game);

void actu_obj(game_t *game);

void inventory_event(game_t *game, list_t *list);

void perso_is_map(game_t *game);

void full_fonction(game_t *game);

void chaperon_event(game_t *game);

void chaperon_map(game_t *game);

void my_putstr(char const *str);

void add_description(char *str, game_t *game);

void add_object_inventory(list_t *list, sfSprite *sprite,
sfTexture *texture, int box);
