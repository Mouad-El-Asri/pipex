/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:50:12 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/10 01:35:46 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pars	var;

	if (pipe(var.fd) < 0)
		print_errors(6);
	check_infile(argc, argv);
	var.paths = check_cmd_path(argv, envp);
	var.cmd1 = ft_split(argv[2], ' ');
	var.cmd2 = ft_split(argv[3], ' ');
	var.cmd1_path = check_cmd2(argv, envp, var.cmd1[0]);
	var.cmd2_path = check_cmd2(argv, envp, var.cmd2[0]);
	var.pid1 = fork();
	if (var.pid1 < 0)
		print_errors(7);
	if (var.pid1 == 0)
		execute_cmd(&var, envp, argv[1], NULL);
	var.pid2 = fork();
	if (var.pid2 < 0)
		print_errors(7);
	if (var.pid2 == 0)
		execute_cmd(&var, envp, NULL, argv[4]);
	close(var.fd[0]);
	close(var.fd[1]);
	waitpid(var.pid1, NULL, 0);
	waitpid(var.pid2, NULL, 0);
	return (0);
}
