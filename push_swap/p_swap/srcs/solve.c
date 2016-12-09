/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:08:12 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 11:45:57 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*move_to_B(char *solution, t_super_stack *super_stack)
{
	int		idx_to_move;
	int		num_to_move;
	int		midA;
	int		midB;
	int		right_place;

	idx_to_move = find_shortest_path_to_sorted_B(super_stack);
	num_to_move = super_stack->stackA->nums[idx_to_move];
	midA = super_stack->stackA->cur_size / 2;
	midB = super_stack->stackB->nums[super_stack->stackB->cur_size / 2];		
	right_place = find_right_location(super_stack->stackB, num_to_move);
	solution = reverse_rotations(solution, super_stack);
	solution = forward_rotations(solution, super_stack);
	solution = update_solution(solution, "pb");
	perform_op("pb", super_stack->stackA, super_stack->stackB, super_stack->flags);
	return (solution);
}


char		*update_solution(char *solution, char *op)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(solution);
	dst = solution + len;
	ft_strcpy(dst, op); 
	ft_strcat(dst, "\n");
	solution = ft_realloc(solution, len + 5);
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

void		solve(t_super_stack *super_stack)
{
	char	*solution;

	solution = ft_strnew(5);
	if (super_stack->flags->v)	
		display_stacks(super_stack->stackA, super_stack->stackB);
	solution = b_solver(solution, super_stack);	
	ft_printf("%s", solution);
}
