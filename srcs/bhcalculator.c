/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhcalculator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwywijas <uwywijas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:53:00 by uwywijas          #+#    #+#             */
/*   Updated: 2023/11/21 17:55:57 by uwywijas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bhcalculator.h"

void	ft_finput(char *str, float *variable)
{
	printf("%s", str);
	scanf("%f", variable);
}

void	ft_dinput(char *str, int *variable)
{
	printf("%s", str);
	scanf("%d", variable);
}

int	ft_getxp(float current_lvl)
{
	float	floating_lvl;
	int		base_lvl;
	int		total[] = {0, 462, 2688, 5885, 11777, 29217, 46255, 63559, 74340, 85483, 95000};
	int		xps[] = {0, 462, 2226, 3197, 5892, 17440, 17038, 17304, 10781, 11143, 9517};

	base_lvl = floor(current_lvl);
	floating_lvl = current_lvl - base_lvl;
	printf("floating = %f\n", floating_lvl);
	return (total[base_lvl] + (xps[base_lvl + 1] * floating_lvl));
}

int	main(void)
{
	float	current_lvl;
	float	current_xp;
	float	project_xp;
	int		is_bonus;
	int		result;

	current_xp = 0;
	project_xp = 0;
	is_bonus = 0;
	result = 0;
	printf(HEADER);
	ft_finput("Current level [0.0/10.0] : ", &current_lvl);
	ft_finput("Project xp [0/63000] : ", &project_xp);
	ft_dinput("Bonus [0/1] : ", &is_bonus);
	current_xp = ft_getxp(current_lvl);
	if (is_bonus)
		project_xp += project_xp * 0.25;
	result = (powf(((current_xp + project_xp) / 49980), 0.45) - powf((current_xp / 49980), 0.45)) * 483;
	printf("You will aproximatively earn : %d days of blackhole.\n", result);
	return (0);
}
