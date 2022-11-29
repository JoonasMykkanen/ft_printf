/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:39 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:40 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned long long num)
{
	int		i;
	char	c;
	int		temp;
	char	buf[17];

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		temp = num % 16;
		if (temp < 10)
		{
			c = temp + 48;
			buf[i++] = c;
		}
		else
		{
			c = temp + 87;
			buf[i++] = c;
		}
		num = num / 16;
	}
	return (i);
}

int	convert_p(va_list *args, int count)
{
	void	*ptr;
	int		len;

	ptr = va_arg(*args, void *);
	ft_putstr_fd("0x", 1);
	len = ft_hexlen((unsigned long long)ptr);
	ft_puthex_lower_fd((unsigned long long)ptr, 1);
	count = count + len + 2;
	return (count);
}