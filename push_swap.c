/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:52:55 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/21 16:37:38 by skhallou         ###   ########.fr       */
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
		if (listsize(stacka) != 1)
		{
			parsing(ac, av, stacka);
			if (checksorted(&stacka) == 0 && listsize(stacka) == 2)
				swap(&stacka, "a");
			else if (checksortd(&stacka) == 0 && listsize(stacka) == 3)
				sort_3(&stacka);
			else if (checksorted(&stacka) == 0 && listsize(stacka) == 5)
				sort_5(&stacka);
			else if (checksorted(&stacka) == 0)
				pivotsorting(&stacka, &stackb);
			
		}	
	}
	
}