/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:21:10 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/19 19:39:39 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	int			i;
	int			j;

	i = ft_strlen(s);
	j = -1;
	str = (char *)malloc(sizeof(char *) * (i + 1));
	while (++j < i)
		str[j] = (*f) (s[j]);
	str[j] = 0;
	return (str);
}
