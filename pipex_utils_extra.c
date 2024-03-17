/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:25:10 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:35 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_file(char *filename)
{
	if (access(filename, F_OK) == 0)
		return (0);
	else
		return (1);
}

int	check_args(char *cmd1, char *cmd2)
{
	if (!cmd1[0] || !cmd2[0])
		return (1);
	else
		return (0);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	while (s2[i] != '\0')
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
