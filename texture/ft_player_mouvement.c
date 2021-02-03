#include "cub3d.h"

void ft_mouvement_up()
{
    int p;

     g_X_remainder = g_X_player;
            g_Y_remainder = g_Y_player;
            g_X_remainder += cos(g_rotationAngle) * 10;
            g_Y_remainder += sin(g_rotationAngle) * 10;
            p = wall_collision();
            if (p != 1)
            {
                g_X_player += cos(g_rotationAngle) * 10;
                g_Y_player += sin(g_rotationAngle) * 10;
            } 
}
void ft_mouvement_down()
{
    int p;

     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle) * 10;
        g_Y_remainder -= sin(g_rotationAngle) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle) * 10;
            g_Y_player -= sin(g_rotationAngle) * 10;
        } 
}
void ft_mouvement_left()
{
    int p;
     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle + M_PI / 2) * 10;
        g_Y_remainder -= sin(g_rotationAngle + M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle + M_PI / 2) * 10;
            g_Y_player -= sin(g_rotationAngle + M_PI / 2) * 10;
        }
}
void ft_mouvement_right()
{
    int p;
     g_X_remainder = g_X_player;
        g_Y_remainder = g_Y_player;
        g_X_remainder -= cos(g_rotationAngle - M_PI / 2) * 10;
        g_Y_remainder -= sin(g_rotationAngle - M_PI / 2) * 10;
        p = wall_collision();
        if (p != 1)
        {
            g_X_player -= cos(g_rotationAngle - M_PI / 2) * 10;
            g_Y_player -= sin(g_rotationAngle - M_PI / 2) * 10;
        }
}
void ft_all_mouvement()
{
    if (strcmp(g_chorfi,"--save") == 0)
        screenshot();
    if(g_down == 1)
        ft_mouvement_down();
    else if (g_up == 1)
        ft_mouvement_up();
    if(g_d == 1)
        ft_mouvement_right();
    if(g_a == 1)
        ft_mouvement_left();
    if (g_left == 1)
         g_rotationAngle -= rad(3);
    if (g_right == 1)
         g_rotationAngle += rad(3);
}