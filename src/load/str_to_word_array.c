/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** str_to_word_array
*/

#include "load_file.h"

char *my_strdup(char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *end_string(char *buffer)
{
    for (int i = 0; buffer[i] != 0; i++){
        if (buffer[i] == '\n' && buffer[i - 1] == ' ')
            buffer[i - 1] = 0;
        if (buffer[i] == '\n')
            buffer[i] = 0;
    }
    return buffer;
}

char *clean_str(char *str)
{
    int x = 0;
    int y = 0;
    char *clean = malloc(sizeof(char) * my_strlen(str) + 1);
    while (str[x] == ' ' || str[x] == '\t')
        x++;
    for (; str[x] != 0; x++, y++) {
        if (str[x] == '\t')
            str[x] = ' ';
        if (str[x] == ' ' && str[x + 1] == ' ')
            x++;
        clean[y] = str[x];
    }
    if (str[x - 1] == ' ')
        clean[y - 1] = 0;
    else
        clean[y] = 0;
    clean = end_string(clean);
    return clean;
}
