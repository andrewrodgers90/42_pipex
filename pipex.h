/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:38:38 by arodgers          #+#    #+#             */
/*   Updated: 2024/02/19 16:26:17 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_path
{
	int		in_file_fd;
	int		out_file_fd;
	int		pid;
	char	*command_1path;
	char	*command_2path;
	char	**args_cmd1;
	char	**args_cmd2;
	char	**env;
}	t_path;

char	**ft_allocatewords(char **arr, char const *s, char sep);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int		check_args(char *cmd1, char *cmd2);

int		check_file(char *filename);

void	close_file(int fd);

void	create_pipe(int fd1[], char **av, t_path *path);

void	duplicate_close(int in_out_fd, int fd_arr[], int sign);

char	**ft_freeall(char **arr, int i);

void	free_total(t_path *path);

char	*get_path(const char *command, char *env[]);

void	handle_error(int err_num);

int		open_file(const char *fielname, int flag);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	**ft_split(char const *s, char c);

char	*ft_strcat(char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_wordcount(char const *s, char sep);

#endif
