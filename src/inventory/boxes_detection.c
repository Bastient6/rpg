/*
** EPITECH PROJECT, 2023
** lopotipoucet
** File description:
** boxes_detection
*/

#include "my.h"

int fifth_line(int x, int y)
{
    if (x >= C1.x && x <= C1.y && y <= L5.y && y >= L5.x)
        return 25;
    if (x >= C2.x && x <= C2.y && y <= L5.y && y >= L5.x)
        return 26;
    if (x >= C3.x && x <= C3.y && y <= L5.y && y >= L5.x)
        return 27;
    if (x >= C4.x && x <= C4.y && y <= L5.y && y >= L5.x)
        return 28;
    if (x >= C5.x && x <= C5.y && y <= L5.y && y >= L5.x)
        return 29;
    if (x >= C6.x && x <= C6.y && y <= L5.y && y >= L5.x)
        return 30;
    return 0;
}

int fourth_line(int x, int y)
{
    if (x >= C1.x && x <= C1.y && y <= L4.y && y >= L4.x)
        return 19;
    if (x >= C2.x && x <= C2.y && y <= L4.y && y >= L4.x)
        return 20;
    if (x >= C3.x && x <= C3.y && y <= L4.y && y >= L4.x)
        return 21;
    if (x >= C4.x && x <= C4.y && y <= L4.y && y >= L4.x)
        return 22;
    if (x >= C5.x && x <= C5.y && y <= L4.y && y >= L4.x)
        return 23;
    if (x >= C6.x && x <= C6.y && y <= L4.y && y >= L4.x)
        return 24;
    return fifth_line(x, y);
}

int third_line(int x, int y)
{
    if (x >= C1.x && x <= C1.y && y <= L3.y && y >= L3.x)
        return 13;
    if (x >= C2.x && x <= C2.y && y <= L3.y && y >= L3.x)
        return 14;
    if (x >= C3.x && x <= C3.y && y <= L3.y && y >= L3.x)
        return 15;
    if (x >= C4.x && x <= C4.y && y <= L3.y && y >= L3.x)
        return 16;
    if (x >= C5.x && x <= C5.y && y <= L3.y && y >= L3.x)
        return 17;
    if (x >= C6.x && x <= C6.y && y <= L3.y && y >= L3.x)
        return 18;
    return fourth_line(x, y);
}

int second_line(int x, int y)
{
    if (x >= C1.x && x <= C1.y && y <= L2.y && y >= L2.x)
        return 7;
    if (x >= C2.x && x <= C2.y && y <= L2.y && y >= L2.x)
        return 8;
    if (x >= C3.x && x <= C3.y && y <= L2.y && y >= L2.x)
        return 9;
    if (x >= C4.x && x <= C4.y && y <= L2.y && y >= L2.x)
        return 10;
    if (x >= C5.x && x <= C5.y && y <= L2.y && y >= L2.x)
        return 11;
    if (x >= C6.x && x <= C6.y && y <= L2.y && y >= L2.x)
        return 12;
    return third_line(x, y);
}

int is_a_box(int x, int y)
{
    if (x >= C1.x && x <= C1.y && y >= L1.x && y <= L1.y)
        return 1;
    if (x >= C2.x && x <= C2.y && y >= L1.x && y <= L1.y)
        return 2;
    if (x >= C3.x && x <= C3.y && y >= L1.x && y <= L1.y)
        return 3;
    if (x >= C4.x && x <= C4.y && y >= L1.x && y <= L1.y)
        return 4;
    if (x >= C5.x && x <= C5.y && y >= L1.x && y <= L1.y)
        return 5;
    if (x >= C6.x && x <= C6.y && y >= L1.x && y <= L1.y)
        return 6;
    return second_line(x, y);
}
