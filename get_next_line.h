/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongha2788 <jongha2788@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:55:23 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/07 14:09:54 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		is_newline(char *buf);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *src, int start, int num);

#endif
