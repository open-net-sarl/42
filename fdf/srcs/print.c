/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:22:37 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/21 17:58:08 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_inits(void *mlx, void *win, t_point **points)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;
	t_point	right_point;
	t_point	below_point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			cur_point = points[arr_i][point_i];
		//	printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init); 
			if (!((points[arr_i][point_i + 1]).end))
			{
				right_point = points[arr_i][point_i + 1];
				draw_line(mlx, win, &cur_point, &right_point);   		
			}
			if (points[arr_i + 1])
			{
				below_point = points[arr_i + 1][point_i];
				//printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n below->x: %lf, below->y: %lf, below->z: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init, below_point.x_init, below_point.y_init, below_point.z_init); 
				draw_line(mlx, win, &cur_point, &below_point); 
			}
			point_i++;  		
		}
		arr_i++;
	}
}

void		print_primes(void *mlx, void *win, t_point **points)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;
	t_point	right_point;
	t_point	below_point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			cur_point = points[arr_i][point_i];
		//	printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init); 
			if (!((points[arr_i][point_i + 1]).end))
			{
				right_point = points[arr_i][point_i + 1];
				draw_prime(mlx, win, &cur_point, &right_point);   		
			}
			if (points[arr_i + 1])
			{
				below_point = points[arr_i + 1][point_i];
				//printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n below->x: %lf, below->y: %lf, below->z: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init, below_point.x_init, below_point.y_init, below_point.z_init); 
				draw_prime(mlx, win, &cur_point, &below_point); 
			}
			point_i++;  		
		}
		arr_i++;
	}
}