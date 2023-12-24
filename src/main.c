#include "../inc/cub3D.h"

void	unload_texture(void *mlx_ptr, t_img *img)
{
	if (img && img->ptr)
	{
		mlx_destroy_image(mlx_ptr, img->ptr);
		free(img);
	}
}

void	end_free(t_info *info)
{
	int	i = -1;

	if (info->ptr)
	{
		unload_texture(info->ptr, info->intro1);
		unload_texture(info->ptr, info->intro2);
		unload_texture(info->ptr, info->bg_default);
		if (info->fireplace)
			unload_texture(info->ptr, info->fireplace);
		while (++i < 12)
		{
			if (info->fire[i])
				unload_texture(info->ptr, info->fire[i]);
			if (i < 6 && info->santa[i])
				unload_texture(info->ptr, info->santa[i]);
			if (i < 3 && info->stars[i])
				unload_texture(info->ptr, info->stars[i]);
			if (i < 6 && info->deer[i])
				unload_texture(info->ptr, info->deer[i]);
		}
		if (info->win)
			mlx_destroy_window(info->ptr, info->win);
		mlx_destroy_display(info->ptr);
		free(info->ptr);
	}
	free(info);
	exit(EXIT_SUCCESS);
}

int	main(__attribute__((unused))int argc, __attribute__((unused))char **argv, __attribute__((unused)) char **envp)
{
	t_info	*info;

	if (! (info = malloc(sizeof(t_info))))
		return (ft_fprintf(2, "%s\n", ALLOC_FAIL), 3);
	ft_memset(info, 0, sizeof(t_info));
	run(info);
	return (end_free(info), 0);
}
