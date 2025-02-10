/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:11:12 by skhallou          #+#    #+#             */
/*   Updated: 2025/02/10 14:34:05 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

static char	*ft_strncpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*read_file(char *reminder)
{
	int		byte_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(reminder), reminder = NULL, NULL);
	byte_read = 1;
	while (byte_read)
	{
		byte_read = read(0, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), buffer = NULL, reminder);
		buffer[byte_read] = '\0';
		reminder = join(reminder, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;
	int			i;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, reminder, 0) < 0)
		return (free(reminder), reminder = NULL, NULL);
	reminder = read_file(reminder);
	if (!reminder || !*reminder)
		return (free(reminder), reminder = NULL, NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (reminder[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (free (reminder), reminder = NULL, NULL);
	line = ft_strncpy(line, reminder, i);
	if (!is_valid(line))
		return (free(reminder), line);
	return (tmp = ft_strdup(reminder + i),
		free(reminder), reminder = ft_strdup(tmp), free(tmp), line);
}
