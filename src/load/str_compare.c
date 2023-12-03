/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** str_compare
*/

#include "load_file.h"

int str_compare(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 1;
    for (int i = 0; str2[i] != 0; i++)
        if (str1[i] != str2[i])
            return 84;
    return 0;
}
