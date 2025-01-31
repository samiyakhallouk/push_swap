/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivotesorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:31:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/31 17:08:51 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int index_pos(t_list **stack, int index)
{
	t_list	*node;
	int		pos;

	node = (*stack);
	pos = 0;
	while (node && node->index != index)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

void	sort_three(t_list **stack)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = *stack;
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	if (node1->index > node2->index && node1->index > node3->index)
	{
		rotate(stack, 'a');
		node1 = *stack;
		node2 = (*stack)->next;
		node3 = (*stack)->next->next;
	}
	if (node2->index > node3->index)
	{
		reverse_rotate(stack, 'a');
		node1 = *stack;
		node2 = (*stack)->next;
		node3 = (*stack)->next->next;
	}
	if (node1->index > node2->index)
		swap(stack, 'a');
}

void	sort_five(t_list **stacka, t_list **stackb)
{
	int	size;
	size = ft_lstsize(*stacka) / 2;
	while ((*stacka))
	{
		if (ft_lstsize(*stacka) > 3)
		{
			if ((*stacka)->index > size || (*stacka)->index == size)
				rotate(stacka, 'a');
			else
				push(stackb, stacka, 'b');
		}
		else
			break;
	}
	sort_three(stacka);
	if ((*stackb)->index < (*stackb)->next->index)
		swap(stackb, 'b');
	while ((*stackb))
		push(stacka, stackb, 'a');	
}

void	sort_part1(t_list **stacka, t_list **stackb)
{
	int	p0;
	int	p1;
	int	p2;

	p0 = -1;
	p1 = ft_lstsize(*stacka) / 3;
	p2 = ft_lstsize(*stacka) / 6;
	while (ft_lstsize(*stacka) > 3)
	{
		if ((*stacka)->index < p1)
			push(stackb, stacka, 'b');
		else
			rotate(stacka, 'a');
		if (ft_lstsize(*stackb) > 1 && (*stackb)->index >= p0 && (*stackb)->index <= p2)
			rotate(stackb, 'b');
		if (ft_lstsize(*stackb) == p1)
		{
			p0 = p1;
			p1 += ft_lstsize(*stacka) / 3;
			p2 = (ft_lstsize(*stacka) / 6) + p0;
		}
		
	}
	sort_three(stacka);
	if (ft_lstsize(*stackb))
		sort_part2(stacka, stackb);
}

void	sort_part2(t_list **stacka, t_list **stackb)
{
	int	i;
	int	big_index;

	big_index = lastindex(stacka);
	while ((*stackb))
	{	
		i = ((*stacka)->index) - 1;
		while ((*stackb)->index != i)
		{
			if (lastindex(stacka) < (*stackb)->index || lastindex(stacka) == big_index)
			{
				push(stacka, stackb, 'a');
				rotate(stacka, 'a');
			}
			
			else if (index_pos(stackb, i) <= ft_lstsize(*stackb) / 2)
				rotate(stackb, 'b');
			else if (index_pos(stackb, i) > ft_lstsize(*stackb) / 2)
				reverse_rotate(stackb, 'b');
		}
		while ((*stackb)->index == i)
			push(stacka, stackb, 'a');
		while (((*stacka)->index) - 1 == lastindex(stacka))
			reverse_rotate(stacka, 'a');		
	}
}

// void	sort_part1(t_list **stacka, t_list **stackb, int p1, int p2)
// {
// 	int	p0;

// 	p0 = -1;
// 	while (ft_lstsize(*stacka) > 3)
// 	{
// 		if ((*stacka)->index < p1)
// 			push(stackb, stacka, 'b');
// 		else
// 			rotate(stacka, 'a');
// 		if (ft_lstsize(*stackb) > 1 && (*stackb)->index >= p0
// 			&& (*stackb)->index <= p2)
// 			rotate(stackb, 'b');
// 		if (ft_lstsize(*stackb) == p1)
// 		{
// 			p0 = p1;
// 			p1 += ft_lstsize(*stacka) / 3;
// 			p2 = ft_lstsize(*stacka) / 6 + p0;
// 		}
// 	}
// 	sort_three(stacka);
// 	if (ft_lstsize(*stackb))
// 		sort_part2(stacka, stackb, lastindex(stacka));
// }

// void	sort_part2(t_list **s_a, t_list **s_b, int bgind)
// {
// 	int	btind;

// 	btind = lastindex(s_a);
// 	while ((*s_b))
// 	{
// 		while ((*s_b) && (*s_b)->index != ((*s_a)->index) - 1)
// 		{
// 			if ((*s_b) && (lastindex(s_a) < (*s_b)->index || btind == bgind))
// 			{
// 				push(s_a, s_b, 'a');
// 				rotate(s_a, 'a');
// 				btind = lastindex(s_a);
// 			}
// 			else if ((*s_b) && ft_lstsize(*s_b)
// 				&& index_pos(s_b, (*s_a)->index - 1) <= ft_lstsize(*s_b) / 2)
// 				rotate(s_b, 'b');
// 			else if ((*s_b) && ft_lstsize(*s_b)
// 				&& index_pos(s_b, (*s_a)->index - 1) > ft_lstsize(*s_b) / 2)
// 				reverse_rotate(s_b, 'b');
// 		}
// 		while (*s_b && ((*s_b)->index == ((*s_a)->index) - 1))
// 			push(s_a, s_b, 'a');
// 		while (lastindex(s_a) == ((*s_a)->index) - 1)
// 			reverse_rotate(s_a, 'a');
// 	}
// }