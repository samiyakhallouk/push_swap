/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:00:20 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/22 20:55:07 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(char *s, t_list **stack, char **splited)
{
	int		i;
	int		sign;
	long	r;

	i = 0;
	r = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	if (s[i] < '0' || s[i] > '9')
		check_error(stack, splited);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			check_error(stack, splited);
		r = r * 10 + s[i] - '0';
		if (((r * sign) > 2147483647) || ((r * sign) < -2147483648))
			check_error(stack, splited);
		i++;
	}
	return (r * sign);
}

int	is_space_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (!src)
		return (NULL);
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*join(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	newstring = malloc(len + 1);
	if (!newstring)
		return (free(s1), NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstring[i++] = s2[j++];
	newstring[i] = 0;
	return (free(s1), newstring);
}
