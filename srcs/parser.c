/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:12:16 by dicosta-          #+#    #+#             */
/*   Updated: 2025/08/27 18:44:38 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int parsing(int argc, char **args)
{
	int	i;

	i = 0;
	if (argc != 5 || argc != 6)
		return (FALSE);
	while (args[i])
	{
		if (d_atoi(args[i]) <= 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}