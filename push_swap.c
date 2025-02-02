/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:52:55 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/02 17:51:06 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void f()
// {
// 	system("leaks push_swap");
// }

int	main(int ac, char **av)
{
	// atexit(f);
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac != 1)
	{
		if (ft_lstsize(stacka) != 1)
		{
			parsing(ac, av, &stacka);
			if (!checksorted(&stacka) && ft_lstsize(stacka) == 2)
				swap(&stacka, 'a');
			else if (!checksorted(&stacka) && ft_lstsize(stacka) == 3)
				sort_three(&stacka);
			else if (!checksorted(&stacka) && ft_lstsize(stacka) == 5)
				sort_five(&stacka, &stackb);
			else if (!checksorted(&stacka))
				sort_part1(&stacka, &stackb);
		}
	}
	free_stack(&stacka);
	free_stack(&stackb);
}