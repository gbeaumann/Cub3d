#include "../cube.h"

//y1 going downwards
unsigned int get_color_y1(t_data *data, float proy, int trigger, int x, int s)
{
    static float yn = 0;
    unsigned int        color;
    static int         y1 = 0;
    static float        ydecimal = 0;
    static float        decimal_count = 0;

    if (trigger == 1)
    {
        ydecimal = (proy - (int)proy);
        yn = 1;
        y1 = IMG_HEIGTH/2;
        color = get_color_tex(data, x, y1, s); 
        decimal_count = 0;
        decimal_count += ydecimal;
    }
    else
    {
        if (yn == (int)proy)
        {
            decimal_count += ydecimal;
            y1 ++;
            yn = 0;
        }
        if ((yn + decimal_count) >= (int)proy)
        {
            color = get_color_tex(data, x, y1, s);
            decimal_count -=1;
        }
        else
        {
            color = get_color_tex(data, x, y1, s);
            yn++;
        }
    }
    return (color);
}

//y2 going upward
unsigned int get_color_y2(t_data *data, float proy, int trigger, int x, int s)
{
    static float yn = 0;
    unsigned int        color;
    static int         y2 = 0;
    static float        ydecimal = 0;
    static float        decimal_count = 0;

    if (trigger == 1)
    {
        ydecimal = (proy - (int)proy);
        yn = 1;
        y2 = (IMG_HEIGTH/2);
        color = get_color_tex(data, x, y2, s);
        decimal_count = 0;
        decimal_count += ydecimal;
    }
    else
    {
        if (yn == (int)proy)
        {
            decimal_count += ydecimal;
            y2 --;
            yn = 0;
        }
        if ((yn + decimal_count) >= (int)proy)
        {
            color = get_color_tex(data, x, y2, s);
            decimal_count -=1;
        }
        else
        {
            color = get_color_tex(data, x, y2, s);
            yn++;
        }
    }
    return (color);
}
