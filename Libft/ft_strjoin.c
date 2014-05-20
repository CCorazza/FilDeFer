/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 17:18:48 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/19 19:39:03 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*res;
	char		*total;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	total = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = 0;
	return (total);
}
