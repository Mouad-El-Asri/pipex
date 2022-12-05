/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:50:12 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/05 03:39:46 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	check_files_errors(argc, argv);
	//paths = check_cmd_path(argv, envp);
	check_cmd_path2(argv, envp);
	return (0);
}
