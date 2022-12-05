/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:22:59 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/05 14:43:15 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files_errors(int argc, char **argv)
{
	if (argc != 5)
		print_errors(1);
	if (access(argv[1], F_OK) != 0)
		print_errors(2);
	else if (access(argv[1], R_OK) != 0)
		print_errors(3);
	if (access(argv[4], F_OK) != 0)
		open(argv[4], O_CREAT, 0222);
	else if (access(argv[4], W_OK) != 0)
		print_errors(4);
}

char	**check_cmd_path(char **argv, char **envp)
{
	int		i;
	char	*p;
	char	**paths;

	i = 0;
	p = NULL;
	if (!*envp)
		print_errors(5);
	while (envp[i])
	{
		if (ft_strstr(envp[i], "PATH="))
		{
			p = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			break ;
		}
		i++;
	}
	if (!p)
		print_errors(6);
	return (ft_split(p, ':'));
}

void	check_cmd_path2(char **argv, char **envp)
{
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	int		i;
	int		count;

	paths = check_cmd_path(argv, envp);
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	i = 0;
	count = 0;
	while (paths[i])
	{
		if ((access(ft_strjoin(paths[i], ft_strjoin("/", cmd1[0])), F_OK) == 0) \
		&& (access(ft_strjoin(paths[i], ft_strjoin("/", cmd1[0])), X_OK) == 0))
			count++;
		if ((access(ft_strjoin(paths[i], ft_strjoin("/", cmd2[0])), F_OK) == 0) \
		&& (access(ft_strjoin(paths[i], ft_strjoin("/", cmd2[0])), X_OK) == 0))
			count++;
		i++;
	}
	if (count != 2)
		print_errors(7);
}
