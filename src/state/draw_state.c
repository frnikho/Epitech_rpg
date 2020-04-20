/*
** EPITECH PROJECT, 2020
** draw_state.c
** File description:
** draw state function
*/

#include <SFML/Graphics/Types.h>
#include <state.h>

void draw_state(sfRenderWindow *window, state_t *state)
{
    if (!state)
        return;
    if (state->npcs) {
        for (int i = 0; state->npcs[i] != 0; i++)
            draw_npc(window, state->npcs[i]);
    }
}