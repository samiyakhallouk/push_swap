/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:59:52 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/08 20:13:03 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_read(t_list **stack)
{
	char	*tmp;
	char	**res;
	char	*line;

	line = NULL;
	tmp = get_next_line(0);
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (!is_valid(tmp))
		{
			free(tmp);
			if (line)
				free(line);
			free_stack(stack);
			write(2, "Error\n", 6);
			exit(2);
		}
		line = join(line, tmp);
		free(tmp);
		tmp = get_next_line(0);
	}
	return (res = ft_split(line, '\n'), free(line), res);
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;
	char	**moves;

	stacka = NULL;
	stackb = NULL;
	moves = NULL;
	if (ac == 1)
		return (0);
	if (ac != 1)
	{
		parsing(ac, av, &stacka);
		moves = ft_read(&stacka);
		if (!moves)
			return (0);
		applymovesonstack(moves, &stacka, &stackb);
		if (checksorted(&stacka) && stackb == NULL)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	free_str(moves);
	free_stack(&stacka);
	free_stack(&stackb);
}
