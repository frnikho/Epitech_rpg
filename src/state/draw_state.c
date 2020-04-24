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
    if (state->npcs) {
        for (int i = 0; state->npcs[i] != 0; i++)
            draw_npc(window, state->npcs[i]);
    }
    if (state->fade_in)
        draw_fade(window, state->fade_in);

    if (state->dialog) {
        draw_dialog(window, state->dialog);
        set_dialog_relative(state->dialog, camera);
    }
    for (int i = 0; state->npcs[i]; i++) {
        draw_dialog(window, state->npcs[i]->dialog);
        set_dialog_relative(state->npcs[i]->dialog, camera);
    }
}