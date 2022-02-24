/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:33:52 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/23 19:23:13 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_access(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_path[i])
	{
		if (access(cmd->cmd_path[i], X_OK) == 0)
			break ;
		i++;
	}
	if (access(cmd->cmd_path[i], X_OK) == -1)
	{
		free_memory(cmd);
		write(2, "Error: command not found\n", 25);
		exit(127);
	}
	return (i);
}

int	check_files(int argc, char **argv, int *fd)
{
	if (argc != 5)
	{
		write(2, "Error: 4 arguments not passed.\n", 31);
		exit(0);
	}
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if ((fd[0] < 0) | (fd[1] < 0))
	{
		if (fd[0] < 0)
			close(fd[0]);
		if (fd[1] < 0)
			close(fd[1]);
		write(2, "Error: Check files and permision.\n", 34);
		return (0);
	}
	return (1);
}

void	join_three(t_command *cmd, int i, char *c)
{
	char	*temp;

	temp = ft_strjoin(cmd->cmd_path[i], c);
	free(cmd->cmd_path[i]);
	cmd->cmd_path[i] = temp;
	temp = ft_strjoin(cmd->cmd_path[i], cmd->cmd);
	free(cmd->cmd_path[i]);
	cmd->cmd_path[i] = temp;
}

void	get_cmd_paths(t_command *cmd, char **argv, char **envp, int check)
{
	int		i;

	i = -1;
	cmd->env_path = NULL;
	cmd->cmd = NULL;
	cmd->cmd_path = NULL;
	while (!cmd->env_path)
		cmd->env_path = ft_strnstr(*envp++, "PATH", 4);
	if (!cmd->env_path)
	{
		write(2, "Error: PATH not found.\n", 23);
		exit(0);
	}
	cmd->cmd_args = ft_split(argv[check], ' ');
	cmd->env_path = ft_strtrim(cmd->env_path, "PATH=");
	cmd->cmd = ft_split(argv[check], ' ')[0];
	cmd->cmd_path = ft_split(cmd->env_path, ':');
	while (cmd->cmd_path[++i])
		join_three(cmd, i, "/");
	free(cmd->cmd);
	free(cmd->env_path);
}
