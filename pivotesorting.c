/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotesorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:31:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/26 22:25:59 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stacka)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = (*stacka);
	node2 = (*stacka)->next;
	node3 = (*stacka)->next->next;
	if (node1->index > node2->index && node1->index > node3->index)
	{
		rotate(stacka, 'a');
		node1 = (*stacka);
		node2 = (*stacka)->next;
		node3 = (*stacka)->next;
	}
	if (node2->index > node3->index)
	{
		reverse_rotate(stacka, 'a');
		node1 = (*stacka);
		node2 = (*stacka)->next;
		node3 = (*stacka)->next;
	}
	if(node1->index > node2->index)
		swap(stacka, 'a');
}

void	sort_five(t_list **stacka, t_list **stackb)
{
	int	size;
	int flag;

	flag = 0;
	size = ft_lstsize(*stacka) / 2;
	while ((*stacka))
	{
		if (ft_lstsize(*stacka) > 3)
		{
			if (flag == 1)
				size -= 1;
			if ((*stacka)->index > size)
			{
				rotate(stacka, 'a');
				flag = 0;
			}
			else
			{
				push(stackb, stacka, 'b');	
				flag = 1;
			}
		}
		else
			break;
	}
	sort_three(stacka);
	while (*stackb)
	{
		if ((*stackb) < (*stackb)->next)
			swap(stackb, 'b');
		else
			push(stacka, stackb, 'a');
	}
}

void	sort_part1(t_list **stacka, t_list **stackb)
{
	int	lp1;
	int	p1;
	int	p2;

	lp1 = -1;
	p1 = ft_lstsize(*stacka) / 3;
	p2 = ft_lstsize(*stacka) / 6;
	while (ft_lstsize(*stacka) > 3)
	{
		if ((*stacka)->index < p1)
			push(stackb, stacka, 'b');
		else
			rotate(stacka, 'a');
		if (ft_lstsize(*stackb) > 1 && (*stackb)->index >= lp1 && (*stackb)->index <= p2)
			rotate(stackb, 'b');
		if (ft_lstsize(*stackb) == p1)
		{
			lp1 = p1;
			p1 += ft_lstsize(*stacka) / 3;
			p2 = (ft_lstsize(*stacka) / 6) + lp1;
		}
		
	}
	sort_three(stacka);
	if (ft_lstsize(*stackb))
		sort_part2(stacka, stackb);
	while (*stacka)
	{
		printf("%d\n", (*stacka)->content);
		(*stacka) = (*stacka)->next;
	}
}

int index_pos(t_list **stack, int index)
{
	t_list	*node;
	int		pos;

	node = (*stack);
	while (node && node->index != index)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

void	sort_part2(t_list **stacka, t_list **stackb)
{
	int	i;

	while ((*stackb))
	{	
		i = ((*stacka)->index) - 1;
		if ((*stackb)->index != i)
		{
			if (index_pos(stackb, i) <= ft_lstsize(*stackb) / 2)
				rotate(stackb, 'b');
			else
				reverse_rotate(stackb, 'b');
		}
		else
		{
			push(stacka, stackb, 'a');
			if (((*stacka)->index) - 1 == lastindex(stacka))
				reverse_rotate(stacka, 'a');
		}		
	}
}