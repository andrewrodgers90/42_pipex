/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:35:07 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:27 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_total(t_path *path)
{
	int	i;

	i = 0;
	while (path->args_cmd1[i] != NULL)
		free(path->args_cmd1[i++]);
	free(path->args_cmd1);
	i = 0;
	while (path->args_cmd2[i] != NULL)
		free(path->args_cmd2[i++]);
	free(path->args_cmd2);
	i = 0;
	while (path->env[i] != NULL)
		free(path->env[i++]);
	free(path->env);
	free(path->command_1path);
	free(path->command_2path);
}

void	handle_error(int err_num)
{
	if (err_num == 1)
		perror("Incorrect input: File_1 ""cmd_1" " cmd_2"" File_2.\n");
	if (err_num == 2)
		perror("Path memmory allocation failed.\n");
	if (err_num == 3)
		perror("Error opening file.\n");
	if (err_num == 4)
		perror("Error closing file.\n");
	if (err_num == 5)
		perror("Command path not found.\n");
	if (err_num == 6)
		perror("File_1 does not exist.\n");
	if (err_num == 7)
		perror("Command failed to execute.\n");
	exit(EXIT_FAILURE);
}

int	open_file(const char *filename, int flag)
{
	int	ret;

	ret = 0;
	if (flag == 0)
		ret = open(filename, O_RDONLY, 0444);
	else if (flag == 1)
		ret = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (ret == -1)
		handle_error(3);
	return (ret);
}

void	close_file(int fd)
{
	if (close(fd) == -1)
		handle_error(4);
}
