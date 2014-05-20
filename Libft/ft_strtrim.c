/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 18:47:08 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/27 17:23:27 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#define	IS_WD(c) ((c) != ' ' && (c) != '\t' && (c) != '\n')

static int			findstart(char const *s)
{
	int				i;

	i = 0;
	while (i < (int)ft_strlen(s))
	{
		if (IS_WD(s[i]))
			return (i);
		i += 1;
	}
	return (0);
}

static int			findend(char const *s)
{
	int				i;

	i = (int)ft_strlen(s) - 1;
	while (i > 0)
	{
		if (IS_WD(s[i]))
			return (i);
		i -= 1;
	}
	return (0);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	int				k;
	char			*trim;

	i = findstart(s);
	j = findend(s);
	k = 0;
	trim = (char *)malloc(sizeof(char) * (j - i));
	*trim = '\0';
	if (trim)
	{
		if (i == 0 && j == ft_strlen(s))
			return (ft_strdup(s));
		if (i == 0 && j == 0)
			return (trim);
		while (i <= j)
			trim[k++] = s[i++];
		trim[k] = '\0';
		return (trim);
	}
	return (NULL);
}
