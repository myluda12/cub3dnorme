#include "cub3d.h"

void direction_global()
{
    g_direction.ea = 0;
    g_direction.no = 0;
    g_direction.su = 0;
    g_direction.we = 0;
    g_direction.s = 0;
    g_direction.f = 0;
    g_direction.c = 0;
}
void ft_header(void)
{
    g_screenmap.header = ft_calloc(54,1);
    g_screenmap.bit_count = 24;
    g_screenmap.g_width = g_width;
    g_screenmap.g_height = g_height;
    g_screenmap.width_in_byte = ((g_screenmap.g_width * g_screenmap.bit_count + 31) / 32) * 4;
    g_screenmap.image_size = g_screenmap.width_in_byte * g_screenmap.g_height;
    g_screenmap.size_header = 40;
    g_screenmap.offset_bits = 40 + 14;
    g_screenmap.file_size = g_screenmap.offset_bits + g_screenmap.image_size;
    g_screenmap.planes = 1;
    ft_memcpy(g_screenmap.header , "BM" , 2);
    ft_memcpy(g_screenmap.header + 2, &g_screenmap.file_size, 4);
    ft_memcpy(g_screenmap.header + 10, &g_screenmap.offset_bits, 4);
    ft_memcpy(g_screenmap.header + 14 , &g_screenmap.size_header, 4);
    ft_memcpy(g_screenmap.header + 18, &g_screenmap.g_width, 4);
    ft_memcpy(g_screenmap.header + 22 , &g_screenmap.g_height, 4);
    ft_memcpy(g_screenmap.header + 26 , &g_screenmap.planes, 2);
    ft_memcpy(g_screenmap.header + 28, &g_screenmap.bit_count, 2);
    ft_memcpy(g_screenmap.header + 34 , &g_screenmap.image_size, 4);
}

int *get_color(int coloor)
{
    int *colors;
    colors = malloc(3 * sizeof(int));
    colors[0] = ((coloor >> 16) & 0xFF);
    colors[1] = ((coloor >> 8) & 0xFF);
    colors[2] = ((coloor) & 0xFF);
    return (colors);

}

void create_image(void)
{
    int row;
    unsigned int col;
    int *colors;

    g_screenmap.img = malloc(g_screenmap.image_size);
    row = g_screenmap.g_height - 1;
    while(row > 0)
    {
        col = 0;
        while(col < g_screenmap.g_width)
        {
            colors = get_color(g_data[(g_screenmap.g_height - row) * g_screenmap.g_width + col]);
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 2] = colors[0];
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 1] = colors[1];
            g_screenmap.img[row * g_screenmap.width_in_byte + col * 3 + 0] = colors[2];
            col++;
        }
        row--;
    }
}

void screenshot(void)
{
    g_screenmap.fd = open("./screenshot.bmp", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    ft_header();
    create_image();
    write(g_screenmap.fd,g_screenmap.header,54);
    write(g_screenmap.fd,g_screenmap.img,g_screenmap.image_size);
    free(g_screenmap.header);
    free(g_screenmap.img);
    exit(0);
}