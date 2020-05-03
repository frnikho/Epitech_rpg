/*
** EPITECH PROJECT, 2020
** draw_state.c
** File description:
** draw state function
*/

#include <SFML/Graphics/Types.h>
#include <state.h>

void draw_state(sfView *camera, sfRenderWindow *window, state_t *state)
{
    if (!state)
        return;
    if (state->fade_in)
        draw_fade(window, state->fade_in);

    if (state->dialog) {
        draw_dialog(window, state->dialog);
        set_dialog_relative(state->dialog, camera);
    }
}