/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applymoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:40:41 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/01 18:27:01 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	is_valid(char *move)
{
	if (ft_strcmp(move, "sa") == 0)
		return (1);
	else if (ft_strcmp(move, "sb") == 0)
		return (1);
	else if (ft_strcmp(move, "pa") == 0)
		return (1);
	else if (ft_strcmp(move, "pb") == 0)
		return (1);
	else if (ft_strcmp(move, "ra") == 0)
		return (1);
	else if (ft_strcmp(move, "rb") == 0)
		return (1);
	else if (ft_strcmp(move, "rra") == 0)
		return (1);
	else if (ft_strcmp(move, "rrb") == 0)
		return (1);
	else
		return (0);
}

void	applymoves(char *move, t_list **stacka, t_list **stackb)
{
	if (ft_strcmp(move, "sa") == 0)
		swap(stacka, 'a');
	else if (ft_strcmp(move, "sb") == 0)
		swap(stackb, 'b');
	else if (ft_strcmp(move, "pa") == 0)
		push(stacka, stackb,'a');
	else if (ft_strcmp(move, "pb") == 0)
		push(stackb, stacka,'b');
	else if (ft_strcmp(move, "ra") == 0)
		rotate(stacka, 'a');
	else if (ft_strcmp(move, "rb") == 0)
		rotate(stackb, 'b');
	else if (ft_strcmp(move, "rra") == 0)
		reverse_rotate(stacka, 'a');
	else if (ft_strcmp(move, "rrb") == 0)
		reverse_rotate(stackb, 'b');
}

void	applymovesonstack(char **moves, t_list **stacka, t_list **stackb)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (!is_valid(moves[i]))
		{
			write(2, "Error!\n", 6);
			exit(1);
		}
		applymoves(moves[i], stacka, stackb);
		i++;
	}
}