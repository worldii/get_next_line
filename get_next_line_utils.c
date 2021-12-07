/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:23:00 by jongha2788        #+#    #+#             */
/*   Updated: 2021/12/07 13:44:33 by jongha2788       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		idx;
	int		s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *) malloc(sizeof(char) * (s1len + s2len + 2));
	if (new == NULL)
		return (NULL);
	idx = 0;
	while (*s1)
	{
		new[idx++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new[idx++] = *s2;
		s2++;
	}
	new[idx] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		len;
	int		sidx;
	int		tidx;

	sidx = 0;
	tidx = 0;
	len = ft_strlen(src);
	temp = (char *) malloc (sizeof(char) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (src[sidx])
	{
		temp[tidx++] = src[sidx++];
	}
	temp[tidx] = 0;
	return (temp);
}

char	*ft_strndup(const char *src, size_t num)
{
	char	*temp;
	int		len;
	int		sidx;
	int		tidx;

	sidx = 0;
	tidx = 0;
	len = ft_strlen(src);
	temp = (char *) malloc (sizeof(char) * num + 1);
	if (temp == NULL)
		return (NULL);
	while (src[sidx] && tidx < num)
	{
		temp[tidx++] = src[sidx++];
	}
	temp[tidx] = 0;
	return (temp);
}
