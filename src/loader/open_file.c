/*
** EPITECH PROJECT, 2023
** My_RPG
** File description:
** open_file
*/

#include <my.h>

char **my_str_to_word_array(char *str, char separator)
{
    int i = 0, j = 0, k = 0;
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));

    if (array == NULL)
        return NULL;
    while (str[i] != '\0') {
        array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        if (array[j] == NULL)
            return NULL;
        while (str[i] != separator && str[i] != '\0') {
            array[j][k] = str[i];
            i++; k++;
        }
        array[j][k] = '\0';
        j++; k = 0;
        if (str[i] != '\0')
            i++;
    }
    array[j] = NULL;
    return array;
}

char *open_file_loader(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat sb;
    char *buffer;

    if (fd == -1)
        return NULL;
    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (buffer == NULL)
        return NULL;
    read(fd, buffer, sb.st_size);
    buffer[sb.st_size] = '\0';
    close(fd);
    return buffer;
}
