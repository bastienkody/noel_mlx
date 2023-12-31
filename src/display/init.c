#include "../../inc/noel.h"

static const char	*fire_pathes[12] = 
{
	"map/fire/fire1.xpm",
	"map/fire/fire2.xpm",
	"map/fire/fire3.xpm",
	"map/fire/fire4.xpm",
	"map/fire/fire5.xpm",
	"map/fire/fire6.xpm",
	"map/fire/fire7.xpm",
	"map/fire/fire8.xpm",
	"map/fire/fire9.xpm",
	"map/fire/fire10.xpm",
	"map/fire/fire11.xpm",
	"map/fire/fire12.xpm",
};

static const char	*santa_pathes[6] = 
{
	"map/santa/santa1.xpm",
	"map/santa/santa2.xpm",
	"map/santa/santa3.xpm",
	"map/santa/santa4.xpm",
	"map/santa/santa5.xpm",
	"map/santa/santa6.xpm",
};

static const char	*deer_pathes[6] = 
{
	"map/reindeer/tripledeerleft1.xpm",
	"map/reindeer/tripledeerleft2.xpm",
	"map/reindeer/tripledeerleft3.xpm",
	"map/reindeer/tripledeerright1.xpm",
	"map/reindeer/tripledeerright2.xpm",
	"map/reindeer/tripledeerright3.xpm",
};

static const char	*star_pathes[6] = 
{
	"map/santa/star1.xpm",
	"map/santa/star2.xpm",
	"map/santa/star3.xpm",
};

int	load_textures_fire(t_info *info)
{
	for (int i = 0; i < 12; ++i)
	{
		info->fire[i] = create_xpm_image(info->ptr, (char *)fire_pathes[i], 206, 275);
		if (!info->fire[i] || !info->fire[i]->ptr)
			return (print_error(XPM_LOAD, "fire"), 0);
	}
	return (1);
}

int	load_textures_santa(t_info *info)
{
	for (int i = 0; i < 6; ++i)
	{
		info->santa[i] = create_xpm_image(info->ptr, (char *)santa_pathes[i], 207, 247);
		if (!info->santa[i] || !info->santa[i]->ptr)
			return (print_error(XPM_LOAD, "santa"), 0);
	}
	return (1);
}

int	load_textures_reindeer(t_info *info)
{
	for (int i = 0; i < 6; ++i)
	{
		info->deer[i] = create_xpm_image(info->ptr, (char *)deer_pathes[i], 96, 32);
		if (!info->deer[i] || !info->deer[i]->ptr)
			return (print_error(XPM_LOAD, "deer"), 0);
	}
	return (1);
}

int	load_textures_stars(t_info *info)
{
	for (int i = 0; i < 3; ++i)
	{
		info->stars[i] = create_xpm_image(info->ptr, (char *)star_pathes[i], 120, 100);
		if (!info->stars[i] || !info->stars[i]->ptr)
			return (print_error(XPM_LOAD, "stars"), 0);
	}
	return (1);
}

int	load_textures_fireplace(t_info *info)
{
	info->fireplace = create_xpm_image(info->ptr, "map/chimney/fireplace.xpm", WIN_W, WIN_H);
	if (!info->fireplace || !info->fireplace->ptr)
			return (print_error(XPM_LOAD, NULL), 0);
	return (1);
}

int	init_display(t_info *info)
{
	info->ptr = mlx_init();
	if (!info->ptr)
		return (print_error(BAD_INI, NULL), 0);
	info->win = mlx_new_window(info->ptr, WIN_W, WIN_H, "Noel mlx fireplace");
	if (!info->win)
		return (print_error(BAD_WIN, NULL), 0);
	if (!load_textures_fire(info) || \
		!load_textures_santa(info) || \
		!load_textures_stars(info) || \
		!load_textures_fireplace(info) || \
		!load_textures_reindeer(info))
		return (0);
	return (1);
}

void	run(t_info *info)
{
	if (!init_display(info))
		return ;
	mlx_key_hook(info->win, &key_inputs, info);
	mlx_hook(info->win, 17, 0, &end_free, info);
	mlx_loop_hook(info->ptr, &disp_fireplace, info);
	mlx_loop(info->ptr);
}
