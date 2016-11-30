/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 19:02:40 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/17 13:15:06 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_int_arr(int *arr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i < (len - 1))
			ft_putstr(", ");
		i++;
	}
	ft_putchar('\n');
}
