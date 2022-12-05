/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:09:18 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/05 14:29:14 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_errors(int num)
{
	if (num == 1)
		ft_putstr("Error\nThe number of arguments is invalid !!!\n");
	else if (num == 2)
		ft_putstr("Error\nThe infile doesn't exist !!!\n");
	else if (num == 3)
		ft_putstr("Error\nYou don't have permession to read from the infile");
	else if (num == 4)
		ft_putstr("Error\nYou don't have permession to read from the outfile");
	else if (num == 5)
		ft_putstr("Error\nThe array of environment variables doesn't exist");
	else if (num == 6)
		ft_putstr("Error\nThe executable programs' PATH doesn't exist");
	else if (num == 7)
		ft_putstr("Error\nA cmd's executable file doesn't exist in the PATH");
	exit(EXIT_FAILURE);
}
