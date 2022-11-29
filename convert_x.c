/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:21:29 by jmykkane          #+#    #+#             */
/*   Updated: 2022/11/29 19:21:30 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_x(va_list *args, int count)
{
	char	*str;
	int		len;
	int		num;

	num = 0;
	str = ft_itoa(num);
	len = ft_strlen(str);
	num = va_arg(*args, int);
	ft_puthex_lower_fd(num, 1);
	free(str);
	return (count + len);
}

int	convert_xx(va_list *args, int count)
{
	char	*str;
	int		len;
	int		num;

	num = 0;
	str = ft_itoa(num);
	len = ft_strlen(str);
	num = va_arg(*args, int);
	ft_puthex_upper_fd(num, 1);
	free(str);
	return (count + len);
}
