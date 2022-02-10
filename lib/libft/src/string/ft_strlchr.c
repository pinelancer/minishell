/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaeng <gpaeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:03:56 by gpaeng            #+#    #+#             */
/*   Updated: 2022/02/10 19:07:29 by gpaeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"

int 	ft_strlchr(char *str, int c) 
{
	int idx;

	idx = 0;
	if (!str)
		return(0);
	while (str[idx] && str[idx] != (char)c)
	{
		idx++;
	}
	return (idx);
}