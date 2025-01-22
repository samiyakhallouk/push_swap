/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:00:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/01/21 16:07:27 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
} t_list;


//linkedlist

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
t_list	ft_lstadd_back(t_list **lst, t_list *new);
int		lstsize(t_list *lst);

//parsing

char	*join_list(int ac, char **av);
void	check_repeat(t_list **stack);
void	indexing_content(t_list **stack);
void	parsing(int ac, char **av, t_list **stack);
void	fill_stack(t_list **stack, char **splited);





#endif