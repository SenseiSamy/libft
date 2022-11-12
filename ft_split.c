/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaji <snaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:53:28 by snaji             #+#    #+#             */
/*   Updated: 2022/11/11 14:34:57 by snaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(char const	*s, char c)
{
	int	count;
	int	i;

	i = 1;
	count = 0;
	if (s[0] && s[0] != c)
		++count;
	while (s[i - 1] && s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			++count;
		++i;
	}
	return (count);
}

static char	*malloc_and_cpy(char const *s, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (s[len] && s[len] != c)
		++len;
	word = (char *)malloc((len + 1) * sizeof (*word));
	if (!word)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
	{
		word[len] = s[len];
		++len;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	result = (char **)malloc((get_size(s, c) + 1) * sizeof (*result));
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	if (s[0] && s[0] != c)
		result[j++] = malloc_and_cpy(s, c);
	while (s[i - 1] && s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			result[j++] = malloc_and_cpy(&s[i], c);
		++i;
	}
	result[j] = NULL;
	return (result);
}
