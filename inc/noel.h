#ifndef CUB3D_H
# define CUB3D_H

/*	includes	*/
# include "../libs/mlx/mlx.h"
# include "../libs/libft/libft.h"
# include <stdbool.h>
# include <X11/keysym.h>

/*	generic errors */
# define ALLOC_FAIL "Malloc error - program exiting"
# define BAD_INI "Mlx initialization failed. Perhaps check envp before retry"
# define BAD_WIN "Mlx window creation failed"
# define XPM_LOAD "XPM image load failure; context: "
# define NO_FETCH_RES "Could not fetch screen resolution from system (the game \
window is designed to be 1920x1080)"
# define LOWER_RES "Screen resolution is lower than expected (1920x1080), you \
might change hardware to fully enjoy the game :)"

/*	num const	*/
# define WIN_W 1920
# define WIN_H 1010
# define MENUBAR_H 70

/*	volecity	*/
# define DEERSTEP 12

/*	counters*/
# define FIRE_COUNTER_MAC_INTEL 5500
# define S_COUNTER_MAC_INTEL 35000
# define DEER_COUNTER_MAC_INTEL 7500

/*	colors	*/
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
#define GREY 0x00808080
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

/*	typedef	*/
typedef bool	t_bool;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_info
{
	void			*ptr;
	void			*win;
	t_img			*bg_default;
	t_img			*fireplace;
	t_img			*fire[12];
	t_img			*santa[16];
	t_img			*stars[3];
	t_img			*deer[6];
}				t_info;

/*	display	*/
void	run(t_info *info);
int		init_display(t_info *info);
int		disp_fireplace(t_info *info);
void	update_deers(int *k, int *x_deer);

/*	hooks	*/
int		key_inputs(int keycode, t_info *info);

/*	img	*/
t_img	*create_image(void *mlx_ptr, int w, int h);
t_img	*create_xpm_image(void *mlx_ptr, char *path, int w, int h);

/*	printers	*/
void	print_error(char *str1, char *str2);

/*	free	*/
int		end_free(t_info *info);

#endif
