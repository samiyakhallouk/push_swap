/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:27:21 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/02 17:49:07 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join_list(int ac, char **av)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 1;
	new = NULL;
	while (i < ac)
	{
		if (!av[i] || is_space_tab(av[i]))
		{
			write(2, "Error\n", 6);
			exit(2);
		}
		
		tmp = join(new, av[i]);
		new = join(tmp, " ");
		i++;
	}
	return (new);
}

void	check_repeat(t_list **stack)
{
	t_list	*tmp;
	t_list	*node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->content == tmp->content)
				free_stack(stack);
			tmp = tmp->next;
		}
		node = node->next;
	}
}

void	indexing_node(t_list **stack)
{
	t_list	*tmp;
	t_list	*node;
	int		i;

	if (!stack || !*stack)
		return ;
	node = *stack;
	while (node)
	{
		i = 0;
		tmp = *stack;
		while (tmp)
		{
			if (node->content > tmp->content)
				i++;
			tmp = tmp->next;
		}
		node->index = i;
		node = node->next;
	}
}

void	fill_stack(t_list **stack, char **splited)
{
	int		n;
	int		i;
	t_list	*node;
	
	i = 0;
	while (splited[i])
	{
		n = ft_atoi(splited[i], stack);
		node = ft_lstnew(n);
		ft_lstadd_back(stack, node);
		i++;
	}
	check_repeat(stack);
	indexing_node(stack);
}

void	parsing(int ac, char **av, t_list **stack)
{
	char	**splited;
	char	*list;

	list = join_list(ac, av);
	if (!list)
		exit(1);
	splited = ft_split(list, ' ');
	free(list);
	if (!splited)
	{
		free_str(splited);
		exit(1);
	}
	fill_stack(stack, splited);
	free_str(splited);
}
