/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:09:50 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/02 17:10:41 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap1(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	push1(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = (*dest);
	*dest = tmp;
}

void	rotate1(t_list **stack)
{
	t_list *tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	(*stack) = (*stack)->next;
	ft_lstlast(tmp)-> next = tmp;
	tmp -> next = NULL;
}

void	reverse_rotate1(t_list **stack)
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
}