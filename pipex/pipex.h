/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:32:16 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/23 19:17:16 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

// Utils
size_t	ft_strlen(const char *s);
int		word_count(const char *s, char c);
char	*dup_word(char const *s, int start, int end);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Utils2
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);

// Check and get (checknget)
int		check_access(t_command *cmd);
int		check_files(int argc, char **argv, int *fd);
void	get_cmd_paths(t_command *cmd, char **argv, char **envp, int check);

// Pipex
void	free_memory(t_command *cmd);
#endif
