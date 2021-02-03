#include "cub3d.h"

void ft_find_intersec()
{
    int g_check;

    while(g_nextHoriX >= 0 && g_nextHoriX < g_mapcount[0].lenghtx * 50 && g_nextHoriY >= 0 && g_nextHoriY < inde * 50)
    {
        g_sprite = 0;
        g_check = wall_checker();
        if(g_sprite == 1)
        {
            g_sprites[g_sprite_count].xcentre = ((int)g_nextHoriX / 50 * 50) + 25;
            g_sprites[g_sprite_count].ycentre = ((int)g_nextHoriY / 50 * 50) + 25;
            g_sprites[g_sprite_count].g_x = g_nextHoriX;
            g_sprites[g_sprite_count].g_y = g_nextHoriY;
            g_sprites[g_sprite_count].g_distance =  sqrtf(powf(g_Y_player - g_sprites[g_sprite_count].g_y,2) + powf(g_X_player - g_sprites[g_sprite_count].g_x,2));
            g_sprites[g_sprite_count].g_rotation = atan2(g_Y_player - g_nextHoriY,  g_X_player - g_nextHoriX);
            g_sprite_count++;

        }
        if (g_check == 1)
        {
            g_wallHoriHit = 1;
            g_HorizwallHitX = g_nextHoriX;
            g_HorizwallHitY = g_nextHoriY;
            break;
        }
        else
        {
            g_nextHoriX += g_xstep;
            g_nextHoriY += g_ystep; 
        }
    }
}
void ft_yx_intercept()
{
    ft_intial_variable();
    g_yintercept = (int)(g_Y_player / g_wall) * g_wall;
    g_yintercept += g_rayFacingDown ? g_wall : 0;
    g_xintercept = g_X_player + (g_yintercept - g_Y_player) / tan(g_rotation);

    g_ystep = g_wall;
    g_ystep *= g_rayFacingUp ? -1 : 1;

    g_xstep = g_ystep / tan(g_rotation);

    g_nextHoriX = g_xintercept;
    g_nextHoriY = g_yintercept;

    if(g_rayFacingUp)
        g_nextHoriY--;
}
void ft_find_intercept1()
{
    int g_check;

    while(g_nextHoriX >= 0 && g_nextHoriX < g_mapcount[0].lenghtx * 50 && g_nextHoriY >= 0 && g_nextHoriY < inde * 50)
    {
        g_sprite = 0;
        g_check = wall_checker();
        if(g_sprite == 1)
        {
            g_sprites[g_sprite_count].xcentre = ((int)g_nextHoriX / 50 * 50) + 25;
            g_sprites[g_sprite_count].ycentre = ((int)g_nextHoriY / 50 * 50) + 25;
            g_sprites[g_sprite_count].g_rotation = atan2(g_Y_player - g_nextHoriY,  g_X_player - g_nextHoriX);
            g_sprites[g_sprite_count].g_x = g_nextHoriX;
            g_sprites[g_sprite_count].g_y = g_nextHoriY;
            g_sprites[g_sprite_count].g_distance =  sqrtf(powf(g_Y_player - g_sprites[g_sprite_count].g_y,2) + powf(g_X_player - g_sprites[g_sprite_count].g_x,2));
            g_sprite_count++;
        }
        if (g_check == 1)
        {
            g_wallVertHit = 1;
            g_VertwallHitX = g_nextHoriX;
            g_VertwallHitY = g_nextHoriY;
            break;
        }
        else
        {
            g_nextHoriX += g_xstep;
            g_nextHoriY += g_ystep; 
        }

    }
}
void ft_yx_intercept1()
{
     g_wallVertHit = 0;
    ray_direction();
    g_xintercept = (int)(g_X_player / g_wall) * g_wall;
    g_xintercept += g_rayFacingRight ? g_wall : 0;
    g_yintercept = g_Y_player - (g_X_player - g_xintercept) * tan(g_rotation);

    g_xstep = g_wall;
    g_xstep *= g_rayFacingLeft ? -1 : 1;
    g_ystep = g_xstep * tan(g_rotation);
   

    g_nextHoriX = g_xintercept;
    g_nextHoriY = g_yintercept;

    if(g_rayFacingLeft)
        g_nextHoriX--;
}
int ft_cast_ray()
{
    int g_check;

    ft_yx_intercept();
    ft_find_intersec();
    ft_yx_intercept1();
    ft_find_intercept1();
    g_HorzHitDistance = (g_wallHoriHit) ? distance_between_horver(g_X_player , g_Y_player, g_HorizwallHitX,g_HorizwallHitY) : MAX_INT;
    g_VertHitDistance = (g_wallVertHit) ? distance_between_horver(g_X_player , g_Y_player, g_VertwallHitX,g_VertwallHitY) : MAX_INT;
    g_WallHitX = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorizwallHitX : g_VertwallHitX;
    g_WallHitY = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorizwallHitY : g_VertwallHitY;
    g_distance = (g_HorzHitDistance) < (g_VertHitDistance) ? g_HorzHitDistance : g_VertHitDistance;
    g_mhah = g_distance == g_HorzHitDistance ? 1 : 0;
    g_wasHitVertical = (g_VertHitDistance) < (g_HorzHitDistance);
    g_DarkColor = 0x006400;
    g_DarkColor = check_opacity(g_DarkColor);
   return 0;
}