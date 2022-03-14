/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:36:41 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/14 14:28:32 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_command
{
	char	**cmd_path;
	char	*cmd;
	char	**cmd_args;
	char	*env_path;
}				t_command;

// Check and get (checknget)
int		check_access(t_command *cmd);
int		check_files(int argc, char **argv, int *fd);
void	get_cmd_paths(t_command *cmd, char **argv, char **envp, int check);

// Pipex
int		pipex(int argc, char **argv, char **envp);
void	free_memory(t_command *cmd);
#endif