/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:13 by arodgers          #+#    #+#             */
/*   Updated: 2023/12/07 13:16:19 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(const char *command, char *env[])
{
	int		i;
	char	*fullpath;

	i = 0;
	while (env[i] != NULL)
	{
		fullpath = (char *)malloc(ft_strlen(env[i]) + ft_strlen(command) + 2);
		if (NULL == fullpath)
			handle_error(2);
		ft_strcpy(fullpath, env[i]);
		ft_strcat(fullpath, "/");
		ft_strcat(fullpath, command);
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		else
			free (fullpath);
		i++;
	}
	if (env[i] == NULL)
		handle_error(5);
	return (NULL);
}

void	duplicate_close(int in_out_fd, int fd_arr[], int sign)
{
	if (sign == 0)
	{
		dup2(in_out_fd, STDIN_FILENO);
		close_file(in_out_fd);
		dup2(fd_arr[1], STDOUT_FILENO);
		close_file(fd_arr[1]);
	}
	else
	{
		dup2(fd_arr[0], STDIN_FILENO);
		close_file(fd_arr[0]);
		dup2(in_out_fd, STDOUT_FILENO);
		close_file(in_out_fd);
	}
}

void	create_pipe(int fd1[], char **av, t_path *path)
{
	pipe(fd1);
	path->pid = fork();
	if (path->pid == 0)
	{
		close_file(fd1[0]);
		path->in_file_fd = open_file(av[1], 0);
		duplicate_close(path->in_file_fd, fd1, 0);
		if ((execve(path->command_1path, path->args_cmd1, NULL)) == -1)
			handle_error(7);
	}
	else
	{
		close_file(fd1[1]);
		path->pid = fork ();
		if (path->pid == 0)
		{
			path->out_file_fd = open_file(av[4], 1);
			duplicate_close(path->out_file_fd, fd1, 1);
			if ((execve(path->command_2path, path->args_cmd2, NULL)) == -1)
				handle_error(7);
		}
		else
			close_file(fd1[0]);
	}
}

char	**get_env(char *envp[])
{
	char	**env;
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if ((ft_strncmp(envp[i], "PATH=", 5)) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	env = ft_split(path, ':');
	return (env);
}

int	main(int ac, char **av, char **envp)
{
	int		fd1[2];
	int		status;
	t_path	path;

	if (ac != 5)
		handle_error (1);
	if ((check_args(av[2], av[3])) == 1)
		handle_error (1);
	if ((check_file(av[1])) == 1)
		handle_error(6);
	path.env = get_env(envp);
	path.args_cmd1 = ft_split(av[2], ' ');
	path.args_cmd2 = ft_split(av[3], ' ');
	path.command_1path = get_path(path.args_cmd1[0], path.env);
	path.command_2path = get_path(path.args_cmd2[0], path.env);
	create_pipe(fd1, av, &path);
	free_total(&path);
	wait(&status);
	wait(&status);
	return (0);
}
