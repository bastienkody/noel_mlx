#include "../../inc/noel.h"

int	disp_fireplace(t_info *info)
{
	static int			i = 0;				// fire
	static int			j = 0;				// stars / santa
	static int			k = 0;				// deer

	static int			counter_fire = 0;
	static int			counter_stantars = 0;

	static const int	fire_x = WIN_W / 2 - 206 / 2;
	static const int	fire_y = WIN_H - 350;

	static const int	r_star_x = WIN_W - 200;
	static const int	r_star_y = 50;
	static const int	l_star_x = 200 - 120;
	static const int	l_star_y = 50;

	static const int	l_santa_x = 80;
	static const int	l_snata_y = WIN_H - 350;

	static const int	r_santa_x = WIN_W - 80 - 247;
	static const int	r_snata_y = WIN_H - 350;

	static int			x_deer = 540;
	static int			y_deer = 120;

	update_deers(&k, &x_deer);

	++counter_fire;
	if (counter_fire > FIRE_COUNTER_MAC_INTEL)
	{
		counter_fire = 0;
		i > 10 ? i = 0 : ++i;
		mlx_put_image_to_window(info->ptr, info->win, info->fireplace->ptr, 0, 0);
		mlx_put_image_to_window(info->ptr, info->win, info->fire[i]->ptr, fire_x, fire_y);
		mlx_put_image_to_window(info->ptr, info->win, info->stars[j % 3]->ptr, r_star_x, r_star_y);
		mlx_put_image_to_window(info->ptr, info->win, info->stars[j % 3]->ptr, l_star_x, l_star_y);
		mlx_put_image_to_window(info->ptr, info->win, info->santa[j]->ptr, r_santa_x, r_snata_y);
		mlx_put_image_to_window(info->ptr, info->win, info->santa[j]->ptr, l_santa_x, l_snata_y);
		mlx_put_image_to_window(info->ptr, info->win, info->deer[k % 6]->ptr, x_deer, y_deer);
	}
	++counter_stantars;
	if (counter_stantars > S_COUNTER_MAC_INTEL)
	{
		counter_stantars = 0;
		j > 4 ? j = 0 : ++j;
		mlx_put_image_to_window(info->ptr, info->win, info->fireplace->ptr, 0, 0);
		mlx_put_image_to_window(info->ptr, info->win, info->fire[i]->ptr, fire_x, fire_y);
		mlx_put_image_to_window(info->ptr, info->win, info->stars[j % 3]->ptr, r_star_x, r_star_y);
		mlx_put_image_to_window(info->ptr, info->win, info->stars[j % 3]->ptr, l_star_x, l_star_y);
		mlx_put_image_to_window(info->ptr, info->win, info->santa[j]->ptr, r_santa_x, r_snata_y);
		mlx_put_image_to_window(info->ptr, info->win, info->santa[j]->ptr, l_santa_x, l_snata_y);
		mlx_put_image_to_window(info->ptr, info->win, info->deer[k % 6]->ptr, x_deer, y_deer);
	}
	return (1);
}
