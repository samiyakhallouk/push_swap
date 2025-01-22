/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:31:07 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/21 21:31:21 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (c == 'a')
		ft_putstr("sa");
	else if (c == 'b')
		ft_putstr("sb");
}

void	push(t_list **dest, t_list **src, char c)
{
	t_list	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*dest);
	*src = tmp;
	if (c == 'a')
		ft_putstr("pa");
	if (c == 'b')
		ft_putstr("pb");
}

void	rotate(t_list **stack, char c)
{
	t_list *tmp;

	tmp = *stack;
	(*stack) = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	if (c == 'a')
		ft_putstr("ra");
	if (c == 'b')
		ft_putstr("rb");
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		ft_pustr("rra");
	if (c == 'b')
		ft_putstr("rrb");
}