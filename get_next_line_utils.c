/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfarhan <sfarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:37:27 by sfarhan           #+#    #+#             */
/*   Updated: 2021/12/07 02:55:45 by sfarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*c;
	int		j;

	j = 0;
	if (!(s))
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	c = (char *)malloc(len * sizeof(char) + 1);
	if (!(c))
	{
		free (c);
		return (NULL);
	}
	while (s[start] && len > 0)
	{
		c[j++] = s[start];
		start++;
		len--;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	ret = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(ret))
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		ret[i] = s2[j++];
		i++;
	}
	ret[i] = '\0';
	free (s1);
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	p = NULL;
	while (src[i])
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (!(p))
		return (NULL);
	while (i > 0)
	{
		p[j] = src[j];
		j++;
		i--;
	}
	p[j] = '\0';
	free (p);
	return (p);
}
