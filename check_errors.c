/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:22:59 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/11 00:35:12 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_infile(int argc, char **argv)
{
	if (argc != 5)
		print_errors(0);
	if (access(argv[1], F_OK) != 0)
		print_errors(1);
	else if (access(argv[1], R_OK) != 0)
		print_errors(2);
}

char	**check_cmd_path(char **envp)
{
	int		i;
	char	*p;
	char	**paths;

	i = 0;
	p = NULL;
	if (!*envp)
		print_errors(3);
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
		print_errors(4);
	paths = ft_split(p, ':');
	free(p);
	return (paths);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*check_cmd1(char **paths, char *cmd, char *cmd_path0, char *cmd_path)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		cmd_path0 = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(paths[i], cmd_path0);
		free(cmd_path0);
		if ((access(cmd_path, F_OK) == 0))
		{
			ft_free(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free(paths);
	print_errors(5);
	return (NULL);
}

char	*check_cmd2(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path0;
	char	*cmd_path;

	if ((access(cmd, F_OK) == 0) && access(cmd, X_OK) == 0)
		return (cmd);
	paths = check_cmd_path(envp);
	cmd_path0 = NULL;
	cmd_path = NULL;
	cmd_path = check_cmd1(paths, cmd, cmd_path0, cmd_path);
	return (cmd_path);
}
