#include "../../inc/noel.h"

t_img	*create_image(void *mlx_ptr, int w, int h)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->ptr = mlx_new_image(mlx_ptr, w, h);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, \
	&img->endian);
	return (img);
}

t_img	*create_xpm_image(void *mlx_ptr, char *path, int w, int h)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, path, &w, &h);
	if (!img->ptr)
		return (print_error(XPM_LOAD, path), NULL);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len, \
	&img->endian);
	if (!img->addr)
		return (print_error("pb with mlx get data addr for:", path), NULL);
	return (img);
}
