#include "cub3d.h"

int wall_checker()
{
    int X_pos;
    int Y_pos;

    X_pos = g_nextHoriX / g_wall;
    Y_pos = g_nextHoriY / g_wall;
    if ((X_pos >= 0 &&  X_pos <= g_mapcount[0].lenghtx) && (Y_pos >= 0 &&  Y_pos < inde))
    {

        if (g_line[Y_pos][X_pos] == '2')
        {
            g_sprite = 1;
            g_sprite_indicator = 1;
        }
        if (g_line[Y_pos][X_pos] == '1')
            return (1);
        
    }
    return 0;

}
 int wall_collision()
{
    int X_pos;
    int Y_pos;

    X_pos = g_X_remainder / g_wall;
    Y_pos = g_Y_remainder / g_wall;
    if (g_line[Y_pos][X_pos] == '1' || g_line[Y_pos][X_pos] == '2')
    {
        return (1);
    }
    return 0;

}
unsigned int    *ft_texture(char     *file, unsigned int *texture)
{
    g_f = 0;
    g_img1 = mlx_xpm_file_to_image(g_mlx_ptr,file,&g_tab[g_f],&g_tab[g_f + 1]);
    if ((int)(g_img1) == 0)
    {
        ft_putstr("INVALID g_map");
        exit (0);
    }
    texture = (unsigned int *)mlx_get_data_addr(g_img1,&g_tab[g_f + 2],&g_tab[g_f + 3], &g_tab[g_f + 4]);
    g_f = g_f + 5;
    return texture;
}

unsigned int    convert_rgb(int r, int g, int b)
{
    unsigned int color;
    color = r;
    color = (color << 8) + g;
    color = (color << 8) + b;
    return (color);
} 
unsigned int    check_opacity(unsigned int hexcolor)
{
    double red;
    double green;
    double blue;
    double oppasity;

    oppasity = (g_distance / 1600) > 1 ? 1 : 1 - (g_distance / 1600) ;
    red = ((hexcolor >> 16) & 255) * oppasity;
    green = ((hexcolor >> 8) & 255) * oppasity;
    blue = (hexcolor & 255) * oppasity;
    return (convert_rgb(red, green, blue));
}