/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** open_file
*/

#include "load_file.h"

int fs_open_file ( char const * filepath )
{
    int i = open (filepath, O_RDONLY);
    if (i >= 0)
        return 0;
    return 84;
}

char **open_file(char *filepath)
{
    if (fs_open_file(filepath) == 84)
        return (NULL);
    int fd = open(filepath, O_RDONLY);
    struct stat a;
    stat(filepath, &a);
    int size = a.st_size;
    char *buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, size);
    buffer[size] = '\0';
    char **tab = my_str_to_word_array(buffer, '\n');
    close(fd);
    return tab;
}
