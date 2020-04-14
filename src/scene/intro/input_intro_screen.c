/*
** EPITECH PROJECT, 2020
** intro_screen_input
** File description:
** intro_screen_input function
*/

#include "game.h"
#include "scene/intro_screen.h"

int input_intro_screen(game_t *game, intro_screen_t *screen)
{
    if (game->event.type != sfEvtKeyPressed)
        return (0);
    if (game->event.key.code == sfKeyD)
        for (int i = 0; screen->npc[i] != 0; i++)
            screen->npc[i]->current_animations = 1;
    if (game->event.key.code == sfKeyS)
        for (int i = 0; screen->npc[i] != 0; i++)
            screen->npc[i]->current_animations = 0;
    if (game->event.key.code == sfKeyZ)
        for (int i = 0; screen->npc[i] != 0; i++)
            screen->npc[i]->current_animations = 3;
    if (game->event.key.code == sfKeyQ)
        for (int i = 0; screen->npc[i] != 0; i++)
            screen->npc[i]->current_animations = 2;
    /*if (!screen->dialog->is_active && !screen->dialog->is_finished)
        screen->dialog->is_active = 1;
    else
        update_dialog_line(screen->dialog);
    */
}