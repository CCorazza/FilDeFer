/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:33:37 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:12:06 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		++i;
	}
	if (!s2[i] && i < n)
		while (i < n)
		{
			s1[i] = '\0';
			++i;
		}
	return (s1);
}
