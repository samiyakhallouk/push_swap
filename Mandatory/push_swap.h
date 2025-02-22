/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:00:40 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/22 20:56:01 by skhallou         ###   ########.fr       */
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
}	t_list;

//parsing

char	*join_list(int ac, char **av);
void	check_repeat(t_list **stack, char **splited);
void	indexing_node(t_list **stack);
void	parsing(int ac, char **av, t_list **stack);
void	fill_stack(t_list **stack, char **splited);

//pivotesorting

void	sort_three(t_list **stacka);
void	sort_five(t_list **stacka, t_list **stackb);
void	sort_part1(t_list **stacka, t_list **stackb);
int		index_pos(t_list **stack, int index);
void	sort_part2(t_list **stacka, t_list **stackb, int big_index);

//moves

void	swap(t_list **stack, char c);
void	push(t_list **dest, t_list **src, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);

//helperlist

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		lastindex(t_list **stack);

//helper

long	ft_atoi(char *s, t_list **stack, char **splited);
int		is_space_tab(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(char *src);
char	*join(char *s1, char *s2);

//helper1

void	ft_putstr(char *s);
void	free_str(char **str);
void	free_stack(t_list **stack);
void	check_error(t_list **stack, char **splited);
int		checksorted(t_list **stack);

char	**ft_split(char *s, char c);

#endif