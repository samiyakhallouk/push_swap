/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:07:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/19 20:01:32 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_stack(t_list **stack)
{
	t_list	*node;
	t_list	*curr;

	curr = (*stack);
	while (curr)
	{
		node = curr->next;
		free(curr);
		curr = node;
	}
	(*stack) = NULL;
}

void	check_error(t_list **stack, char **splited)
{
	t_list	*node;
	t_list	*curr;

	if (stack && *stack)
	{
		curr = (*stack);
		while (curr)
		{
			node = curr->next;
			free(curr);
			curr = node;
		}
		stack = NULL;
	}
	free_str(splited);
	write(2, "Error\n", 6);
	exit(2);
}

int	checksorted(t_list **stack)
{
	t_list	*node;

	node = (*stack);
	while (node && node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}
