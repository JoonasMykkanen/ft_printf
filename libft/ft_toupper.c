/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:52:40 by jmykkane          #+#    #+#             */
/*   Updated: 2022/10/26 15:52:41 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	c_out;

	c_out = (unsigned char)c;
	if (c_out >= 97 && c_out < 123)
	{
		c_out -= 32;
	}
	return (c_out);
}
