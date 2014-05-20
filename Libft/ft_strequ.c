/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 19:15:52 by ccorazza          #+#    #+#             */
/*   Updated: 2014/04/19 20:36:11 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if ((ft_strncmp(s1, s2, ft_strlen(s1) + 1)) == 0)
		return (1);
	else
		return (0);
}
