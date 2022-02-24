/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:32:14 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/24 16:54:04 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	handle_child(t_command *cmd, char **envp, char **argv, int *fd)
{
	int	i;

	get_cmd_paths(cmd, argv, envp, 2);
	i = check_access(cmd);
	close(fd[2]);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[3], STDOUT_FILENO);
	close(fd[3]);
	close(fd[0]);
	execve(cmd->cmd_path[i], cmd->cmd_args, envp);
}

void	handle_parent(t_command *cmd, char **argv, char **envp, int *fd)
{
	int	i;

	get_cmd_paths(cmd, argv, envp, 3);
	i = check_access(cmd);
	close(fd[3]);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[2], STDIN_FILENO);
	close(fd[2]);
	close(fd[1]);
	execve(cmd->cmd_path[i], cmd->cmd_args, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_command	cmd;
	int			fd[4];
	int			pid1;

	if (pipe(fd + 2) == -1)
	{
		write(2, "Error: Pipe could not be opened.\n", 33);
		return (0);
	}
	if (check_files(argc, argv, fd) == 0)
		exit(0);
	pid1 = fork();
	if (pid1 < 0)
		return (0);
	if (pid1 == 0)
		handle_child(&cmd, envp, argv, fd);
	else
	{
		waitpid(pid1, NULL, 0);
		handle_parent(&cmd, argv, envp, fd);
	}
	free_memory(&cmd);
	return (0);
}
