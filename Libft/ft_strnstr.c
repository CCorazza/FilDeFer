/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:40:58 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:16:50 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n > 0)
	{
		while ((s1[i] == s2[i]) && (i < (int)n))
		{
			if ((s2[i + 1] == '\0') || (n - i == 0))
				return ((char *)s1);
			i++;
		}
		i = 0;
		s1++;
		n--;
	}
	return (0);
}
