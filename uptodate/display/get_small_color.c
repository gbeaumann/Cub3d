#include "../cube.h"

unsigned int get_small_color_y1(t_data *data, float proy, int trigger, int x, int s)
{
    static float        yimg = 0;
    unsigned int        color;
    static int          y1 = 0;
    static float        ydecimal = 0;
    static float        decimal_count = 0;
    
    if (trigger == 1)
    {
        yimg = 1/proy;
        y1 = IMG_HEIGTH/2;
        ydecimal = ((1/proy) - yimg);
        if (ydecimal > 0.8)
            yimg += 1;
        color = get_color_tex(data, x, y1, s); 
    }
    else
    {
        y1 += yimg;
        color = get_color_tex(data, x, y1, s);
    }
    return (color);
}

unsigned int get_small_color_y2(t_data *data, float proy, int trigger, int x, int s)
{
    static int        yimg = 0;
    unsigned int        color;
    static int          y2 = 0;
    static float        ydecimal = 0;
    static float        decimal_count = 0;

    if (trigger == 1)
    {
        yimg = (int)1/proy;
        ydecimal = ((1/proy) - yimg);
        if (ydecimal > 0.8)
            yimg += 1;
        if (data->n == data->ray1)
        {
            printf("yimg: %d\n", yimg);
            printf("ydecimal: %f\n", ydecimal);
        }
        y2 = IMG_HEIGTH/2;
        color = get_color_tex(data, x, y2, s);
        decimal_count = 0;
        //decimal_count += ydecimal;
    }
    else
    {
        if (decimal_count >= yimg)
        {
            y2 -= yimg;
            decimal_count = 0;
            //color = get_color_tex(data, x, y2, s);
        }
        else
        {
            y2 -= yimg;
            color = get_color_tex(data, x, y2, s);
            //decimal_count += ydecimal;
        }
    }
    return (color);
}