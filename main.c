/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:10:25 by jbagger           #+#    #+#             */
/*   Updated: 2022/12/03 13:22:46 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int main()
{
	char c = 'X';
	char *s = "This is a string";
	int d = 123;
	unsigned int u = 1234567890;
	int result;
	int b = 217;

	printf("-------ft_printf:-------\n");
	result = ft_printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\no = '%o'\nu = '%u'\n%%\n%", c, s, d, d, d, d, &s, d, u);
	printf("printed bytes = %d\n", result);
	ft_printf("b = %b\n", b);

	printf("\n--------printf:--------\n");
	result = printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\no = '%o'\nu = '%u'\n%%\n%", c, s, d, d, d, d, &s, d, u);
	printf("printed bytes = %d\n", result);
	ft_printf("b = can't print binary numbers...\n", b);

	return (0);
}