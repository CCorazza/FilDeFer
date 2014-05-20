/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:37:31 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:18:24 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	count;

	count = 0;
	while ((count < len) && (b != NULL))
	{
		((unsigned char*)b)[count] = c;
		count++;
	}
	return (b);
}
