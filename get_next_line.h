/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:44:04 by naperisw          #+#    #+#             */
/*   Updated: 2025/04/16 10:44:07 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*ft_strjoin(char *static_buffer, char *read_buffer);
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, const void *source, size_t n);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif