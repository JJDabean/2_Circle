/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:38:12 by djoung            #+#    #+#             */
/*   Updated: 2024/12/11 19:29:09 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd, int i)
{
	int	file_in;
	int	file_out;

	if (i == 0)
	{
		file_in = open(argv[1], O_RDONLY);
		if (file_in == -1)
			error_output(errno, argv[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(file_in, STDIN_FILENO);
		close(fd[0]);
		execute(argv[2], envp);
	}
	else
	{
		file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file_out == -1)
			error_output(errno, argv[4]);
		dup2(fd[0], STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO);
		close(fd[1]);
		execute(argv[3], envp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid[2];
	int		i;

	i = 0;
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_putstr_fd("Pipe error", 2);
		while (i < 2)
		{
			pid[i] = fork();
			if (pid[i] == -1)
				ft_putstr_fd("Fork error", 2);
			else if (pid[i] == 0)
				child_process(argv, envp, fd, i);
			i++;
		}
		close(fd[1]);
		close(fd[0]);                                      
		waitpid(pid[1], NULL, 0);
		waitpid(pid[0], NULL, 0);
	}
	else
		ft_putstr_fd("Arguments error", 2);
	return (0);
}
