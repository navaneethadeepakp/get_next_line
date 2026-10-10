/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:07:42 by naperisw          #+#    #+#             */
/*   Updated: 2025/04/04 12:31:22 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char		*dst;
	const char	*src;

	dst = dest;
	src = source;
	if (!dest || !src)
		return (NULL);
	if (dst > src)
	{
		while (n--)
			dst[n] = src[n];
	}
	else
	{
		while (n--)
			*dst++ = *src++;
	}
	return (dest);
}

size_t	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str && str[length])
		length++;
	return (length);
}

char	*ft_strjoin(char *s_buffer, char *r_buffer)
{
	char	*new_buf;
	size_t	s_buf_len;
	size_t	r_buf_len;

	s_buf_len = 0;
	r_buf_len = 0;
	if (!s_buffer && !r_buffer)
		return (NULL);
	if (s_buffer)
		s_buf_len = ft_strlen(s_buffer);
	if (r_buffer)
		r_buf_len = ft_strlen(r_buffer);
	new_buf = (char *)malloc((s_buf_len + r_buf_len + 1) * sizeof(char));
	if (!new_buf)
		return (NULL);
	ft_memmove(new_buf, s_buffer, s_buf_len);
	ft_memmove(new_buf + s_buf_len, r_buffer, r_buf_len);
	new_buf[s_buf_len + r_buf_len] = '\0';
	free(s_buffer);
	return (new_buf);
}
