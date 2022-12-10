/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:47:46 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/10 01:47:50 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(t_pars *var, char **envp, char *argv1, char *argv2)
{
	if (!argv2 && argv1)
	{
		dup2(var->fd[1], STDOUT_FILENO);
		close(var->fd[0]);
		close(var->fd[1]);
		var->infile_fd = open(argv1, O_RDONLY);
		dup2(var->infile_fd, STDIN_FILENO);
		close(var->infile_fd);
		execve(var->cmd1_path, var->cmd1, envp);
	}
	else
	{
		dup2(var->fd[0], STDIN_FILENO);
		close(var->fd[0]);
		close(var->fd[1]);
		var->outfile_fd = open(argv2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(var->outfile_fd, STDOUT_FILENO);
		close(var->outfile_fd);
		execve(var->cmd2_path, var->cmd2, envp);
	}
}
