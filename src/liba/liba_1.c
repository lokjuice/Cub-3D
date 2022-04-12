/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtheobal <vtheobal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:57:01 by wroyal            #+#    #+#             */
/*   Updated: 2022/03/19 15:59:11 by vtheobal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub.h"

char	*ft_bzero(char *s, size_t maxlen)
{
	int		i;
	char	*ptr;

	ptr = s;
	i = 0;
	while (maxlen > 0)
	{
		ptr[i] = ' ';
		maxlen--;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	char	*mas;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s1[l] != '\0')
		l++;
	mas = malloc(sizeof(char) * l + 1);
	if (mas == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		mas[i] = s1[i];
		i++;
	}
	mas[i] = '\0';
	return (mas);
}

char	ft_first(const	char *str)
{
	while (*str != '\0')
	{
		if (*str == '\t' || *str == '\n' || *str == '\v')
			str++;
		if (*str == '\r' || *str == ' ' || *str == '\f')
			str++;
		else
			str++;
	}
	return (*str);
}

int	ft_shield(long i, long a)
{
	if (i % 2 == 1)
		a *= -1;
	if (a < -2147483648)
		return (-1);
	if (a > 2147483647)
		return (0);
	return (a);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	a;

	i = 0;
	a = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		a = a + (*str - '0');
		a = a * 10;
		str++;
	}
	a = a / 10;
	return (ft_shield(i, a));
}
