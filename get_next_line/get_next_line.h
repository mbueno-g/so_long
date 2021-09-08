/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 17:31:04 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/02 16:07:17 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif


char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void	*ft_memcpy_gnl(void *dst, const void *src, size_t n);
void	ft_strdel_gnl(char **ptr);

#endif
