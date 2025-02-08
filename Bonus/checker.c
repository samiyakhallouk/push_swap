/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:59:52 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/08 18:57:04 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

// char	**ft_read(void)
// {
// 	char	*buffer;
// 	char	*line;
// 	char	**res;
// 	int		byte_read;
// 	char	*tmp;
// 	int i = 0;

// 	line = NULL;
// 	byte_read = 1;
// 	// buffer = malloc(1000 + 1);
// 	// if (!buffer)
// 	// 	return (NULL);
// 	while (byte_read)
// 	{
// 		buffer = malloc(1000 + 1);
// 		if (!buffer)
// 			return (NULL);
// 		byte_read = read(0, buffer, 1000);
// 		if (byte_read < 0)
// 			return (free(buffer), NULL);
// 	char	**ft_read(void)
// {
// 	char	*buffer;
// 	char	*line;
// 	char	**res;
// 	int		byte_read;
// 	char	*tmp;
// 	int i = 0;

// 	line = NULL;
// 	byte_read = 1;
// 	// buffer = malloc(1000 + 1);
// 	// if (!buffer)
// 	// 	return (NULL);
// 	while (byte_read)
// 	{
// 		buffer = malloc(1000 + 1);
// 		if (!buffer)
// 			return (NULL);
// 		byte_read = read(0, buffer, 1000);
// 		if (byte_read < 0)
// 			return (free(buffer), NULL);
// 		buffer[byte_read] = '\0';
// 		while (buffer[i] && buffer[i] != '\n')
// 			i++;
// 		if (buffer[i] && buffer[i] == '\n')
// 			i++;
// 		tmp = malloc(i + 1);
// 		i = 0;
// 		while (buffer[i] && buffer[i] != '\n')
// 		{
// 			tmp[i] = buffer[i];
// 			i++;
// 		}
// 		if (buffer[i] && buffer[i] == '\n')
// 		{
// 			tmp[i] = buffer[i];
// 			i++;
// 		}
// 		tmp[i] = '\0';
// 		printf("%s", tmp);
// 		// printf("n = %d\n", byte_read);
// 		if (!is_valid(tmp) && byte_read)
// 		{
// 			write(2, "Errop\n", 6);
// 			exit(2);
// 		}
// 		free(tmp);
// 		tmp = NULL;
// 		line = join(line, buffer);
// 		free(buffer);
// 		buffer = NULL;
// 	}
// 	return (res = ft_split(line, '\n'), free(line), res);
// }

char	**ft_read(void)
{
	char	*tmp;
	char	**res;
	char	*line;

	line = NULL;
	tmp = get_next_line();
	while (tmp)
	{
		if (!is_valid(tmp))
		{
			free(tmp);
			write(2, "Errop\n", 6);
			exit(2);
		}
		line = join(line, tmp);
		free(tmp);
		tmp = get_next_line();
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
	if (ac == 1) return (0);
	if (ac != 1)
	{
		parsing(ac, av, &stacka);
		moves = ft_read();
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
