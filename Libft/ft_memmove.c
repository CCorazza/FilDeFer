/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:39:51 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:12:01 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*src;

	if (n)
	{
		src = ft_memalloc(n);
		ft_memcpy(src, s2, n);
		ft_memcpy(s1, src, n);
		free(src);
	}
	return (s1);
}
