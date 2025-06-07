/*
** EPITECH PROJECT, 2025
** window.c
** File description:
** just a file
*/

#include "../include/my_rpg.h"

void manage_event(param_t *param)
{
    while (sfRenderWindow_pollEvent(param->window, &param->event)) {
        if (param->event.type == sfEvtClosed) {
            sfRenderWindow_close(param->window);
            return;
        }
    }
}

void window_loop(param_t *param)
{
    while (sfRenderWindow_isOpen(param->window)) {
        manage_event(param);
        sfRenderWindow_clear(param->window, sfBlack);
        sfRenderWindow_display(param->window);
    }
    sfRenderWindow_destroy(param->window);
    return;
}

void init_param(param_t *param)
{
    param->mode = (sfVideoMode){1920, 1080, 64};
    param->sf = (sfUint32){sfClose};
    param->event = (sfEvent){0};
    param->window = sfRenderWindow_create(param->mode, "My_rpg", param->sf, 0);
}

int main(int ac, char **av)
{
    param_t param;

    init_param(&param);
    window_loop(&param);
}
