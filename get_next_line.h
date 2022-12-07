/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrivino <ctrivino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:56:54 by ctrivino          #+#    #+#             */
/*   Updated: 2022/12/07 13:37:11 by ctrivino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  1
# endif

# define FT_EOF 0
# define FT_SUCCESS 1
# define FT_FAIL -1

char	*get_next_line(int fd);
size_t	ft_strlen(const char	*s);
void	ft_bzero(void	*s, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif