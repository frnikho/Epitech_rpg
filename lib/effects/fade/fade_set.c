/*
** EPITECH PROJECT, 2020
** fade_set.c
** File description:
** fade set function
*/

#include "lib/effects/fade.h"

void set_fade_callback(fade_t *call)
{

}

void set_fade_active(fade_t *fade)
{
    fade->is_active = 1;
}

int fade_is_active(fade_t *fade)
{
    return fade->is_active;
}

int fade_is_finish(fade_t *fade)
{
    return fade->is_finish;
}