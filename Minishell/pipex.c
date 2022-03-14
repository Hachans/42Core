/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:32:14 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/14 20:55:43 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include <stdio.h>

void	free_memory(t_command *cmd)
{
	int	i;

	i = -1;
	while (cmd->cmd_args[++i])
		free(cmd->cmd_args[i]);
	free(cmd->cmd_args);
	i = -1;
	while (cmd->cmd_path[++i])
		free(cmd->cmd_path[i]);
	free(cmd->cmd_path);
}

void	handle_child(t_command *cmd, char **argv, char **envp, int *ffd, int arg)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	if (pipe(fd) == -1)
	{
		write(2, "Error: Pipe could not be opened.\n", 33);
		exit(0);
	}
	get_cmd_paths(cmd, argv, envp, arg);
	i = check_access(cmd);
	pid = fork();
	if (pid < 0)
	{
		free_memory(cmd);
		exit(127);
	}
	else if (!pid)
	{
		close(fd[0]);
		close(ffd[1]);
		dup2(ffd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(ffd[0]);
		close(fd[1]);
		execve(cmd->cmd_path[i], cmd->cmd_args, envp);
	}
	else
	{
		close(fd[1]);
		close(ffd[0]);
		waitpid(pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		dup2(ffd[1], STDOUT_FILENO);
		close(fd[0]);
		close(ffd[1]);
	}
}

// Does not work with 2+ pipes yet
int	pipex(int argc, char **argv, char **envp)
{
	t_command	cmd;
	int			ffd[2];
	int			i;
	
	i = 1;
	if (check_files(argc, argv, ffd) == 0)
		exit(0);
	while (++i < argc - 1)
		handle_child(&cmd, argv, envp, ffd, i);
	free_memory(&cmd);
	return (0);
}
