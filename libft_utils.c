/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:12:07 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/07 13:17:06 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_freeall(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		if (i == 0)
		{
			break ;
		}
		i--;
	}
	free(arr);
	return (NULL);
}

char	**ft_allocatewords(char **arr, char const *s, char sep)
{
	char const	*temp;
	size_t		i;

	temp = s;
	i = 0;
	while (*temp)
	{
		while (*s == sep)
			s++;
		temp = s;
		while (*temp && *temp != sep)
			temp++;
		if (*temp == sep || *temp == '\0')
		{
			if (temp > s)
			{
				arr[i] = ft_substr(s, 0, temp - s);
				if (arr[i] == NULL)
					return (ft_freeall(arr, i));
				i++;
			}
			s = temp;
		}
	}
	return (arr);
}

int	ft_wordcount(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
		{
			s++;
		}
		if (*s)
		{
			word_count++;
		}
		while (*s && *s != sep)
		{
			s++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	size = ft_wordcount(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
	{
		return (0);
	}
	new[size] = NULL;
	return (ft_allocatewords(new, s, c));
}
