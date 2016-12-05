/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:08:12 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 17:20:00 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*update_solution(char *solution, char *op)
{
	char	*dst;
	char	*s;
	size_t	len;

	ft_printf("solution before each update: %s\n", solution);
	s = (char*)malloc(ft_strlen(solution));
	len = ft_strlen(s);
	dst = solution + len;
	ft_strcpy(dst, op); 
	ft_strcat(dst, "\n");
	ft_printf("s before realloc: %s\n", s);
	solution = ft_realloc(s, len + 5);
	ft_printf("solution after each update: %s\n", solution);
	return (solution);
}

int			perform_op(char *op, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_first_two(stackA);
	else if (ft_strcmp(op, "sb") == 0)
		swap_first_two(stackB);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stackA, stackB);
	else if (ft_strcmp(op, "pa") == 0)
		push_on_A(stackA, stackB);
	else if (ft_strcmp(op, "pb") == 0)
		push_on_B(stackA, stackB);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stackA);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stackB);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stackA, stackB);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(stackA);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(stackB);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(stackA, stackB);
	else
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (flags->v)	
		display_stacks(stackA, stackB);
	return (1);
}

void		find_min(t_stack *stackA)
{
	int		min;
	int		i;

	min = stackA->nums[0];
	i = 1;
	while (i < stackA->cur_size)
	{
		if (stackA->nums[i] < min)	
		{
			min = stackA->nums[i];
			stackA->min_num = min;
			stackA->min_idx = i;
		}
		i++;
	}
}