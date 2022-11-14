/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:31:41 by jbagger           #+#    #+#             */
/*   Updated: 2022/11/14 17:29:47 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
	malloc, free, write, va_start, va_arg, va_copy, va_end

	• %c Prints a single character.
	• %s Prints a string (as defined by the common C convention).
	• %p The void * pointer argument has to be printed in hexadecimal format.
	• %d Prints a decimal (base 10) number.
	• %i Prints an integer in base 10.
	• %u Prints an unsigned decimal (base 10) number.
	• %x Prints a number in hexadecimal (base 16) lowercase format.
	• %X Prints a number in hexadecimal (base 16) uppercase format.
	• %% Prints a percent sign.
*/

int ft_printf(const char *format, ...)
{
	char *s;
	unsigned int i;
	char *traverse;

	va_list arg;
	va_start(arg, format);

	traverse = format;
	while (*traverse != '\0')
	{
		while (*traverse != '%')
		{
			write(1, *traverse, 1);
			traverse++;
		}
		traverse++;
		if (*traverse == 'c')
		{
			i = va_arg(arg, int);
			write(1, &i, 1);
		}
		else if (*traverse == 's')
		{

		}
		else if (*traverse == 'p')
		{

		}
		else if (*traverse == 'd')
		{
			i = va_arg(arg, int);
			putnbr(i);
		}
		else if (*traverse == 'i')
		{

		}
		else if (*traverse == 'u')
		{

		}
		else if (*traverse == 'x')
		{

		}
		else if (*traverse == 'X')
		{

		}
		else (*traverse == '%')
		{

		}
	}
	va_end(arg);
}