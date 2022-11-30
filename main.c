/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbagger <jbagger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:10:25 by jbagger           #+#    #+#             */
/*   Updated: 2022/11/30 10:13:26 by jbagger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main()
{
	char c = 'X';
	char *s = "This is a string";
	int d = -123;
	unsigned int u = 1234567890;
	int result;

	printf("-------ft_printf:-------\n");
	result = ft_printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n", c, s, d, d, d, d, &d, u);
	printf("result = %d\n", result);

	printf("\n--------printf:--------\n");
	result = printf("c = '%c'\ns = '%s'\nd = '%d'\ni = '%i'\nx = '%x'\nX = '%X'\np = '%p'\nu = '%u'\n%%\n", c, s, d, d, d, d, &d, u);
	printf("result = %d\n", result);

	return (0);
}