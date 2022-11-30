/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:31:41 by jbagger           #+#    #+#             */
/*   Updated: 2022/11/26 08:46:16 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(char *s)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
			i += ft_putchar_len(s[i]);
		return (i);
	}
	return (0);
}

unsigned int	convert(long long int num, int base, char c, unsigned int len)
{
	static char	*digits;
	static char	buffer[50];
	char		*result;

	if (num < 0)
	{
		len += ft_putchar_len('-');
		num *= -1;
	}
	if (c == 'p')
		len += ft_putstr_len("0x");
	digits = "0123456789abcdef";
	if (c == 'X')
		digits = "0123456789ABCDEF";
	result = &buffer[49];
	*result = '\0';
	while (num != 0)
	{
		*--result = digits[num % base];
		num /= base;
	}
	len += ft_putstr_len(result);
	return (len);
}

int	ft_check(char c, int res, va_list list)
{
	if (c == 'c')
		res += ft_putchar_len(va_arg(list, int));
	else if (c == 's')
		res += ft_putstr_len(va_arg(list, char *));
	else if (c == 'p')
		res = convert(va_arg(list, unsigned long long int), 16, 'p', res);
	else if (c == 'd' || c == 'i')
		res = convert(va_arg(list, int), 10, 'd', res);			
	else if (c == 'u')
		res = convert(va_arg(list, unsigned int), 10, 'u', res);
	else if (c == 'x')
		res = convert(va_arg(list, unsigned int), 16, 'x', res);
	else if (c == 'X')
		res = convert(va_arg(list, unsigned int), 16, 'X', res);
	else if (c == '%')
		res += ft_putchar_len('%');
	return (res);
}

int ft_printf(const char *str, ...)
{
	unsigned int	i;
	unsigned int	res;
	va_list 		list;

	va_start(list, str);
	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '%')
		{
			if (str[i] == '\0')
			{
				va_end(list);
				return (res);
			}
			res += ft_putchar_len(str[i++]);
		}
		i++;
		res = ft_check(str[i], res, list);
		i++;
	}
	va_end(list);
	return (res);
}

// int main()
// {
// 	char c = 'X';
// 	char *s = "This is a string";
// 	int d = -123;
// 	unsigned int u = 1234567890;
// 	int result;

// 	ft_printf("-------ft_printf:-------\n");
// 	result = ft_printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n", c, s, d, d, d, d, &d, u);
// 	printf("result = %d\n", result);

// 	printf("\n--------printf:--------\n");
// 	result = printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n", c, s, d, d, d, d, &d, u);
// 	printf("result = %d\n", result);

// 	return (0);
// }