/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 17:15:04 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/19 19:39:20 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size + 1);
	return (s);
}
