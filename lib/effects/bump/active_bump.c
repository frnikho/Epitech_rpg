/*
** EPITECH PROJECT, 2020
** active_bump.c
** File description:
**  function
*/

#include "lib/effects/bump.h"

void set_bump_active(bump_t *bump, int is_active)
{
    bump->is_active = is_active;
}

void toggle_bump_active(bump_t *bump)
{
    bump->is_active = !bump->is_active;
}

int is_bump_active(bump_t *bump)
{
    return (bump->is_active);
}