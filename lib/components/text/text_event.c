/*
** EPITECH PROJECT, 2020
** text_event
** File description:
** text_event function
*/

#include "lib/components/text.h"

int is_text_clicked(text_t *text, sfEvent event)
{
    sfVector2f pos = {text->position.x, text->position.y};
    sfFloatRect rect = sfText_getLocalBounds(text->text);
    int mx = rect.width + pos.x;
    int my = rect.height + pos.y;

    if (event.type != sfEvtMouseButtonPressed)
        return (0);
    float x = event.mouseButton.x;
    float y = event.mouseButton.y;
    if (x <= mx && x >= pos.x && y <= my && y >= pos.y)
        return (1);
    else
        return (0);
}