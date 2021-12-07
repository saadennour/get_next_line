/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:11:51 by sfarhan           #+#    #+#             */
/*   Updated: 2021/12/07 04:23:05 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_get_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static char	*ft_before(char *s)
{
	int	i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

static char	*ft_after(char *s)
{
	int		i;
	char	*a;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			a = ft_substr(s, i + 1, ft_strlen(s) - i + 1);
			free(s);
			return (a);
		}
		i++;
	}
	free(s);
	return (NULL);
}

char	*ft_readline(char *s, int fd)
{
	char	*line;
	int		i;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
	{
		free (line);
		return (NULL);
	}
	i = 1;
	while (ft_get_check(s) == 1 && i != 0)
	{
		i = read (fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free (line);
			return (NULL);
		}
		line[i] = '\0';
		s = ft_strjoin(s, line);
	}
	free (line);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*r;
	static char	*s[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	s[fd] = ft_readline(s[fd], fd);
	if (!s[fd])
		return (NULL);
	r = ft_before(s[fd]);
	s[fd] = ft_after(s[fd]);
	return (r);
}

// #include <fcntl.h>
// int main()
// {
//     int fd;
//     fd = open ("text.txt", O_RDWR | O_CREAT);
//     char *s;
//     while ((s = get_next_line(fd)))
//     {
//         printf ("%s", s);
// 		free (s);
//     }
//     // system("Leaks a.out");
// }
// #include <stdio.h>
// int main()
// {
//     int fd;
// 	int fd1;
	
//     fd = open ("text.txt", O_RDWR | O_CREAT);
// 	fd1 = open ("test.txt", O_RDWR | O_CREAT);
//     char *s = NULL;
//     s = get_next_line(fd);
//     printf ("%s", s);
// 	free (s);
// 	s = get_next_line(fd1);
//     printf ("%s", s);
// 	free (s);
// 	s = get_next_line(fd);
//     printf ("%s", s);
// 	free (s);
// 	s = get_next_line(fd1);
//     printf ("%s", s);
// 	free (s);
// 	s = get_next_line(fd1);
//     printf ("%s", s);
// 	free (s);
//     // system("Leaks a.out");
// }