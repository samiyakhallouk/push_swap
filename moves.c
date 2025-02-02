/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:31:07 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/02 17:26:15 by skhallou         ###   ########.fr       */
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
		ft_putstr("sa\n");
	else if (c == 'b')
		ft_putstr("sb\n");
}

void	push(t_list **dest, t_list **src, char c)
{
	t_list	*tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*dest);
	*dest = tmp;
	if (c == 'a')
		ft_putstr("pa\n");
	if (c == 'b')
		ft_putstr("pb\n");
}

void	rotate(t_list **stack, char c)
{
	t_list *tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	ft_lstlast(tmp)-> next = tmp;
	tmp -> next = NULL;
	if (c == 'a')
		ft_putstr("ra\n");
	if (c == 'b')
		ft_putstr("rb\n");
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list *tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		ft_putstr("rra\n");
	if (c == 'b')
		ft_putstr("rrb\n");
}
