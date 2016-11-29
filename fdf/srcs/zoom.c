#include "fdf.h"

void	unzoom(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((map->points[arr_i][point_i]).end))
		{
			point = &(map->points[arr_i][point_i]); 
			point->z_prime *= 0.9;
			point->x_prime *= 0.9;
			point->y_prime *= 0.9;
			point_i++;  		
		}
		arr_i++;
	}
	map->scale *= 0.95;
}

void	zoom(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((map->points[arr_i][point_i]).end))
		{
			point = &(map->points[arr_i][point_i]); 
			point->z_prime *= 1.1;
			point->x_prime *= 1.1;
			point->y_prime *= 1.1;
			point_i++;  		
		}
		arr_i++;
	}
	map->scale *= 1.05;
}

void	zoom_detective(t_map *map)
{
		if (map->zoom_sign == 1)
			zoom(map);
		else if (map->zoom_sign == -1)
			unzoom(map);
		mlx_clear_window(map->mlx, map->win);
		center(map);
		print_primes(map);
}