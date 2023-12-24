/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:40:09 by bguillau          #+#    #+#             */
/*   Updated: 2022/11/18 18:22:09 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	if (!n || !s)
		return (s);
	tmp = (char *)s;
	while (--n)
		tmp[n] = c;
	tmp[n] = c;
	return (s);
}