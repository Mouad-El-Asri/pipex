/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:39:03 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/10 02:46:45 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_pars
{
	char	**paths;
	int		fd[2];
	int		outfile_fd;
	int		infile_fd;
	int		pid1;
	int		pid2;
	char	**cmd1;
	char	**cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_pars;

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	check_infile(int argc, char **argv);
char	**check_cmd_path(char **envp);
void	ft_free(char **strs);
char	*check_cmd1(char **paths, char *cmd, char *cmd_path0, char *cmd_path);
char	*check_cmd2(char **envp, char *cmd);
void	execute_cmd(t_pars *var, char **envp, char *argv1, char *argv2);
void	print_errors(int num);

#endif