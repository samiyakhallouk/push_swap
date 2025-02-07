/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:59:52 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/07 20:07:21 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_read(void)
{
	char	*buffer;
	char	*line;
	char	**res;
	int		byte_read;

	line = NULL;
	byte_read = 1;
	buffer = malloc(1000 + 1);
	if (!buffer)
		return (NULL);
	while (byte_read)
	{
		byte_read = read(0, buffer, 1000);
		if (byte_read < 0)
			return (free(buffer), NULL);
		buffer[byte_read] = '\0';
		line = join(line, buffer);
		if (!is_valid(buffer))
		{
			write(2, "Error\n", 6);
			return(NULL);
		}
	}
	free(buffer);
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
	if (ac != 1)
	{
		parsing(ac, av, &stacka);
		moves = ft_read();
		applymovesonstack(moves, &stacka, &stackb);
		if (checksorted(&stacka) && stackb == NULL)
			ft_putstr("ok\n");
		else
			ft_putstr("ko\n");
	}
	free_str(moves);
	free_stack(&stacka);
	free_stack(&stackb);
}
