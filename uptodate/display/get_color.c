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
        y1 = 92/2;
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
        y2 = (92/2);
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

//maybe right
/*int get_xval_sprite(t_data *data)
{
    static float prox = 0;
    static int xn = 0;
    static int x = 0;
    static float        xdecimal = 0;
    static float        decimal_count = 0;

    if (data->ray[data->n].wall == 'S' && data->ray[data->n - 1].wall != 'S')
	{
		prox = rule_of_three_x(data);
        //prox = find_prox(data);
        xdecimal = (prox - ((int)prox));
        decimal_count = 0;
        decimal_count += xdecimal;
        printf("rule of three x %f ===========================\n", prox);
		xn = 1;
        //x = data->xstart;
        printf("xstart: %d\n", data->xstart);
        x = 0;
	}
    else if (data->ray[data->n].wall == 'S')
    {
        if (xn == (int)prox)
        {
            decimal_count += xdecimal;
            x++;
            xn = 0;
        }
        if ((xn + decimal_count) >= (int)prox)
            decimal_count -= 1;
        else
            xn++;
    }
    return (x);
}*/
