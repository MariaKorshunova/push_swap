/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:44:48 by jmabel            #+#    #+#             */
/*   Updated: 2022/01/14 14:06:02 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_make_array(char **arr, char const *s, char c)
{
	const char	*start;
	size_t		i;
	size_t		letter;

	i = 0;
	while (*s)
	{
		letter = 0;
		while (*s == c && *s)
			s++;
		start = (char *)s;
		while (*s != c && *s)
		{
			letter++;
			s++;
		}
		if (*(s - 1) != c)
		{
			arr[i++] = ft_substr(start, 0, letter);
			if (arr == NULL)
				ft_free_array(&arr, i);
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char		**arr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(*arr) * (ft_str_in_array(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	arr = ft_make_array(arr, s, c);
	return (arr);
}
