/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:39:03 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/05 03:36:51 by moel-asr         ###   ########.fr       */
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
void	print_errors(int num);
void	check_files_errors(int argc, char **argv);
char	**check_cmd_path(char **argv, char **envp);
void	check_cmd_path2(char **argv, char **envp);

#endif
