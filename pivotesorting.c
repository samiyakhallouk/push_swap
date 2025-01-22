/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotesorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:31:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/22 21:48:58 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list **sort_3(t_list **stacka)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = (*stacka);
	node2 = (*stacka)->next;
	node3 = (*stacka)->next->content;
	if (node1->index > node2->index && node1->index > node3->index)
	{
		rotate(stacka, 'a');
		node1 = (*stacka);
		node2 = (*stacka)->next;
		node3 = (*stacka)->next;
	}
	if (node1->index > node3->index)
	{
		reverse_rotate(stacka, 'a');
		node1 = (*stacka);
		node2 = (*stacka)->next;
		node3 = (*stacka)->next;
	}
	if(node1->index > node2->index)
		swap(stacka, 'a');
}

t_list **sort_5(t_list **stacka, t_list **stackb)
{
	int	size;

	
	while ((*stacka))
	{
		if (ft_lstsize(*stacka) > 3)
		{
			if ((*stacka)->index > (size / 2))
				rotate(*stacka, 'a');
			push(stackb, stacka, 'b');	
		}
		(*stacka) = (*stacka)->next;
	}
	sort_3(stacka);
}

pivotsorting(t_list **stacka, t_list **stackb)
{
	
}