/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:13:05 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/20 05:16:09 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *s1)
{
	int			i;
	char		*dest;

	i = -1;
	dest = NULL;
	if ((dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		while (s1[++i])
			dest[i] = s1[i];
		dest[i] = '\0';
	}
	return (dest);
}
