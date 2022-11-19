/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:47 by snaji             #+#    #+#             */
/*   Updated: 2022/11/19 16:28:50 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;

	y = ft_strlen(src);
	if (dstsize == 0)
		return (y);
	i = ft_strlen(dst);
	if (i > dstsize)
		return (dstsize + y);
	y = 0;
	while (src[y] != 0 && (i + y < dstsize - 1))
	{
		dst[i + y] = src[y];
		y++;
	}
	dst[i + y] = '\0';
	return (i + ft_strlen(src));
}
