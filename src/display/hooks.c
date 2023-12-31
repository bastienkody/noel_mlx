#include "../../inc/noel.h"

int	key_inputs(int keycode, t_info *info)
{
	//ft_fprintf(1, "keycode:%i\n", keycode);
	if (keycode == XK_Escape || keycode == XK_q)
		end_free(info);
	return (1);
}

void	update_deers(int *k, int *x_deer)
{
	static int			counter_deer = 0;
	static int			deerdir = 1;		// deer from l to r

	++counter_deer;
	if (counter_deer > DEER_COUNTER_MAC_INTEL)
	{
		counter_deer = 0;
		if (deerdir == 1)	// going to the right (sprites 0,1 2)
		{
			if (*x_deer + 96 + DEERSTEP >= WIN_W - 540)
			{
				deerdir *= -1;
				*k = 3;
			}
			else
			{
				*k + 1 > 2 ? *k = 0 : (*k)++;
				*x_deer += DEERSTEP;
			}
		}
		else			// going left (sprites 3 4 5)
		{
			if (*x_deer - DEERSTEP / 2 <= 540)
			{
				deerdir *= -1; 
				*k = 0;
			}
			else
			{
				*k + 1 > 5 ? *k = 3 : (*k)++;
				*x_deer -= DEERSTEP;
			}
		}
	}
}

