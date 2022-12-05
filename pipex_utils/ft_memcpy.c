/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-asr <moel-asr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:35:03 by moel-asr          #+#    #+#             */
/*   Updated: 2022/12/05 03:36:36 by moel-asr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!dest && !src)
		return (NULL);
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
