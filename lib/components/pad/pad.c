/*
** EPITECH PROJECT, 2020
** pad.c
** File description:
** pad function
*/

#include "lib/components/pad.h"
#include "SFML/Window.h"

int pad_pressed(int PAD_KEY)
{
    return sfJoystick_isButtonPressed(0, PAD_KEY);
}

enum pad pad_arrow(void)
{
    float x = sfJoystick_getAxisPosition(0, sfJoystickPovX);
    float y = sfJoystick_getAxisPosition(0, sfJoystickPovY);

    if (x <= -100)
        return (PAD_LEFT);
    if (x >= 100)
        return (PAD_RIGHT);
    if (y <= -100)
        return (PAD_UP);
    if (y >= 100)
        return (PAD_DOWN);
    return (0);
}