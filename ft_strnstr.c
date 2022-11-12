/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:54:04 by snaji             #+#    #+#             */
/*   Updated: 2022/11/11 13:36:59 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	size = ft_strlen(little) - 1;
	size_t			i;
	size_t			j;

	i = 0;
	if (len == 0 || (little && little[i] == '\0'))
	{
		if (little && little[i] == '\0')
			return ((char *)big);
		return (NULL);
	}
	while (big[i + size] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i + j] && i + j < len)
			++j;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		++i;
	}
	return (NULL);
}
