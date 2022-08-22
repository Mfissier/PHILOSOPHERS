/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:47:21 by mafissie          #+#    #+#             */
/*   Updated: 2022/08/19 14:01:29 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/philo.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = s;
	i = 0;
	if (n == 0)
		return (s);
	while (i < n)
		tmp[i++] = c;
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	tmp = ft_memset(tmp, '\0', n);
	s = tmp;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb >= 65535 && size >= 65535)
		return (NULL);
	p = (void *)malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}


