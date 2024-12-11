/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:20:33 by djoung            #+#    #+#             */
/*   Updated: 2024/12/11 22:59:24 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*real_path;
	int		p;

	p = 0;
	while (ft_strnstr(envp[p], "PATH=", 5) == 0)
		p++;
	paths = ft_split(envp[p] + 5, ':');
	p = 0;
	while (paths[p])
	{
		path = ft_strjoin(paths[p], "/");
		real_path = ft_strjoin(path, cmd);
		free(path);
		if (access(real_path, F_OK) == 0)
			return (real_path);
		free(real_path);
		p++;
	}
	p = -1;
	while (paths[++p])
		free(paths[p]);
	free(paths);
	return (0);
}

void	error_output(int errnum, char *e_cmd)
{
	if (errnum != 0)
	{
		ft_putstr_fd("zsh: ", 2);
		ft_putstr_fd(strerror(errnum), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(e_cmd, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	execute_error(char **cmd, int errnum)
{
	int	i;

	i = 0;
	if (errnum != 0)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
	}
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = check_path(cmd[0], envp);
	if (cmd[1][0] == '\'')

	if (!path || execve(path, cmd, envp) == -1)
		execute_error(cmd, errno);
}
