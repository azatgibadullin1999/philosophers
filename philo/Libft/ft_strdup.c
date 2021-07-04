/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 23:43:09 by larlena           #+#    #+#             */
/*   Updated: 2021/06/26 23:31:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	end;

	end = ft_strlen(s1) + 1;
	if ((dst = ft_calloc(sizeof(char), end)) == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, end + 1);
	return (dst);
}
