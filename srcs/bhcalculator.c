/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhcalculator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:53:00 by uwywijas          #+#    #+#             */
/*   Updated: 2023/11/21 17:11:32 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bhcalculator.h"

void	ft_finput(char *str, int *variable)
{
	printf("%s", str);
	scanf("%d", variable);
}

int	main(void)
{
	int	current_lvl;
	int	current_xp;
	int	project_xp;
	int	is_bonus;
	int	result;

	current_xp = 0;
	project_xp = 0;
	is_bonus = 0;
	result = 0;
	printf(HEADER);
	ft_finput("Current level [0/30] : ", &current_lvl);
	ft_finput("Project xp [0/63000] : ", &project_xp);
	ft_finput("Bonus [0/1] : ", &is_bonus);
	printf("You will aproximatively earn : %d days of blackhole.\n", result);
	return (0);
}
