/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:52:55 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/26 22:21:35 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac != 1)
	{
		if (ft_lstsize(stacka) != 1)
		{
			parsing(ac, av, &stacka);
			if (checksorted(&stacka) == 0 && ft_lstsize(stacka) == 2)
				swap(&stacka, 'a');
			else if (checksorted(&stacka) == 0 && ft_lstsize(stacka) == 3)
				sort_three(&stacka);
			else if (checksorted(&stacka) == 0 && ft_lstsize(stacka) == 5)
				sort_five(&stacka, &stackb);
			else if (checksorted(&stacka) == 0)
				sort_part1(&stacka, &stackb);
			
		}	
	}
	// free_stack(&stacka);
	// free_stack(&stackb);
}