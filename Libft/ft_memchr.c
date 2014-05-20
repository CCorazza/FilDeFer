/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 04:20:18 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:14:43 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	if (str == 0)
		return (0);
	while (i++ < n && s)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (0);
}
