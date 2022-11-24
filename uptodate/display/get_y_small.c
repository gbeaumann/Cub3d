#include "../cube.h"

unsigned int get_color_y1_small(t_data *data, float proy, int trigger, int x, int s)
{
    static float yn = 0;
    unsigned int        color;
    static int         y1 = 0;
    static float        ydecimal = 0;
    static float        decimal_count = 0;

    if (trigger == 1)
    {
        ydecimal = proy;
        yn = 1;
        y1 = 92/2;
        color = get_color_tex(data, x, y1, s); 
        decimal_count = 0;
        decimal_count += ydecimal;
    }
    else
    {
        y1 = yn * ydecimal;
        color = get_color_tex(data, x, y1, s);
    }
    return (color);
}