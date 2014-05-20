/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:11:44 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:11:57 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*d;
	const char	*s;

	if (n)
	{
		d = (char*)s1;
		s = (const char*)s2;
		while (n--)
		{
			*(d++) = *(s++);
			if (*(s - 1) == c)
				return (d);
		}
	}
	return (NULL);
}
